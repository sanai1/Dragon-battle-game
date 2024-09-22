#include "Enemy.hpp"
#include "iostream"
#pragma once

using namespace std;

class Dragon : public Enemy {
public:

    Dragon(string color, int health, int attack) :
            _color(color),
            _answer(0),
            _a(0),
            _b(0),
            Enemy(health, attack) {}

    bool check_answer(string answer) {
        try {
            if (stoi(answer) == _answer)
                return true;
            else
                return false;
        } catch (exception exception) {
            return false;
        }
    }

    string getQuestion(string str) {
        srand(time(0));
        int a = rand() % 100;
        int b = rand() % 100;
        _a = a;
        _b = b;
        if (str == "+")
            _answer = _a + _b;
        else if (str == "-")
            _answer = _a - _b;
        else if (str == "*")
            _answer = _a * _b;
        return to_string(_a) + " " + str + " " + to_string(_b) + " = ?";
    }

    std::string getInfo() override {
        return "Dragon\n"
               "HP: " + to_string(getHealth()) + "\n"
                                                 "Damage: " + to_string(getAttack());
    }

    virtual string question() = 0;

private:

    string _color;
    int _answer;
    int _a;
    int _b;

};