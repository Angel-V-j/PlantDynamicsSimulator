#ifndef PLANTDYNAMICSSIMULATOR_TIME_H
#define PLANTDYNAMICSSIMULATOR_TIME_H
#include "Weather.h"
#include "Climate.h"


class Time {
    private:
        int days;
        short hour;

    public:
        Time();

        int getDay() const;
        short getHour() const;

        std::string update(Weather &weather, Climate &climate, ChaosGenerator &chaosGen);
        bool isDay() const;
};

#endif //PLANTDYNAMICSSIMULATOR_TIME_H