#include "FileWriter.h"

FileWriter::FileWriter(const std::string fileName) {
    this->fileName = fileName;
}

void FileWriter::writeLine(const std::string& line) const {
    std::ofstream file(fileName, std::ios::app);

    if(!file.is_open())
        throw std::runtime_error("Unable to open file: " + fileName);

    file << line << '\n';
}
