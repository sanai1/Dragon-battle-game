#include <SFML/Graphics.hpp>
#include <utility>
#include "/home/aleksandr/CLionProjects/game/logic/Dragon.hpp"
#include "../logic/Hero.hpp"

#pragma once

void initStartSprite(sf::Texture& texture, sf::Sprite& sprite) {

    if (!texture.loadFromFile("/home/aleksandr/CLionProjects/game/image/start-photo.jpg"))
        std::cout << "start-photo.jpg" << std::endl;
    sprite.setTexture(texture);
    sprite.setPosition(20, 105);
    sprite.setScale(0.99, 0.99);

}

void initDragon(std::string nameDragon, sf::Texture& textureDragon, sf::Sprite& spriteDragon) {
    if (!textureDragon.loadFromFile("/home/aleksandr/CLionProjects/game/image/" + nameDragon))
        std::cout << "fail " << nameDragon << std::endl;
    textureDragon.setSmooth(true);
    spriteDragon.setTexture(textureDragon);
    spriteDragon.setScale(0.75, 0.75);
    spriteDragon.setPosition(50, 150);
}

void initBox(sf::RectangleShape& boxInput, sf::RectangleShape& boxAnswer, sf::Font& font, sf::Text& textBoxAnswer) {
    boxInput.setOutlineThickness(2);
    boxInput.setOutlineColor(sf::Color::Black);
    boxInput.setPosition(355, 650);
    boxInput.setSize(sf::Vector2f(300, 100));
    boxInput.setFillColor(sf::Color(0, 255, 255, 100));

    boxAnswer.setOutlineThickness(2);
    boxAnswer.setOutlineColor(sf::Color::Black);
    boxAnswer.setPosition(355, 900);
    boxAnswer.setSize(sf::Vector2f(300, 50));
    boxAnswer.setFillColor(sf::Color::Green);

    textBoxAnswer.setFont(font);
    textBoxAnswer.setString("To answer");
    textBoxAnswer.setFillColor(sf::Color::Black);
    textBoxAnswer.setCharacterSize(40);
    textBoxAnswer.setPosition(410, 900);
}

void initTextAnswer(sf::Font& font, std::string& answer, sf::Text& textAnswer) {
    textAnswer.setFont(font);
    textAnswer.setString(answer);
    textAnswer.setCharacterSize(50);
    textAnswer.setPosition(360, 670);
}

void initTextQuestion(sf::Font& font, std::string& str, sf::Text& textQuestion) {
    textQuestion.setFont(font);
    textQuestion.setString(str);
    textQuestion.setCharacterSize(50);
    textQuestion.setPosition(600, 300);
}

void initTextInfo(sf::Font& font, std::string& str, sf::Text& textInfo) {
    textInfo.setFont(font);
    textInfo.setString(str);
    textInfo.setCharacterSize(25);
    textInfo.setPosition(450, 975);
}

void initLevel(
        std::string nameDragon,
        sf::Texture& textureDragon,
        sf::Sprite& spriteDragon,
        sf::RectangleShape& boxInput,
        sf::RectangleShape& boxAnswer,
        sf::Font& font,
        sf::Text& textBoxAnswer) {
    initDragon(std::move(nameDragon), textureDragon, spriteDragon);
    initBox(boxInput, boxAnswer, font, textBoxAnswer);
}

void initCloseButton(sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("/home/aleksandr/CLionProjects/game/image/close-button.png"))
        cout << "fail close-button.png" << endl;
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.15, 0.15);
    sprite.setPosition(910, 10);
}

void initBoxClose(sf::RectangleShape& boxReset, sf::RectangleShape& boxNotSave, sf::RectangleShape& boxSave) {
    boxSave.setOutlineThickness(2);
    boxSave.setOutlineColor(sf::Color::Black);
    boxSave.setPosition(380, 200);
    boxSave.setSize(sf::Vector2f(250, 100));
    boxSave.setFillColor(sf::Color::Green);

    boxNotSave.setOutlineThickness(2);
    boxNotSave.setOutlineColor(sf::Color::Black);
    boxNotSave.setPosition(380, 450);
    boxNotSave.setSize(sf::Vector2f(250, 100));
    boxNotSave.setFillColor(sf::Color::Yellow);

    boxReset.setOutlineThickness(2);
    boxReset.setOutlineColor(sf::Color::Black);
    boxReset.setPosition(380, 700);
    boxReset.setSize(sf::Vector2f(250, 100));
    boxReset.setFillColor(sf::Color::Red);
}

void initTextClose(sf::Font& font, sf::Text& textReset, sf::Text& textNotSave, sf::Text& textSave) {
    textReset.setFont(font);
    textReset.setString("Reset");
    textReset.setCharacterSize(60);
    textReset.setPosition(425, 710);
    textReset.setFillColor(sf::Color::Black);

    textNotSave.setFont(font);
    textNotSave.setString("Not save");
    textNotSave.setCharacterSize(60);
    textNotSave.setPosition(385, 460);
    textNotSave.setFillColor(sf::Color::Black);

    textSave.setFont(font);
    textSave.setString("Save");
    textSave.setCharacterSize(60);
    textSave.setPosition(435, 210);
    textSave.setFillColor(sf::Color::Black);
}

void initBoxDragonInfoBoxHeroInfo(sf::RectangleShape& boxDragonInfo, sf::RectangleShape& boxHeroInfo) {
    boxDragonInfo.setOutlineThickness(2);
    boxDragonInfo.setOutlineColor(sf::Color::Black);
    boxDragonInfo.setPosition(55, 750);
    boxDragonInfo.setSize(sf::Vector2f(250, 150));
    boxDragonInfo.setFillColor(sf::Color::Blue);

    boxHeroInfo.setOutlineThickness(2);
    boxHeroInfo.setOutlineColor(sf::Color::Black);
    boxHeroInfo.setPosition(700, 750);
    boxHeroInfo.setSize(sf::Vector2f(250, 150));
    boxHeroInfo.setFillColor(sf::Color::Blue);
}

void initTextDragonInfo(sf::Font& font, std::string& str, sf::Text& textDragonInfo) {
    textDragonInfo.setFont(font);
    textDragonInfo.setString(str);
    textDragonInfo.setCharacterSize(40);
    textDragonInfo.setPosition(65, 750);
}

void initTextHeroInfo(sf::Font& font, std::string& str, sf::Text& textHeroInfo) {
    textHeroInfo.setFont(font);
    textHeroInfo.setString(str);
    textHeroInfo.setCharacterSize(40);
    textHeroInfo.setPosition(710, 750);
}

void rollback(Hero& hero, vector<int>& status, int& cntTask, int& cntRight, Dragon* masDragon[], int* masCntDragon) {
    hero.setHealth(100);
    status.emplace_back(5);
    cntTask = 0;
    cntRight = 0;

    for (int i = 0; i < 4; i++)
        masDragon[i]->setHealth(200);

    for (int i = 0; i < 4; i++)
        masCntDragon[i] = 0;
}

void initIsWin(sf::RectangleShape& boxIsWin, sf::Font& font, sf::Text& textIsWin, string str) {
    boxIsWin.setOutlineThickness(5);
    boxIsWin.setOutlineColor(sf::Color::Black);
    boxIsWin.setPosition(325, 550);
    boxIsWin.setSize(sf::Vector2f(350, 100));
    boxIsWin.setFillColor(sf::Color::Blue);

    textIsWin.setFont(font);
    textIsWin.setString(str);
    textIsWin.setCharacterSize(50);
    if (str == "Level is passed") {
        textIsWin.setFillColor(sf::Color::Green);
        textIsWin.setPosition(325, 565);
    } else {
        textIsWin.setFillColor(sf::Color::Red);
        textIsWin.setPosition(345, 565);
    }
}