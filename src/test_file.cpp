#include <fstream>
#include <iostream>
int main() {
    std::ifstream f("C:\\Users\\elroy\\OneDrive\\Desktop\\PTE\\data\\QQQ.csv");
    if(f.is_open()) std::cout << "File opened successfully!\n";
    else std::cout << "Failed to open file!\n";
}