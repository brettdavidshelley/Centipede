/*
Author: Brett Shelley
Class: ECE4122
Last Date Modified: 9/25/2024
Description:
    Centipede object file.
Purpose:
    To aid in main Centipede game file.

*/

#include "ECE_Centipede.hpp"
#include <iostream> //DEBUG TOOL
#include <cmath>

ECE_Centipede::ECE_Centipede(int s)
{
    loose = false;
    lastTime = std::chrono::high_resolution_clock::now();
    size = s - 1; //all centipedes will have a head, and it is not part of the list so we decrement
    if (!headTexture.loadFromFile("graphics/head.png"))
    {
        std::cout << "Couldn't Load Head Texture" << std::endl;
    }
    if (!tailTexture.loadFromFile("graphics/tail.png"))
    {
        std::cout << "Couldn't Load Tail Texture" << std::endl;
    }
    speed = 150.0f; //gameplay is 150 usually
    TailPiece head;
    head.sprite.setTexture(headTexture);
    head.sprite.setPosition(1800, 100);
    head.lastPosChange = 0;
    head.visible = true;
    tail.push_back(head);
    //Next we will use the TailPiece struct to set some values
    int posX = tail.front().sprite.getPosition().x; //we will use this a few times
    int posY = tail.front().sprite.getPosition().y; //we will use this a few times
    for (int i = 1; i <= size; i++)
    {
        TailPiece piece;  // Create a new TailPiece object in each iteration
        piece.lastPosChange = 0;
        piece.sprite.setTexture(tailTexture);  // Each piece gets its own sprite with the same texture
        piece.sprite.setPosition(posX + (i * 100), posY);  // Position each piece separately
        tail.push_back(piece);  // Add the new piece to the list
    }
}

void ECE_Centipede::update(std::list<sf::Sprite>& mushrooms)
{
    currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count(); // Convert to seconds
    lastTime = currentTime;
    timeChange = speed * deltaTime;
    tail.front().lastPosChange = timeChange; //set new x change for going left
    move();
    collisions(mushrooms);
    updateNextPositions();
}

void ECE_Centipede::move()
{
    //first loop changes all the positions
    for (std::list<TailPiece>::iterator it = tail.begin(); it != tail.end(); ++it)
    {
        //std::cout << "TailPiece T: Down = " << it->down << ", counter = "
        //<< it->downCounter << ", change = " << it->lastPosChange << std::endl; //DEBUG TOOL
        if (tail.begin() == it)
        {
            float x = tail.begin()->sprite.getPosition().x;
            float y = tail.begin()->sprite.getPosition().y;
            if (tail.begin()->down)
            {
                tail.begin()->sprite.setPosition(x, y + tail.front().lastPosChange);
                tail.begin()->downCounter += tail.front().lastPosChange;
            } else if (tail.begin()->left)
            {
                tail.begin()->sprite.setPosition(x - tail.front().lastPosChange, y);
            } else {
                tail.begin()->sprite.setPosition(x + tail.front().lastPosChange, y);
            }
            continue;
        }
        sf::Vector2f t = it->sprite.getPosition(); //making a copy for easy use
        if (it->down)
        {
            it->sprite.setPosition(t.x, t.y + it->lastPosChange);
            it->downCounter += it->lastPosChange;
        } else if (it->left)
        {
            it->sprite.setPosition(t.x - it->lastPosChange, t.y);
        } else 
        {
            it->sprite.setPosition(t.x + it->lastPosChange, t.y);
        }
    }
}

void ECE_Centipede::updateNextPositions()
{
    //second loop edits all the "last positions"
    for (std::list<TailPiece>::iterator it = tail.end(); it != tail.begin();)
    {
        --it;
        if (it == tail.begin())
        {
            break; //don't do anything to the head
        }
        TailPiece t = *it; //making a copy for easy use
        it->lastPosChange = (std::prev(it))->lastPosChange;
        if (it->sprite.getPosition().x < 1800)
        {
            it->visible = true;
        }
        //std::cout << "Down = " << it->down << std::endl; //DEBUG TOOL
    }
    //std::cout << "END ITERATION" << std::endl; //DEBUG TOOL
}

//This method is useful to check against a laser hit
bool ECE_Centipede::checkCollision(const sf::Sprite& target)
{
    for (auto it = tail.begin(); it != tail.end();)
    {
        if (it->sprite.getGlobalBounds().intersects(target.getGlobalBounds()))
        {
            // The specific laser object hit the centipede
            // Maintain a reference to the next tail piece
            auto nextPiece = std::next(it); // Get the next piece

            // Remove the current tail piece
            it = tail.erase(it); // Erase returns the next iterator
            
            // If nextPiece exists, you can edit it if needed
            if (nextPiece != tail.end())
            {
                //HERE we make nextPiece act as if it is another centipede
                nextPiece->sprite.setTexture(headTexture);
            }

            return true; // Collision detected
        }
        else
        {
            ++it; // Move to the next tail piece if no collision
        }
    }
    return false; // No collision detected
}


//This method will be used privately to check if it should bounce off mushrooms
//and to check against bounds
void ECE_Centipede::collisions(std::list<sf::Sprite>& mushrooms)
{
    for (auto& piece : tail)
    {
        // Check if the centipede hits the left or right bounds
        float x = piece.sprite.getPosition().x;
        float y = piece.sprite.getPosition().y;

        if (y >= 980)
        {
            loose = true;
        }

        // Handle boundary collisions (left and right edges)
        if ((x < 0 || x > 1800) && piece.visible)
        {
            // Reverse direction and move down
            piece.sprite.setPosition(std::clamp(x, 0.0f, 1800.0f), y + piece.lastPosChange);
            piece.down = true;
            piece.left = !piece.left;  // Reverse direction for after down period
            piece.downCounter = 0 + piece.lastPosChange;
            continue;
        }

        if (y)

        if (piece.downCounter > 100)
        {
            piece.sprite.setPosition(x, y - std::fmod(y, 100));
            piece.down = false;
        }

        // Handle collisions with mushrooms
        for (auto& m : mushrooms)
        {
            if (m.getGlobalBounds().intersects(piece.sprite.getGlobalBounds()))
            {
                // If the centipede hits a mushroom, reverse direction and move down
                if (!piece.down)
                {
                    if (piece.left)
                    {
                        x = m.getPosition().x + 100; //right side of mushroom
                    } else
                    {
                        x = m.getPosition().x - 100; //left side of mushroom
                    }
                    piece.sprite.setPosition(x, y);
                    piece.down = true;
                    piece.left = !piece.left;  // Reverse direction
                    piece.downCounter = 0;
                    break;
                } else
                {
                    y = m.getPosition().y - 100;
                    piece.sprite.setPosition(x, y);
                    piece.down = false;
                }
            }
        }
    }
}

void ECE_Centipede::draw(sf::RenderWindow& window)
{
    for (auto it = tail.rbegin(); it != tail.rend(); ++it)
    {
        if (it->down)
        {
            it->sprite.setRotation(270);
            it->sprite.move(0, 100); //rotation causes a change in rendor position
            window.draw(it->sprite);
            it->sprite.move(0, -100); //undo the change we made a second ago
            it->sprite.setRotation(0);
        } else if (!(it->left))
        {
            it->sprite.setRotation(180);
            it->sprite.move(100, 100);
            window.draw(it->sprite);
            it->sprite.move(-100, -100);
            it->sprite.setRotation(0);
        } else 
        {
            window.draw(it->sprite);
        }
    }
}

bool ECE_Centipede::win()
{
    if (tail.size() == 0)
    {
        return true;
    }
    return false;
}

bool ECE_Centipede::centipedeGameOver()
{
    return loose;
}

std::list<sf::Sprite> ECE_Centipede::getTailSprites()
{
    std::list<sf::Sprite> sprites;
    for (auto& t : tail)
    {
        sprites.push_back(t.sprite);
    }
    return sprites;
}

//this method will pause the centipede from moving
void ECE_Centipede::pause()
{
    currentTime = std::chrono::high_resolution_clock::now();
    lastTime = currentTime;
}

