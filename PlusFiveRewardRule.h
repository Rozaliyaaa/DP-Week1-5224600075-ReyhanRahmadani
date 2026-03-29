#pragma once
#include "IRewardRule.h"

class PlusFiveRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore) override {
        return baseScore + 5;
    }
};