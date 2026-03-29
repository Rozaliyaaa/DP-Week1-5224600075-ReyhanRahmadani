#pragma once
#include "IScoringRule.h"

class MultiplyScoringRule : public IScoringRule {
public:
    int computeBaseScore(const TurnInput& input) override {
        return input.value * 10;
    }
};