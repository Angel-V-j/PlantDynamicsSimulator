#ifndef PLANTDYNAMICSSIMULATOR_SIMULATOR_H
#define PLANTDYNAMICSSIMULATOR_SIMULATOR_H
#include "../service/FileWriter.h"
#include "../service/FileReader.h"
#include "../chaos/ChaosGenerator.h"
#include "../weather/Climate.h"
#include "../weather/Time.h"
#include "../weather/Weather.h"


class Simulator {
    private:
        ChaosGenerator chaos;
        Climate climate;
        Time time;
        Weather weather;

        FileWriter writer;
        FileReader reader;
    public:
        Simulator();
        void run(int days);
};


#endif //PLANTDYNAMICSSIMULATOR_SIMULATOR_H