#include "TimeSystem.h"

TimeSystem::TimeSystem()  {
    weather = new WeatherSystem(0.2, 0.05);
    days = 0;
    hour = 0;
}

int TimeSystem::getDay() const {
    return this->days;
}

short TimeSystem::getHour() const {
    return this->hour;
}

void TimeSystem::update() {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++)
            weather->update();
        hour++;
    }

    hour = 0;
    days++;
}