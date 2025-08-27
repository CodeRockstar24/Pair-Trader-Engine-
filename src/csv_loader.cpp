#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

namespace CSVLoader {
    std::vector<double> loadClosePrices(const std::string& filename) {
        std::vector<double> prices;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return prices;
        }

        std::string line;
        bool headerSkipped = false;

        while (std::getline(file, line)) {
            if (!headerSkipped) { 
                headerSkipped = true; 
                continue; 
            }

            std::stringstream ss(line);
            std::string date, closeStr;
            if (!std::getline(ss, date, ',')) continue;
            if (!std::getline(ss, closeStr, ',')) continue;

            // convert to double safely
            try {
                double price = std::stod(closeStr);
                prices.push_back(price);
            } catch (...) {
                // skip non-numeric lines
                continue;
            }
        }
        return prices;
    }
}
