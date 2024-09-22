#include "Dragon.hpp"
#pragma once

class GreenDragon : public Dragon {
public:

    GreenDragon(int health, int attack) : Dragon("GREEN", health, attack) {}

    std::string question() override {
        return getQuestion("+");
    }

};