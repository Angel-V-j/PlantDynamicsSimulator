#ifndef PLANTDYNAMICSSIMULATOR_FILEREADER_H
#define PLANTDYNAMICSSIMULATOR_FILEREADER_H
#include <string>
#include <vector>


class FileReader {
    private:
        std::string fileName;
    public:
        explicit FileReader(const std::string &fileName);

        std::vector<std::string> readAllLines() const;
};


#endif //PLANTDYNAMICSSIMULATOR_FILEREADER_H