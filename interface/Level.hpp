#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
#pragma once

class Level {
public:

    Level(std::string file, int number, int positionX, int positionY) :
        file_(std::move(file) + std::to_string(number) + ".png"),
        positionX_(positionX),
        positionY_(positionY),
        is_alive_(false) {
        initTexture();
    }

    sf::Sprite getSprite() {
        return sprite_;
    }

    void setIsAlive(bool isAlive) {
        is_alive_ = isAlive;
    }

    bool isAlive() const {
        return is_alive_;
    }

private:

    void initTexture() {
        if (!texture_.loadFromFile(file_))
            std::cout << "fail " << file_ << std::endl;
        texture_.setSmooth(true);
        initSprite();
    }

    void initSprite() {
        sprite_.setTexture(texture_);
        sprite_.setScale(0.75, 0.75);
        sprite_.setPosition(positionX_, positionY_);
    }

    int positionX_;
    int positionY_;
    bool is_alive_;

    std::string file_;
    sf::Texture texture_;
    sf::Sprite sprite_;

};