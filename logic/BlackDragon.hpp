#include "Dragon.hpp"
#pragma once

class BlackDragon : public Dragon {
public:

    BlackDragon(int health, int attack) : Dragon("Black", health, attack) {}

    std::string question() override {
        return getQuestion("*");
    }

};