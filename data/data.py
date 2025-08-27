import yfinance as yf
import pandas as pd 
tickers = ["QQQ", "XLK"]
start_date = "2023-01-01"
end_date = "2025-08-26" 
# Download data from Yahoo Finance
for ticker in tickers:
    data = yf.download(ticker, start=start_date, end=end_date)
    
    # Keep only Date and Close columns
    data = data[["Close"]]
    data.reset_index(inplace=True)
    
    # Save to CSV
    filename = f"data/{ticker}.csv"
    data.to_csv(filename, index=False)