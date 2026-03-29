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

        // 1. Generate input
        TurnInput input = inputGenerator.generate();
        std::cout << "[PLAY] input generated: " << input.value << "\n";

        // 2. Compute base score
        int baseScore = scoringRule.computeBaseScore(input);
        std::cout << "[SCORE] base score: " << baseScore << "\n";

        // 3 & 4. Compute reward + update money
        int reward = rewardRule.computeReward(baseScore);
        money += reward;

        std::cout << "[REWARD] gain: " << reward
                  << " | money: " << money << "\n";

        // 5. Shop phase (print only)
        shopSystem.showOffer();

        // 6. Advance round
        currentRound++;

        if(currentRound <= 3)
            std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}