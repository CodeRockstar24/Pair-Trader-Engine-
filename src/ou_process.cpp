#include "ou_process.h"
#include <cmath>
#include <numeric>
#include <stdexcept>

// ===== Compute Hedge Ratio (beta) =====
double compute_hedge_ratio(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.empty()) {
        throw std::invalid_argument("Input vectors must be non-empty and of the same size.");
    }

    double mean_x = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
    double mean_y = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        numerator   += (x[i] - mean_x) * (y[i] - mean_y);
        denominator += (x[i] - mean_x) * (x[i] - mean_x);
    }

    if (denominator == 0) {
        throw std::runtime_error("Variance of x is zero, cannot compute beta.");
    }

    return numerator / denominator;
}

// ===== Compute Spread =====
std::vector<double> compute_spread(const std::vector<double>& x, const std::vector<double>& y, double beta) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Vectors must be same size to compute spread.");
    }

    std::vector<double> spread;
    spread.reserve(x.size());

    for (size_t i = 0; i < x.size(); ++i) {
        spread.push_back(y[i] - beta * x[i]);
    }

    return spread;
}

// ===== Compute Z-Score =====
std::vector<double> compute_zscore(const std::vector<double>& spread, int window) {
    if (spread.size() < static_cast<size_t>(window)) {
        throw std::invalid_argument("Not enough data points for given window.");
    }

    std::vector<double> zscores(spread.size(), 0.0);

    for (size_t i = window; i < spread.size(); ++i) {
        double mean = 0.0;
        for (size_t j = i - window; j < i; ++j) {
            mean += spread[j];
        }
        mean /= window;

        double variance = 0.0;
        for (size_t j = i - window; j < i; ++j) {
            variance += (spread[j] - mean) * (spread[j] - mean);
        }
        variance /= window;

        double stddev = std::sqrt(variance);

        if (stddev > 1e-6) {
            zscores[i] = (spread[i] - mean) / stddev;
        } else {
            zscores[i] = 0.0; // avoid division by zero
        }
    }

    return zscores;
}
