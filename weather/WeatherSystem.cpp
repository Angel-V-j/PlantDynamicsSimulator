#include "WeatherSystem.h"

WeatherSystem::WeatherSystem() {
}

WeatherSystem::WeatherSystem(double cloudiness, double wind) {
    this->cloudiness = cloudiness;
    this->cloudinessTarget = cloudiness;
    this->wind = wind;
    this->windTarget = wind;
    this->rainChance = 0;
    this->rainIntensity = 0;
    this->isRaining = false;
}

void WeatherSystem::update(const double & chaos) {
    updateCloudinessTarget(chaos, 20);
    updateWindTarget(chaos, 25);
    updateRainChance(chaos, 15);
    updateRainState(chaos);
    updateRainIntensity(chaos);
}

void WeatherSystem::tick(const double & delta, const double & chaos) {


    for (int i = 0; i < 60; i++) {
        moveToTarget(cloudinessTarget, this->cloudiness, delta);
        moveToTarget(windTarget, this->wind, delta);

    }
}

void WeatherSystem::moveToTarget(const double & target, double & currentValue, const double speed) {
    currentValue += (target - currentValue) * speed;
}

double WeatherSystem::getCloudiness() const {
    return this->cloudiness;
}

double WeatherSystem::getCloudinessTarget() const {
    return this->cloudinessTarget;
}

double WeatherSystem::getWind() const {
    return this->wind;
}

double WeatherSystem::getWindTarget() const {
    return this->windTarget;
}

double WeatherSystem::getRainChance() const {
    return this->rainChance;
}

double WeatherSystem::getRainIntensity() const {
    return rainIntensity;
}

bool WeatherSystem::getIsRaining() const {
    return isRaining;
}

void WeatherSystem::updateCloudinessTarget(const double chaos, const float multiplayer) {
    this ->cloudinessTarget += (chaos - 0.5) * multiplayer;
}
void WeatherSystem::updateWindTarget(const double chaos, const float multiplayer) {
    this->windTarget += (chaos - 0.5) * multiplayer;
}
void WeatherSystem::updateRainChance(const double chaos, const float multiplayer) {
    this->windTarget += (chaos - 0.5) * multiplayer;
}
void WeatherSystem::updateRainState(const double chaos) {
    if (cloudiness < 50 && chaos < 0.5)
        this->isRaining = false;
    else
        this->isRaining = true;
}