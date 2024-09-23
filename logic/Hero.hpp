#include "Attacker.hpp"
#include "iostream"
#pragma once

class Hero : public Attacker {
public:

    Hero(int experience, std::string name, int health, int attack) :
            _experience(experience),
            _name(name),
            Attacker(health, attack) {};

    std::string getInfo() override {
        return "Hero\n"
               "HP: " + to_string(getHealth()) + "\n"
                                                 "Damage: " + to_string(getAttack());
    }

private:

    int _experience;
    std::string _name;

};