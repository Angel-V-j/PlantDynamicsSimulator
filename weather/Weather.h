#ifndef PLANTDYNAMICSSIMULATOR_WEATHER_H
#define PLANTDYNAMICSSIMULATOR_WEATHER_H
#include <string>
#include "../chaos/ChaosGenerator.h"

class Weather {
    private:
        double cloudiness;
        double cloudinessTarget;

        double wind;
        double windTarget;

        double rainChance;
        double rainIntensity;
        bool isRaining;

        void tick(double chaos);
        void moveToTarget(const double &target, double &currentValue, double chaos);
        // void updateCloudinessTarget(double chaos, float multiplier);
        // void updateWindTarget(double chaos, float multiplier);
        // void updateRainChance(double chaos, float multiplier);
        // void updateRainIntensity(double chaos, float multiplier);
        void updateRainState(double chaos);
        void updateTarget(double& target, double chaos, double multiplier);

    public:
        Weather(double cloudiness, double wind);

        void update(double chaos);

        double getCloudiness() const;
        double getCloudinessTarget() const;
        double getWind() const;
        double getWindTarget() const;
        double getRainChance() const;
        double getRainIntensity() const;
        bool getIsRaining() const;

        std::string toString() const;

        ~Weather() = default;
};


#endif //PLANTDYNAMICSSIMULATOR_WEATHER_H