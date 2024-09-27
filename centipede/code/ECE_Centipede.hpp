/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    ECE_Centipede description file.
Purpose:
    To aid in main Centipede game file.

*/

#ifndef ECE_CENTIPEDE_HPP
#define ECE_CENTIPEDE_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include <chrono>
#include <iostream>

class ECE_Centipede {
public:
    ECE_Centipede(int s);
    void update(std::list<sf::Sprite>& mushrooms);
    void move();
    void draw(sf::RenderWindow& window);
    bool checkCollision(const sf::Sprite& target);
    bool win();
    bool centipedeGameOver();
    void pause();
    std::list<sf::Sprite> getTailSprites();
private:
    void collisions(std::list<sf::Sprite>& mushrooms);
    void updateNextPositions();
    int size;
    struct TailPiece 
    {
        float lastPosChange;
        sf::Sprite sprite;
        bool down = false;
        bool left = true;
        float downCounter = 0;
        bool visible = false;
    };
    std::list<TailPiece> tail;

    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;
    float timeChange;

    float speed;

    bool loose;

    sf::Texture headTexture;  // Store textures as member variables
    sf::Texture tailTexture;  // So they persist during the object's lifetime
};

#endif
