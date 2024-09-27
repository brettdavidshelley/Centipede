/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    ECE_LaserBlast description file.
Purpose:
    To aid in main Centipede game file.

*/
#ifndef ECE_LASER_BLAST_HPP
#define ECE_LASER_BLAST_HPP

#include <SFML/Graphics.hpp>
#include <chrono>

class ECE_LaserBlast : public sf::Sprite {
public:
    ECE_LaserBlast(int x, int y, const sf::Texture& texture);
    void update();
    void draw(sf::RenderWindow& window) const;
    bool isOffScreen() const;
    bool checkCollision(const sf::Sprite& target) const;
    void pause();

private:
    float speed;
    
    // Member variables for time tracking
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;

    // Position variables
    float posY;
    float posX;
};

#endif

