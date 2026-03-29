#pragma once
#include <iostream>
#include "PlusFiveRewardRule.h"

class ShopSystem {
public:
    void showOffer(PlusFiveRewardRule& rewardRule, int& money) {

        std::cout << "[SHOP] offered: +5 bonus (cost 20)\n";
        std::cout << "Buy? (y/n): ";

        char choice;
        std::cin >> choice;

        if(choice == 'y' && money >= 20) {
            rewardRule.increaseBonus(5);
            money -= 20;

            std::cout << "[SHOP] Purchased! Bonus now: "
                      << rewardRule.getBonus() << "\n";
        } else {
            std::cout << "[SHOP] skipped\n";
        }
    }
};