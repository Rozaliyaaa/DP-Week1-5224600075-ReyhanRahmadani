#pragma once
#include "IInputGenerator.h"
#include <random>

class RandomInputGenerator : public IInputGenerator {
private:
    std::mt19937 engine;
    std::uniform_int_distribution<int> distribution;

public:
    RandomInputGenerator();
    TurnInput generate() override;
};