#pragma once
#include <iostream>

class ShopSystem {
public:
    void showOffer() {
        std::cout << "[SHOP] offered: Bonus (+5)\n";
        std::cout << "[SHOP] skipped\n";
    }
};