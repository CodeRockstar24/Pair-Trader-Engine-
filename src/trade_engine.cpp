#include "trade_engine.h"
#include "ou_process.h"
#include <iostream>
#include <cmath>

TradeResult run_backtest(const std::vector<double>& x,
                         const std::vector<double>& y,
                         int lookback,
                         double entry_threshold,
                         double exit_threshold) {
    TradeResult result;
    result.final_pnl = 0.0;
    result.num_trades = 0;

    // Step 1: Compute hedge ratio
    double beta = compute_hedge_ratio(x, y);

    // Step 2: Compute spread
    std::vector<double> spread = compute_spread(x, y, beta);

    // Step 3: Compute z-scores
    std::vector<double> zscores = compute_zscore(spread, lookback);

    // State: +1 = long spread, -1 = short spread, 0 = flat
    int position = 0;
    double pnl = 0.0;
    result.equity_curve.reserve(spread.size());

    for (size_t i = lookback; i < spread.size(); ++i) {
        double z = zscores[i];

        // Entry rules
        if (position == 0) {
            if (z > entry_threshold) {
                // Short spread: short y, long x
                position = -1;
                result.num_trades++;
            } else if (z < -entry_threshold) {
                // Long spread: long y, short x
                position = 1;
                result.num_trades++;
            }
        }
        // Exit rules
        else if ((position == 1 && z > -exit_threshold) ||
                 (position == -1 && z < exit_threshold)) {
            position = 0;
        }

        // Daily PnL approximation: spread change * position
        if (i > 0) {
            pnl += position * (spread[i] - spread[i - 1]);
        }

        result.equity_curve.push_back(pnl);
    }

    result.final_pnl = pnl;
    return result;
}
