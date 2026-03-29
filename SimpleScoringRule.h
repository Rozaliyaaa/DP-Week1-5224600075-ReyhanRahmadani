#pragma once
#include "IScoringRule.h"

class SimpleScoringRule : public IScoringRule {
public:
    int computeBaseScore(const TurnInput& input) override {
        return input.value;
    }
};