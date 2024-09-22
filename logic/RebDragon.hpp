#include "Dragon.hpp"
#pragma once

class RenDragon : public Dragon {
public:

    RenDragon(int health, int attack) : Dragon("Red", health, attack) {}

    std::string question() override {
        return getQuestion("*");
    }

};