PairTraderEngine – Statistical Arbitrage Backtesting in C++

Overview

PairTraderEngine is a modular C++ application implementing a statistical arbitrage (pairs trading) strategy for financial assets. Designed for performance and extensibility, it allows users to load historical market data, compute hedge ratios, analyze spreads, generate Z-scores, and backtest trading strategies on ETFs like QQQ and XLK.

This project demonstrates quantitative finance knowledge, C++ software engineering skills, and data-driven decision making, making it a strong portfolio addition or SOP showcase.

Features
1. CSV Data Loader

Load historical price data from CSV files.

Supports flexible file paths (Windows/macOS/Linux).

Extracts only the closing prices needed for backtesting.

Modularized in csv_loader.h/cpp for easy reuse in other projects.

2. Hedge Ratio Calculation

Computes the optimal hedge ratio (beta) between two assets using linear regression.

Encapsulated in ou_process.h/cpp.

Supports real-time adjustment for new datasets.

3. Spread and Z-Score Computation

Calculates the spread between two correlated assets using the hedge ratio.

Computes Z-scores to identify trading signals (entry/exit points).

Enables statistical arbitrage based on mean-reversion principles.

4. Backtesting Engine

Fully modular trade_engine.h/cpp.

Inputs: asset prices, hedge ratio, lookback period, entry/exit thresholds.

Outputs: cumulative P&L, number of trades, equity curve, and detailed trade results.

Supports parameter customization for experimentation and strategy optimization.

5. future plan - GUI with Qt features

Minimal Qt GUI implemented (if included).

Allows selection of QQQ & XLK CSV files via file dialogs.

“Run Backtest” button executes the strategy.

Results displayed in a text box.

Optional equity curve plotting with Qt Charts or QCustomPlot.
