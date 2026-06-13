#include "Climate.h"

#include <algorithm>

Climate::Climate() {
    temperature = 18;
    humidity = 40;
    soilHumidity = 60;
    light = 0;
}

void Climate::update(Weather & weather, short hour) {
    updateTemperatureTarget(hour,weather.getCloudiness(),
        weather.getWind(),weather.getRainIntensity());

    for (int i = 0; i < 60; i++) {
        updateTemperature();
    }
}

void Climate::updateTemperature() {
    temperature += std::abs(temperatureTarget-temperature)/60.0;
}

float Climate::getDayFactor(const short hour) {
    if (hour < 6)
        return 0.0;

    if (hour <= 17)
        return (hour - 6) / 11.00f;

    return (24 - hour) / 7.00f;
    // if (hour >= 6 && hour < 9)
    //     dayFactor += 0.05;
    // else if (hour >= 9 && hour <= 16)
    //     dayFactor += 0.1;
    // else if (hour > 17 && hour <= 22)
    //     dayFactor -= 0.05;
    // else if (hour > 23 || hour < 6)
    //     dayFactor -= 0.1;
}

void Climate::updateTemperatureTarget(short hour, double cloudiness, double wind, double rainIntensity) {
    temperatureTarget = 18 + getDayFactor(hour) * 12
    - cloudiness * 0.05 - wind * 0.03 - rainIntensity * 0.08;
}

void Climate::updateHumidity(double wind, double rainIntensity) {
    if (rainIntensity > 0.0)
        humidity += rainIntensity * 0.05;
    else
        humidity -= - temperature * 0.0013 - wind * 0.0008 - light * 0.0004;

    humidity = std::clamp(humidity, 0.0, 100.0);
}

void Climate::updateSoilHumidity(double wind, double rainIntensity) {
    if (rainIntensity > 0.0)
        soilHumidity += rainIntensity * 0.03;
    else
        soilHumidity -= - temperature * 0.0003 - wind * 0.0001 - light * 0.0002;

    soilHumidity = std::clamp(soilHumidity, 0.0, 100.0);
}

void Climate::updateLight(const double cloudiness, const bool isDay) {
    if (isDay)
        this->light = 100-cloudiness;
    else
        this->light = 0;
}

double Climate::getTemperature() const {
    return temperature;
}

double Climate::getHumidity() const {
    return humidity;
}

double Climate::getSoilHumidity() const {
    return  soilHumidity;
}

double Climate::getLight() const {
    return light;
}