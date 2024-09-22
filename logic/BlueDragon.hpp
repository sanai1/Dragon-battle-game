#include "Dragon.hpp"
#pragma once

class BlueDragon : public Dragon {
public:

    BlueDragon(int health, int attack) : Dragon("Blue", health, attack) {}

    std::string question() override {
        return getQuestion("-");
    }

};