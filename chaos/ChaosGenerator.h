//
// Created by Angel on 6/7/2026.
//

#ifndef PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H
#define PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H
#include <cmath>
#include <bits/valarray_after.h>


class ChaosGenerator {
    private:
        double rate; // r
        double startValue; // x
        float growthExponent; // p
        float limitExponent; // q
    public:
        ChaosGenerator(double rate, double startValue) {
            this->rate = rate;
            this->startValue = startValue;
            this->growthExponent = 1;
            this->limitExponent = 1;
        }

        ChaosGenerator(double rate, double startValue, float growthExponent, float limitExponent) {
            this->rate = rate;
            this->startValue = startValue;
            this->growthExponent = growthExponent;
            this->limitExponent = limitExponent;
        }

        double next() const {
            return rate * std::pow(startValue, growthExponent) * (1 - std::pow(startValue, limitExponent)); // return r*x^p(1-x^q)
        }
};


#endif //PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H