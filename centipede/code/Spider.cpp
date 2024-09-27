/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    To provide helpful methods for controlling spider logic.
Purpose:
    To aid in main Centipede game file.

*/

#include "Spider.hpp"
#include <iostream>

Spider::Spider()
    : seed(std::chrono::system_clock::now().time_since_epoch().count()),
      generator(seed)
{
    lastTime = std::chrono::high_resolution_clock::now();
    speed = 300.0f;
    if (!spiderStillTexture.loadFromFile("graphics/spider.png"))
    {
        std::cout << "Could not load spider texture" << std::endl;
    }
    std::uniform_int_distribution<int> randomNum(480, 780); //starting locations for spider
    posX = randomNum(generator);
    posY = randomNum(generator);
    this->setTexture(spiderStillTexture);
    this->setPosition(posX, posY); 
}

void Spider::move()
{
    updateDirection();
    currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count(); // Convert to seconds
    lastTime = currentTime;
    float change = speed * deltaTime;
    if (down)
    {
        posY += change;
        if (posY > 930)
        {
            posY = 930; //1080 - 150 (size of spider)
            down = false; //add some variety I guess?
            up = true;
        }
    }
    if (up)
    {
        posY -= change;
        if (posY < 480)
        {
            posY = 480;
            up = false;
            down = true;
        }
    }
    if (left)
    {
        posX -= change;
        if (posX < 0)
        {
            posX = 0;
            left = false;
            right = true;
        }
    }
    if (right)
    {
        posX += change;
        if (posX > 1770) 
        {
            posX = 1770; //19020 - 150 (size of spider)
            right = false;
            left = true;
        }
    }
    this->setPosition(posX, posY);    
}

void Spider::updateDirection()
{
    currentTime = std::chrono::high_resolution_clock::now();
    float delay = std::chrono::duration<float>(currentTime - lastTimeDirection).count();
    //delay just makes it seem a little more intentional in the movement
    if (delay > 0.5f)
    {
        lastTimeDirection = currentTime;
        //choose a direction to turn on
        int num = randomNumber();
        if (num == 0)
        {
            left = true;
            if (right == true)
            {
                right == false; //undo opposing forces
            }
        } else if (num == 1)
        {
            up = true;
            if (down)
            {
                down == false;
            }
        } else if (num == 2)
        {
            right = true;
            if (left)
            {
                left = false; //undo the opposing force
            }
        } else if (num = 3)
        {
            down = true;
            if (up)
            {
                up = false;
            }
        }
    }
}

void Spider::draw(sf::RenderWindow& window)
{
    window.draw(*this);
}

bool Spider::checkCollision(const sf::Sprite& target)
{
    return this->getGlobalBounds().intersects(target.getGlobalBounds());
}

void Spider::pause()
{
    currentTime = std::chrono::high_resolution_clock::now();
    lastTime = currentTime;
}

//primarily used for direction
int Spider::randomNumber()
{
    std::uniform_int_distribution<int> randomNum(0, 4);
    return randomNum(generator);
}

//this method is for when the spider hits the player
//and we wait for it to respawn
void Spider::restart()
{
    posX = -500;
    posY = -500;
    left = false;
    right = false;
    up = false;
    down = false;
    //later implement a delay for when it comes back?
}