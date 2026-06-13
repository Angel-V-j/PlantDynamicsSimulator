#include "FileReader.h"

#include <fstream>
#include <stdexcept>

FileReader::FileReader(const std::string &fileName) {
    this->fileName = fileName;
}

std::vector<std::string> FileReader::readAllLines() const{
    std::ifstream file("logs/" + fileName + ".csv");

    if(!file.is_open())
        throw std::runtime_error("Unable to open file: " + fileName);

    std::vector<std::string> lines;
    std::string line;

    while(std::getline(file, line))
        lines.push_back(line);

    return lines;
}