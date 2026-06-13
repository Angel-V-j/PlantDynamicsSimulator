#ifndef PLANTDYNAMICSSIMULATOR_CLIMATE_H
#define PLANTDYNAMICSSIMULATOR_CLIMATE_H
#include "Weather.h"
#include <cmath>


class Climate {
    private:
        double temperature;
        double temperatureTarget;
        double humidity;
        double soilHumidity;
        double light;

        float getDayFactor(short hour);
        void updateTemperature();
        void updateTemperatureTarget(short hour, double cloudiness, double wind, double rainIntensity);
        void updateHumidity(double wind, double rainIntensity);
        void updateSoilHumidity(double wind, double rainIntensity);
        void updateLight(double cloudiness, bool isDay);
    public:
        Climate();

        void update(Weather &weather, short hour);

        double getTemperature() const;
        double getTemperatureTarget() const;
        double getHumidity() const;
        double getSoilHumidity() const;
        double getLight() const;

        std::string toString() const;
};


#endif //PLANTDYNAMICSSIMULATOR_CLIMATE_H