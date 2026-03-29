#pragma once
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    IInputGenerator& inputGenerator;
    IScoringRule& scoringRule;
    IRewardRule& rewardRule;
    ShopSystem& shopSystem;

    int money;
    int currentRound;

public:
    RunSession(
        IInputGenerator& inputGenerator,
        IScoringRule& scoringRule,
        IRewardRule& rewardRule,
        ShopSystem& shopSystem
    );

    void run();
};