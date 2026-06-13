#include "Time.h"

Time::Time() {
    days = 0;
    hour = 0;
}

int Time::getDay() const {
    return this->days;
}

short Time::getHour() const {
    return this->hour;
}

bool Time::isDay() const {
    if (hour > 6 && hour < 19)
        return true;

    return false;
}

void Time::update(Weather & weather) {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++)
            weather.update();
        hour++;
    }

    hour = 0;
    days++;
}