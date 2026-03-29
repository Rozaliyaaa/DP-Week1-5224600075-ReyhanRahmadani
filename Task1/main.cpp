#include "RandomInputGenerator.h"
#include "MultiplyScoringRule.h"
#include "PlusFiveRewardRule.h"
#include "ShopSystem.h"
#include "RunSession.h"

int main() {

    RandomInputGenerator inputGenerator;
    MultiplyScoringRule scoringRule;
    PlusFiveRewardRule rewardRule;
    ShopSystem shopSystem;

    RunSession session(
        inputGenerator,
        scoringRule,
        rewardRule,
        shopSystem
    );

    session.run();

    return 0;
}