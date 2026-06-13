#include "Weather.h"

#include <algorithm>

Weather::Weather(double cloudiness, double wind) {
    this->cloudiness = cloudiness;
    this->cloudinessTarget = cloudiness;
    this->wind = wind;
    this->windTarget = wind;
    this->rainChance = 0;
    this->rainIntensity = 0;
    this->isRaining = false;
}

void Weather::update(const ChaosGenerator & chaosGenerator) {
    const double chaos = chaosGenerator.next();
    updateTarget(cloudinessTarget,chaos, 20);
    updateTarget(wind,chaos, 25);
    updateTarget(rainChance,chaos, 15);
    updateRainState(chaos);
    if (isRaining)
        updateTarget(rainIntensity,chaos, 10);

    // updateCloudinessTarget(chaos, 20);
    // updateWindTarget(chaos, 25);
    // updateRainChance(chaos, 15);
    // updateRainState(chaos);
    // updateRainIntensity(chaos, 10);
    tick(chaos);
}

void Weather::tick(const double chaos) {
    for (int i = 0; i < 60; i++) {
        moveToTarget(cloudinessTarget, this->cloudiness, chaos);
        moveToTarget(windTarget, this->wind, chaos);
    }
}

void Weather::moveToTarget(const double & target, double & currentValue, const double speed) {
    currentValue += (target - currentValue) * speed;
}

void Weather::updateRainState(const double chaos) {
    if (cloudiness < 50 && chaos < 0.5)
        this->isRaining = false;
    else
        this->isRaining = true;
}

void Weather::updateTarget(double& target, double chaos, double multiplier) {
    target += (chaos - 0.5) * multiplier;
    target = std::clamp(target, 0.0, 100.0);
}

double Weather::getCloudiness() const {
    return this->cloudiness;
}

double Weather::getCloudinessTarget() const {
    return this->cloudinessTarget;
}

double Weather::getWind() const {
    return this->wind;
}

double Weather::getWindTarget() const {
    return this->windTarget;
}

double Weather::getRainChance() const {
    return this->rainChance;
}

double Weather::getRainIntensity() const {
    return rainIntensity;
}

bool Weather::getIsRaining() const {
    return isRaining;
}

// void Weather::updateCloudinessTarget(const double chaos, const float multiplayer) {
//     this ->cloudinessTarget += (chaos - 0.5) * multiplayer;
//     this->cloudinessTarget = putIntoBoundaries(cloudinessTarget);
// }
//
// void Weather::updateWindTarget(const double chaos, const float multiplier) {
//     this->windTarget += (chaos - 0.5) * multiplier;
// }
//
// void Weather::updateRainChance(const double chaos, const float multiplier) {
//     this->windTarget += (chaos - 0.5) * multiplier;
// }
//
// void Weather::updateRainIntensity(const double chaos, const float multiplier) {
//     if (this->isRaining)
//         this->rainIntensity += (chaos - 0.5) * multiplier;
// }
//
