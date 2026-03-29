#pragma once
#include "IRewardRule.h"

class PlusFiveRewardRule : public IRewardRule {
private:
    int bonus;

public:
    PlusFiveRewardRule() : bonus(5) {}

    int computeReward(int baseScore) override {
        return baseScore + bonus;
    }

    void increaseBonus(int amount) {
        bonus += amount;
    }

    int getBonus() const {
        return bonus;
    }
};