#include "Time.h"

#include "Climate.h"

Time::Time() {
    days = 0;
    hour = 0;
}

void Time::update(Weather & weather, Climate & climate, const ChaosGenerator & chaos) {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            weather.update(chaos);
            climate.update(weather, hour);
        }

        hour++;
    }

    hour = 0;
    days++;
}

bool Time::isDay() const {
    if (hour >= 6 && hour <= 20)
        return true;

    return false;
}

int Time::getDay() const {
    return this->days;
}

short Time::getHour() const {
    return this->hour;
}

