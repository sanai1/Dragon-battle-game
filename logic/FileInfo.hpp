#include <iostream>
#include <fstream>
#include "../interface/Level.hpp"
#include "Dragon.hpp"
#include "Hero.hpp"

#pragma once

void writeFile(Level& level1, Level& level2, Level& level3, Level& level4, Dragon* masDragon[], int masCntDragon[], const Hero& hero, int cntTask, int cntRight, int isGame) {
    std::ofstream out;
    out.open("fileInfo.txt");

    if (!out.is_open()) {
        cout << "fail write fileInfo.txt" << endl;
        return;
    }

    out << level1.isAlive() << endl;
    out << level2.isAlive() << endl;
    out << level3.isAlive() << endl;
    out << level4.isAlive() << endl;

    for (int i = 0; i < 4; i++)
        out << masDragon[i]->getHealth() << endl;

    for (int i = 0; i < 4; i++)
        out << masCntDragon[i] << endl;

    out << hero.getHealth() << endl;

    out << cntTask << endl;

    out << cntRight << endl;

    out << isGame;
}

void writeFileReset() {
    std::ofstream out;
    out.open("fileInfo.txt");

    if (!out.is_open()) {
        cout << "fail open fileInfo.txt" << endl;
        return;
    }

    string str;
    str = "1\n0\n0\n0\n"
          "200\n200\n200\n200\n"
          "0\n0\n0\n0\n"
          "100\n"
          "0\n0\n"
          "0";
    out << str;
}

void readFile(Level& level1, Level& level2, Level& level3, Level& level4, Dragon* masDragon[], int *masCntDragon, Hero& hero, int& cntTask, int& cntRight, int& isGame) {
    string str;
    std::ifstream in("fileInfo.txt");

    if (in) {
        getline(in, str);
        level1.setIsAlive(stoi(str));

        getline(in, str);
        level2.setIsAlive(stoi(str));

        getline(in, str);
        level3.setIsAlive(stoi(str));

        getline(in, str);
        level4.setIsAlive(stoi(str));

        for (int i = 0; i < 4; i++) {
            getline(in, str);
            masDragon[i]->setHealth(stoi(str));
        }

        for (int i = 0; i < 4; i++) {
            getline(in, str);
            masCntDragon[i] = stoi(str);
        }

        getline(in, str);
        hero.setHealth(stoi(str));

        getline(in, str);
        cntTask = stoi(str);

        getline(in, str);
        cntRight = stoi(str);

        getline(in, str);
        isGame = stoi(str);
    } else {
        cout << "fail read fileInfo.txt" << endl;
    }

    in.close();
}