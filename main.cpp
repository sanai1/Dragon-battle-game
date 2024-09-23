#include <iostream>
#include <SFML/Graphics.hpp>
#include "interface/Level.hpp"
#include "interface/Functions.hpp"
#include "logic/Hero.hpp"
#include "logic/Dragon.hpp"
#include "logic/GreenDragon.hpp"
#include "logic/BlueDragon.hpp"
#include "logic/RebDragon.hpp"
#include "logic/BlackDragon.hpp"
#include "logic/FileInfo.hpp"

using namespace std;

vector<int> status;

sf::Texture textureStart;
sf::Sprite spriteStart;

sf::Texture textureCloseButton;
sf::Sprite spriteCloseButton;

sf::RectangleShape boxReset, boxNotSave, boxSave;
sf::Text textReset, textNotSave, textSave;

sf::Texture textureDragon;
sf::Sprite spriteDragon;
sf::Text textQuestion, textAnswer, textInfo, textBoxAnswer;
sf::RectangleShape boxInput, boxAnswer;

sf::RectangleShape boxDragonInfo, boxHeroInfo;
sf::Text textDragonInfo, textHeroInfo;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1100), "Game", sf::Style::None);
    status.emplace_back(0);

    sf::Font font;
    if (!font.loadFromFile("/home/aleksandr/CLionProjects/fonts/arial.ttf"))
        cout << "fail arial.ttf" << endl;

    sf::RectangleShape boxName;
    boxName.setOutlineThickness(5);
    boxName.setOutlineColor(sf::Color::Black);
    boxName.setPosition(5, 5);
    boxName.setSize(sf::Vector2f(990, 90));
    boxName.setFillColor(sf::Color::Cyan);

    sf::RectangleShape boxScreen;
    boxScreen.setOutlineThickness(5);
    boxScreen.setOutlineColor(sf::Color::Black);
    boxScreen.setPosition(5, 100);
    boxScreen.setSize(sf::Vector2f(990, 995));
    boxScreen.setFillColor(sf::Color(0, 0, 255, 100));

    sf::Text textName;
    textName.setFont(font);
    textName.setString("Game");
    textName.setCharacterSize(75);
    textName.setPosition(400, 5);
    textName.setFillColor(sf::Color::Black);

    string fileTop = "/home/aleksandr/CLionProjects/image/number-";
    Level level1(fileTop, 1, 75, 200);
    Level level2(fileTop, 2, 550, 200);
    Level level3(fileTop, 3, 75, 650);
    Level level4(fileTop, 4, 550, 650);

    Dragon* masDragon[] = {
            new GreenDragon(200, 20),
            new BlueDragon(200, 25),
            new RenDragon(200, 35),
            new BlackDragon(200, 50)};
    int masCntDragon[] = {0, 0, 0, 0};
    string answer, question, info, dragonInfo, heroInfo;
    int cntTask = 0, cntRight = 0;
    Hero hero(0, "hero", 100, 20);
    readFile(level1, level2, level3, level4, masDragon, masCntDragon, hero, cntTask, cntRight);
    info = to_string(cntTask) + "/10 task\n" + to_string(cntRight) + "/" + to_string(cntTask) + " right";

    int versionSave = 0;
    while (window.isOpen() && versionSave == 0) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
                if (level1.getSprite().getGlobalBounds().contains(mousePoz.x, mousePoz.y) && level1.isAlive()) {
                    if (status.back() == 5) {
                        status.emplace_back(1);
                        question = masDragon[0]->question();
                    }
                } else if (level2.getSprite().getGlobalBounds().contains(mousePoz.x, mousePoz.y) && level2.isAlive()) {
                    if (status.back() == 5) {
                        status.emplace_back(2);
                        question = masDragon[1]->question();
                    }
                } else if (level3.getSprite().getGlobalBounds().contains(mousePoz.x, mousePoz.y) && level3.isAlive()) {
                    if (status.back() == 5) {
                        status.emplace_back(3);
                        question = masDragon[2]->question();
                    }
                } else if (level4.getSprite().getGlobalBounds().contains(mousePoz.x, mousePoz.y) && level4.isAlive()) {
                    if (status.back() == 5) {
                        status.emplace_back(4);
                        question = masDragon[3]->question();
                    }
                } else if (spriteCloseButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    status.emplace_back(7);
                } else if (boxName.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    status.emplace_back(5);
                } else if (boxAnswer.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    if (status.back() == 1 || status.back() == 2 || status.back() == 3 || status.back() == 4)
                        status.emplace_back(6);
                } else if (boxReset.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    versionSave = 2;
                } else if (boxNotSave.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    versionSave = -1;
                } else if (boxSave.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                    versionSave = 1;
                }
            }

            if (event.type == sf::Event::KeyPressed && (status.back() == 1 || status.back() == 2 || status.back() == 3 || status.back() == 4))
                switch (event.key.code) {
                    case sf::Keyboard::Num0:
                    case sf::Keyboard::Numpad0:
                        answer += "0";
                        break;
                    case sf::Keyboard::Num1:
                    case sf::Keyboard::Numpad1:
                        answer += "1";
                        break;
                    case sf::Keyboard::Num2:
                    case sf::Keyboard::Numpad2:
                        answer += "2";
                        break;
                    case sf::Keyboard::Num3:
                    case sf::Keyboard::Numpad3:
                        answer += "3";
                        break;
                    case sf::Keyboard::Num4:
                    case sf::Keyboard::Numpad4:
                        answer += "4";
                        break;
                    case sf::Keyboard::Num5:
                    case sf::Keyboard::Numpad5:
                        answer += "5";
                        break;
                    case sf::Keyboard::Num6:
                    case sf::Keyboard::Numpad6:
                        answer += "6";
                        break;
                    case sf::Keyboard::Num7:
                    case sf::Keyboard::Numpad7:
                        answer += "7";
                        break;
                    case sf::Keyboard::Num8:
                    case sf::Keyboard::Numpad8:
                        answer += "8";
                        break;
                    case sf::Keyboard::Num9:
                    case sf::Keyboard::Numpad9:
                        answer += "9";
                        break;
                    case sf::Keyboard::Subtract:
                        answer += "-";
                        break;
                    case sf::Keyboard::Enter:
                        if (status.back() == 1 || status.back() == 2 || status.back() == 3 || status.back() == 4)
                            status.emplace_back(6);
                        break;
                    case sf::Keyboard::Delete:
                    case sf::Keyboard::BackSpace:
                        answer = answer.substr(0, answer.size() - 1);
                        break;
                }
        }

        window.clear();

        window.draw(boxName);
        window.draw(boxScreen);
        window.draw(textName);

        initCloseButton(textureCloseButton, spriteCloseButton);
        window.draw(spriteCloseButton);

        if (status.back() == 0) {
            answer = "";
            initStartSprite(textureStart, spriteStart);
            window.draw(spriteStart);
        } else if (status.back() == 1) {
            initLevel("dragon-green.png", textureDragon, spriteDragon, boxInput, boxAnswer, font, textBoxAnswer);
        } else if (status.back() == 2) {
            initLevel("dragon-blue.png", textureDragon, spriteDragon, boxInput, boxAnswer, font, textBoxAnswer);
        } else if (status.back() == 3) {
            initLevel("dragon-red.png", textureDragon, spriteDragon, boxInput, boxAnswer, font, textBoxAnswer);
        } else if (status.back() == 4) {
            initLevel("dragon-black.png", textureDragon, spriteDragon, boxInput, boxAnswer, font, textBoxAnswer);
        } else if (status.back() == 5) {
            answer = "";

            window.draw(level1.getSprite());
            window.draw(level2.getSprite());
            window.draw(level3.getSprite());
            window.draw(level4.getSprite());
        } else if (status.back() == 6) {
            status.pop_back();
            masCntDragon[status.back() - 1]++;
            cntTask = masCntDragon[status.back() - 1];

            if (masDragon[status.back() - 1]->check_answer(answer)) {
                hero.attack(*masDragon[status.back() - 1]);
                cntRight++;
            } else
                masDragon[status.back() - 1]->attack(hero);

            if (!hero.is_alive()) {
                rollback(hero, status, cntTask, cntRight, masDragon, masCntDragon);
            } else {
                if (masCntDragon[status.back() - 1] < 10)
                    question = masDragon[status.back() - 1]->question();
                else {
                    if (status.back() == 1) {
                        level1.setIsAlive(false);
                    } else if (status.back() == 2) {
                        level2.setIsAlive(false);
                    } else if (status.back() == 3) {
                            level3.setIsAlive(false);
                    } else if (status.back() == 4) {
                        level4.setIsAlive(false);
                    }
                    if (status.back() < 4) {
                        if (status.back() == 1) {
                            level2.setIsAlive(true);
                        } else if (status.back() == 2) {
                            level3.setIsAlive(true);
                        } else if (status.back() == 3) {
                            level4.setIsAlive(true);
                        }
                    }
                    rollback(hero, status, cntTask, cntRight, masDragon, masCntDragon);
                }
            }
            info = to_string(cntTask) + "/10 task\n" + to_string(cntRight) + "/" + to_string(cntTask) + " right";
            answer = "";
        } else if (status.back() == 7) {
            initBoxClose(boxReset, boxNotSave, boxSave);
            window.draw(boxReset);
            window.draw(boxNotSave);
            window.draw(boxSave);

            initTextClose(font, textReset, textNotSave, textSave);
            window.draw(textReset);
            window.draw(textNotSave);
            window.draw(textSave);
        }
        if (status.back() != 0 && status.back() != 5 && status.back() != 7) {
            window.draw(spriteDragon);

            window.draw(boxInput);
            window.draw(boxAnswer);
            window.draw(textBoxAnswer);

            initBoxDragonInfoBoxHeroInfo(boxDragonInfo, boxHeroInfo);
            window.draw(boxDragonInfo);
            window.draw(boxHeroInfo);

            dragonInfo = masDragon[status.back() - 1]->getInfo();
            initTextDragonInfo(font, dragonInfo, textDragonInfo);
            window.draw(textDragonInfo);

            heroInfo = hero.getInfo();
            initTextHeroInfo(font, heroInfo, textHeroInfo);
            window.draw(textHeroInfo);

            initTextQuestion(font, question, textQuestion);
            window.draw(textQuestion);

            initTextAnswer(font, answer, textAnswer);
            window.draw(textAnswer);

            initTextInfo(font, info, textInfo);
            window.draw(textInfo);
        }

        window.display();
    }

    if (versionSave == 1)
        writeFile(level1, level2, level3, level4, masDragon, masCntDragon, hero, cntTask, cntRight);
    if (versionSave == 2)
        writeFileReset();

    return 0;
}