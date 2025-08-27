#pragma once
#include <vector>

// Estimate hedge ratio (beta) using simple OLS regression
double compute_hedge_ratio(const std::vector<double>& x, const std::vector<double>& y);

// Compute spread = y - beta * x
std::vector<double> compute_spread(const std::vector<double>& x, const std::vector<double>& y, double beta);

// Compute Z-score of spread
std::vector<double> compute_zscore(const std::vector<double>& spread, int window = 30);
