#include "Attacker.hpp"
#pragma once

class Enemy : public Attacker {
public:

    Enemy(int health, int attack) : Attacker(health, attack) {}

    virtual std::string getInfo() = 0;

};