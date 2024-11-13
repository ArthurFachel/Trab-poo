#include <iostream>
#include "FileHandler.hpp"

int main() {
    string filename = "2020.csv"; 
    vector<DataItem> data = FileHandler::readDataFromFile(filename);

    FileHandler::printData(data);

    return 0;
}
