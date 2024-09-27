/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    To provide helpful methods for controlling spider logic.
Purpose:
    To aid in main Centipede game file.

*/


#ifndef SPIDER_HPP
#define SPIDER_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>

class Spider : public sf::Sprite {
public:
    Spider();
    void move();
    void draw(sf::RenderWindow& window);
    bool checkCollision(const sf::Sprite& target);
    void pause();
    void restart();
private:
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    float posX;
    float posY;

    float speed;

    std::chrono::time_point<std::chrono::high_resolution_clock> lastTimeDirection;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;

    sf::Texture spiderStillTexture; //later should add moving texture

    //random Num generaor stuff:
    unsigned seed;
    std::default_random_engine generator;
    int randomNumber();
    void updateDirection();
};

#endif
