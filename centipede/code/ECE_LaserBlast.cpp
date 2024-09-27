/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    To provide helpful methods for controlling player laser logic.
Purpose:
    To aid in main Centipede game file.

*/
#include "ECE_LaserBlast.hpp"

ECE_LaserBlast::ECE_LaserBlast(int x, int y, const sf::Texture& texture)
    : posX(x), posY(y), lastTime(std::chrono::high_resolution_clock::now())
{
    // Initialize the laser blast shape
    this->setTexture(texture);
    this->setPosition(x, y);
    //this->setScale(0.1f, 0.4f); //Scale of laser
    speed = 900.0f; // Speed at which the laser moves upward
}

void ECE_LaserBlast::update()
{
    currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count(); // Convert to seconds
    lastTime = currentTime;

    posY -= (speed * deltaTime); // Update Y position
    this->setPosition(posX, posY); // Update shape position
}

void ECE_LaserBlast::draw(sf::RenderWindow& window) const
{
    window.draw(*this);
}

bool ECE_LaserBlast::isOffScreen() const
{
    return (this->getPosition().y + this->getGlobalBounds().height) < 0;
}

bool ECE_LaserBlast::checkCollision(const sf::Sprite& target) const
{
    return this->getGlobalBounds().intersects(target.getGlobalBounds());
}

void ECE_LaserBlast::pause()
{
    currentTime = std::chrono::high_resolution_clock::now();
    lastTime = currentTime;
}

