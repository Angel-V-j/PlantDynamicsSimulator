#ifndef PLANTDYNAMICSSIMULATOR_TIMESYSTEM_H
#define PLANTDYNAMICSSIMULATOR_TIMESYSTEM_H
#include "WeatherSystem.h"


class TimeSystem {
    private:
        WeatherSystem *weather;
        int days;
        short hour;
    public:
        TimeSystem();

        int getDay() const;
        short getHour() const;

        void update();
};

#endif //PLANTDYNAMICSSIMULATOR_TIMESYSTEM_H