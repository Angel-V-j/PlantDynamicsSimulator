#ifndef PLANTDYNAMICSSIMULATOR_WEATHERSYSTEM_H
#define PLANTDYNAMICSSIMULATOR_WEATHERSYSTEM_H

class WeatherSystem {
    private:
        double cloudiness;
        double cloudinessTarget;

        double wind;
        double windTarget;

        double rainChance;
        double rainIntensity;
        bool isRaining;

        void tick(const double & delta);
        void moveToTarget(const double & target, double & currentValue, double speed);
    public:
        WeatherSystem();
        WeatherSystem(double cloudiness, double wind);

        void update();

        double getCloudiness() const;
        double getCloudinessTarget() const;
        double getWind() const;
        double getWindTarget() const;
        double getRainChance() const;
        double getRainIntensity() const;
        bool getIsRaining() const;

        void updateCloudinessTarget(double chaos, float multiplayer);
        void updateWindTarget(double chaos, float multiplayer);
        void updateRainChance(double chaos, float multiplayer);
        void updateRainIntensity(double chaos, float multiplayer);
        void updateRainState(double chaos);

        ~WeatherSystem() = default;
};


#endif //PLANTDYNAMICSSIMULATOR_WEATHERSYSTEM_H