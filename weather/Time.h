#ifndef PLANTDYNAMICSSIMULATOR_TIME_H
#define PLANTDYNAMICSSIMULATOR_TIME_H
#include "Weather.h"


class Time {
    private:
        int days;
        short hour;
    public:
        Time();

        int getDay() const;
        short getHour() const;

        bool isDay() const;
        void update(Weather & weather);
};

#endif //PLANTDYNAMICSSIMULATOR_TIME_H