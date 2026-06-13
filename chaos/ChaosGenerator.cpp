#include "ChaosGenerator.h"
#include <cmath>

ChaosGenerator::ChaosGenerator(const double rate, const double startValue) {
    this->rate = rate;
    this->startValue = startValue;
    this->growthExponent = 1;
    this->limitExponent = 1;
}

ChaosGenerator::ChaosGenerator(const double rate, const double startValue,
                                const float growthExponent, const float limitExponent) {
    this->rate = rate;
    this->startValue = startValue;
    this->growthExponent = growthExponent;
    this->limitExponent = limitExponent;
}

double ChaosGenerator::getRate() const {
    return this->rate;
}

double ChaosGenerator::getStartValue() const {
    return this->startValue;
}

float ChaosGenerator::getGrowthExponent() const {
    return this->growthExponent;
}

float ChaosGenerator::getLimitExponent() const {
    return this->limitExponent;
}

double ChaosGenerator::next() {
    this->startValue = rate * std::pow(startValue, growthExponent)
    * (1 - std::pow(startValue, limitExponent)); // return r*x^p(1-x^q)
    return startValue;
}
