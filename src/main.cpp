#include <iostream>
#include <vector>
#include <string>
#include "csv_loader.h"
#include "ou_process.h"
#include "trade_engine.h"


int main() {
    std::cout << "=== PairTraderEngine ===\n";

    // CSV paths (relative to src folder)
    std::string qqq_file = "C:\\PTE\\PTE\\data\\QQQ.csv";
    std::string xlk_file = "C:\\PTE\\PTE\\data\\XLK.csv";

    // Load price data
    std::vector<double> qqq_prices = CSVLoader::loadClosePrices(qqq_file);
    std::vector<double> xlk_prices = CSVLoader::loadClosePrices(xlk_file);

    if (qqq_prices.empty()) {
        std::cerr << "Failed to load QQQ price data from " << qqq_file << std::endl;
        return 1;
    }
    if (xlk_prices.empty()) {
        std::cerr << "Failed to load XLK price data from " << xlk_file << std::endl;
        return 1;
    }

    std::cout << "Loaded " << qqq_prices.size() << " QQQ prices and "
              << xlk_prices.size() << " XLK prices.\n";

    // Compute hedge ratio (beta)
    double beta = compute_hedge_ratio(qqq_prices, xlk_prices);
    std::cout << "Computed hedge ratio (beta): " << beta << "\n";

    // Compute spread
    std::vector<double> spread = compute_spread(qqq_prices, xlk_prices, beta);

    // Compute Z-score
    std::vector<double> zscore = compute_zscore(spread);

    // Run backtest
    int lookback = 30;
    double entry_threshold = 2.0;
    double exit_threshold = 0.5;

    TradeResult result = run_backtest(qqq_prices, xlk_prices, lookback, entry_threshold, exit_threshold);

    // Display results
    std::cout << "Cumulative P&L: " << result.final_pnl << "\n";
    std::cout << "Number of trades: " << result.num_trades << "\n";

    // Access equity curve if needed
    std::vector<double> pnl_curve = result.equity_curve;

    std::cout << "=== Backtest Completed ===\n";
    return 0;
}
