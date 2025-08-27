#pragma once
#include <string>
#include <vector>

struct TradeResult {
    double final_pnl;
    int num_trades;
    std::vector<double> equity_curve;
};

// Backtest pairs trading strategy
TradeResult run_backtest(const std::vector<double>& x,
                         const std::vector<double>& y,
                         int lookback = 30,
                         double entry_threshold = 2.0,
                         double exit_threshold = 0.5);
 

                         