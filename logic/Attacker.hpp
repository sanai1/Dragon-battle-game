#include "iostream"
#pragma once

class Attacker {
public:
    Attacker(int health, int attack) :
            _health(health),
            _attack(attack){};

    virtual void attack(Attacker& target) {
        if (this->is_alive() && target.is_alive()) {
            target._health -= this->_attack;
            if (target._health < 0)
                target._health = 0;
        } else {
        }
    }

    virtual bool is_alive() {
        if (this->_health > 0)
            return true;
        else
            return false;
    }

    virtual std::string getInfo() = 0;

    int getHealth() const {
        return _health;
    }

    int getAttack() const {
        return _attack;
    }

    void setHealth(int health) {
        _health = health;
    }

private:
    int _health;
    int _attack;
};
