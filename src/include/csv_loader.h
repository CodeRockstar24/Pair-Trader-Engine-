#ifndef CSV_LOADER_H
#define CSV_LOADER_H

#include <string>
#include <vector>

class CSVLoader {
public:
    // Loads "Close" column from CSV into a vector of doubles
    static std::vector<double> loadClosePrices(const std::string& filename);
};

#endif 

