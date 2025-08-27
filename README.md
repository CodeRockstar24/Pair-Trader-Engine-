💹 PairTraderEngine – Statistical Arbitrage Backtesting in C++
🔹 Overview

PairTraderEngine is a modular C++ application implementing a statistical arbitrage (pairs trading) strategy for financial assets.
It allows users to:

Load historical market data

Compute hedge ratios

Analyze spreads and generate Z-scores

Backtest trading strategies on ETFs like QQQ and XLK

🛠 Features
📄 CSV Data Loader

Load historical price data from CSV files

Supports flexible file paths (Windows/macOS/Linux)

Extracts only the closing prices needed for backtesting

Modularized in csv_loader.h/cpp for easy reuse

📊 Hedge Ratio Calculation

Computes the optimal hedge ratio (beta) between two assets using linear regression

Encapsulated in ou_process.h/cpp

Supports real-time adjustment for new datasets

🔗 Spread and Z-Score Computation

Calculates the spread between two correlated assets using the hedge ratio

Computes Z-scores to identify trading signals (entry/exit points)

Enables statistical arbitrage based on mean-reversion principles

💹 Backtesting Engine

Fully modular trade_engine.h/cpp

Inputs: asset prices, hedge ratio, lookback period, entry/exit thresholds

Outputs: cumulative P&L, number of trades, equity curve, and detailed trade results

Supports parameter customization for experimentation and strategy optimization

🖥 future plan- GUI with Qt (features)

Minimal Qt GUI implemented (if included)

Allows selection of QQQ & XLK CSV files via file dialogs

“Run Backtest” button executes the strategy

Results displayed in a text box

Optional equity curve plotting with Qt Charts or QCustomPlot
