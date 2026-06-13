#include "Time.h"

#include <sstream>

#include "Climate.h"

Time::Time() {
    days = 0;
    hour = 0;
}

std::string Time::update(Weather & weather, Climate & climate, ChaosGenerator & chaosGen) {
    std::ostringstream oss;
    for (int i = 0; i < 24; i++) {
        double chaos = chaosGen.next();
        for (int j = 0; j < 60; j++) {
            weather.update(chaos);
            climate.update(weather, hour);
        }

        oss << getDay() << ", " << getHour() << ", " << chaos << ", " << std::endl;
        oss << weather.toString() << ", " << std::endl;
        oss << climate.toString() << ", " << std::endl;
        hour++;
    }

    hour = 0;
    days++;
    return oss.str();
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
