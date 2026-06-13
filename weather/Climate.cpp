#include "Climate.h"

Climate::Climate() {

}

void Climate::update() {

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

void Climate::setTemperature(double wind, double rainIntensity) {
    double temperature = 25 - wind - rainIntensity + light;
    this->temperature =
}

void Climate::setHumidity(double humidity) {

}

void Climate::setSoilHumidity(double humidity) {

}

void Climate::setLight(double cloudiness, bool isDay) {
    if (isDay)
        this->light = 1-cloudiness;
    else
        this->light = 0;
}