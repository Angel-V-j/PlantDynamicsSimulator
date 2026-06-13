#ifndef PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H
#define PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H

class ChaosGenerator {
    private:
        double rate; // r
        double startValue; // x
        float growthExponent; // p
        float limitExponent; // q
    public:
        ChaosGenerator(double rate, double startValue);
        ChaosGenerator(double rate, double startValue, float growthExponent, float limitExponent);
        double getRate() const;
        double getStartValue() const;
        float getGrowthExponent() const;
        float getLimitExponent() const;
        double next();

        ~ChaosGenerator() = default;
};


#endif //PLANTDYNAMICSSIMULATOR_CHAOSGENERATOR_H