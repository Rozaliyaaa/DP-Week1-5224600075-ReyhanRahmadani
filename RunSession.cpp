#include "RunSession.h"
#include <iostream>

RunSession::RunSession(
    IInputGenerator& inputGenerator,
    IScoringRule& scoringRule,
    IRewardRule& rewardRule,
    ShopSystem& shopSystem
)
: inputGenerator(inputGenerator),
  scoringRule(scoringRule),
  rewardRule(rewardRule),
  shopSystem(shopSystem),
  money(0),
  currentRound(1)
{}

void RunSession::run() {

    std::cout << "=== RUN START ===\n";

    while(currentRound <= 3) {

        std::cout << "Round " << currentRound << "\n";

        TurnInput input = inputGenerator.generate();
        std::cout << "[PLAY] input generated: " << input.value << "\n";

        int baseScore = scoringRule.computeBaseScore(input);
        std::cout << "[SCORE] base score: " << baseScore << "\n";

        int reward = rewardRule.computeReward(baseScore);
        std::cout << "[REWARD] gain: " << reward << "\n";

        money += reward;
        std::cout << "[MONEY] money: " << money << "\n";

        shopSystem.showOffer(
                dynamic_cast<PlusFiveRewardRule&>(rewardRule),
                money
        );
        currentRound++;
        std::cout << "[ROUND] advanced\n";

        if(currentRound <= 3)
            std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}