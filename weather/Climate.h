#ifndef PLANTDYNAMICSSIMULATOR_CLIMATE_H
#define PLANTDYNAMICSSIMULATOR_CLIMATE_H


class Climate {
    private:
        double temperature;
        double temperatureTarget;
        double humidity;
        double soilHumidity;
        double light;
    public:
        Climate();

        void update();

        double getTemperature() const;
        double getTemperatureTarget() const;
        double getHumidity() const;
        double getSoilHumidity() const;
        double getLight() const;
        void setTemperature(double wind, double rainIntensity);
        void setHumidity(double humidity);
        void setSoilHumidity(double humidity);
        void setLight(double light, bool isDay);
};


#endif //PLANTDYNAMICSSIMULATOR_CLIMATE_H