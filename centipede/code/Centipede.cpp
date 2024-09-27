/*
Author: Brett Shelley
Version: 1.1
Last Date Modified: 9/27/2024
Description:
    Recreation of classic centipede game from arcades.
Purpose:
    To understand and apply 2D graphics and class creation in C++.

*/

// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <chrono>
#include <random>
#include "ECE_LaserBlast.hpp"
#include "ECE_Centipede.hpp"
#include "Spider.hpp"

// Make code easier to type with "using namespace"
using namespace sf;
//game loop returns true if won
bool game(sf::RenderWindow& window); //specify game method that will be called

std::list<sf::Sprite> setupMushrooms(sf::Texture& t);

int main() {
    // Create a window with the given dimensions

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Centipede", sf::Style::Default);
    //Increase view size to see everything in pace Ice
    //View view = window.getView();
    //view.setSize(window.getSize().x * 1.5, window.getSize().y * 1.5);
    //window.setView(view);

    // Load the background texture from file
    sf::Texture startTexture;
    if (!startTexture.loadFromFile("graphics/startBackground.png"))
    {
        return -1; // Exit if loading fails
    }

    // Create a sprite to display the texture
    sf::Sprite startBackground;
    startBackground.setTexture(startTexture);

    // Main game loop
    while (window.isOpen())
    {
        window.draw(startBackground);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Check for window close event
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Check for key press events
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close(); // Close window when Escape is pressed
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    game(window);
                }
            }
        }
        window.display();
    }
    return 0;
}

bool game(sf::RenderWindow& window)
{
    //----------------------------------------Main Game Setup-------------------------------------------
    //Time:
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();
    float speed = 500.0f;
    //Mushroom texture:
    sf::Texture mushroomTexture;
    if (!mushroomTexture.loadFromFile("graphics/mushroom.png"))
    {
        std::cout << "Couldn't Load Mushroom Texture" << std::endl;
    }
    sf::Texture mushroomTexture2;
    if (!mushroomTexture2.loadFromFile("graphics/mushroom2.png"))
    {
        std::cout << "Couldn't Load Mushroom 2 Texture" << std::endl;
    }
    sf::Texture mushroomTexture3;
    if (!mushroomTexture3.loadFromFile("graphics/mushroom3.png"))
    {
        std::cout << "Couldn't Load Mushroom 3 Texture" << std::endl;
    }
    sf::Texture mushroomTexture4;
    if (!mushroomTexture4.loadFromFile("graphics/mushroom4.png"))
    {
        std::cout << "Couldn't Load Mushroom 4 Texture" << std::endl;
    }
    std::list<sf::Sprite> mushrooms;
    mushrooms = setupMushrooms(mushroomTexture);

    //game background texture
    sf::Texture gameTexture;
    if (!gameTexture.loadFromFile("graphics/gameBackground.png"))
    {
        std::cout << "Couldn't Load gameBackground Texture" << std::endl;
    }
    sf::Sprite gameBackground;
    gameBackground.setTexture(gameTexture);

    //Make spider:
    Spider spider;
    
    //if player is alive:
    bool alive = true;

    //Player texture:
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("graphics/player.png"))
    {
        std::cout << "Couldn't Load Player Texture" << std::endl;
    }
    float playerX = 900;
    float playerY = 960;
    int playerStartX = playerX;
    int playerStartY = playerY;
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(playerX, playerY);
    //player blast clock:
    std::chrono::high_resolution_clock::time_point lastBlastTime = std::chrono::high_resolution_clock::now();
    const int BLAST_DELAY_MS = 100; //delay we can adjust
    //Score Information:
    int score = 0;
    sf::Text scoreText;
    sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(Color::Red);
    scoreText.setPosition(914, 0);
    scoreText.setString(std::to_string(score));
    //Lives Information:
    int lives = 2;
    sf::Sprite life1;
    life1.setTexture(playerTexture);
    life1.setPosition(14, 0);
    sf::Sprite life2;
    life2.setTexture(playerTexture);
    life2.setPosition(114, 0);
    //Pause Information:
    sf::Text pauseText;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
    pauseText.setFont(font);
    pauseText.setCharacterSize(200);
    pauseText.setFillColor(Color::White);
    pauseText.setPosition(654, 450);
    pauseText.setString("Pause");
    //GameOver Information:
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(200);
    gameOverText.setFillColor(Color::White);
    gameOverText.setPosition(400, 400);
    gameOverText.setString("Game Over!");
    //Win Information:
    bool win = false;
    sf::Text winText;
    winText.setFont(font);
    winText.setCharacterSize(200);
    winText.setFillColor(Color::White);
    winText.setPosition(400, 400);
    winText.setString("You Win!!!");
    //Laser List:
    std::list<ECE_LaserBlast> blasts;
    sf::Texture blastTexture;
    if (!blastTexture.loadFromFile("graphics/laser.png"))
    {
        std::cout << "Couldn't Load Laser Texture" << std::endl;
    }
    //Centipede Stuff:
    std::list<ECE_Centipede> centipedes; //starts as only one
    centipedes.emplace_back(12); //create one centipede to start, 11 segments and a head
    //-------------------------------------------------Main Game Loop---------------------------------------
    while (alive && window.isOpen())
    {
        currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count(); // Convert to seconds
        lastTime = currentTime;
        window.clear();
        window.draw(gameBackground);
        for (const auto& m : mushrooms)
        {
            window.draw(m);
        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Check for window close event
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Check for key press events
            if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    alive = false; //easy way to end the game for debugging
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    //Escape pauses the game
                    bool pause = true;
                    while (pause)
                    {
                        spider.pause();
                        for (auto& c : centipedes)
                        {
                            c.pause();
                        }
                        for (auto& b : blasts)
                        {
                            b.pause();
                        }
                        //New event for pausing
                        sf::Event pauseEvent;
                        while (window.pollEvent(pauseEvent))
                        {
                            if (pauseEvent.key.code == sf::Keyboard::Enter)
                            {
                                pause = false; //Enter unpauses the game
                            }
                            if (pauseEvent.type == sf::Event::Closed)
                            {
                                window.close();
                                pause = false; //get out of inner loop inside game loop
                            }
                        }
                        window.clear();
                        window.draw(gameBackground);
                        spider.draw(window);
                        for (const auto& m : mushrooms)
                        {
                            window.draw(m);
                        }
                        for (ECE_LaserBlast b : blasts)
                        {
                            b.draw(window);
                        }
                        if (lives == 2)
                        {
                            window.draw(life2);
                            window.draw(life1);
                        } else if (lives == 1)
                        {
                            window.draw(life1);
                        }
                        for (auto& c : centipedes)
                        {
                            c.draw(window);
                        }
                        scoreText.setString(std::to_string(score));
                        window.draw(scoreText);
                        window.draw(playerSprite);
                        window.draw(pauseText);
                        window.display();
                    }
                }
            }
        }
        //Move player outside event to allow for more real time movement:
        float change = speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerX > 0)
        {
            playerX -= change;
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerX < 1800)
        {
            playerX += change;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerY > 800)
        {
            playerY -= change;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerY < 980)
        {
            playerY += change;
        }
        playerSprite.setPosition(playerX, playerY);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //add laser to list of laser blasts and checks a delay before allowing it to send
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto timeSinceLastBlast = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastBlastTime);
            if (timeSinceLastBlast.count() > BLAST_DELAY_MS)
            {
                blasts.emplace_back(playerX + 39, playerY - 10, blastTexture);
                lastBlastTime = currentTime;
            }
        }
        for (std::list<ECE_LaserBlast>::iterator it = blasts.begin(); it != blasts.end();)
        {
            it->update(); // Call update on the laser blast
            it->draw(window); // Draw the laser blast
            if (it->isOffScreen()) {
                it = blasts.erase(it); // Remove and update the iterator
                continue;
            }
            bool hit = false; //to track if the blast hit something
            for (std::list<sf::Sprite>::iterator itMush = mushrooms.begin(); itMush != mushrooms.end();)
            {
                if (it->checkCollision(*itMush))
                {
                    hit = true;
                    it = blasts.erase(it);
                    //compare with the texture to know what state the sprite is in (3 hits and it's gone)
                    const sf::Texture* currentTexture = itMush->getTexture();
                    if (currentTexture == &mushroomTexture)
                    {
                        itMush->setTexture(mushroomTexture2);
                    } else if (currentTexture == &mushroomTexture2)
                    {
                        itMush->setTexture(mushroomTexture3);
                    } else if (currentTexture == &mushroomTexture3)
                    {
                        itMush->setTexture(mushroomTexture4);
                    } else 
                    {
                        itMush = mushrooms.erase(itMush);
                    }
                    break;
                }
                ++itMush;
            }
            if (hit)
            {
                continue;
            }
            win = true; //it will check if any centipedes remain, if so it will be false;
            for (std::list<ECE_Centipede>::iterator itCent = centipedes.begin(); itCent != centipedes.end(); ++itCent)
            {
                if (itCent->checkCollision(*it))
                {
                    score += 100;
                    hit = true;
                    //create mushroom and then delete blast
                    sf::Sprite newMushroom;
                    newMushroom.setTexture(mushroomTexture);
                    int x = it->getPosition().x;
                    int y = it->getPosition().y;
                    x = (x / 100) * 100;
                    y = (y / 100) * 100;
                    it = blasts.erase(it); //erase blast
                    //make sure we don't accidentally change direction of centipede before it gets within bounds at the beginning
                    if (y < 200 && x > 1720)
                    {
                        win = false;
                        continue;
                    }
                    newMushroom.setPosition(x, y);
                    mushrooms.push_back(newMushroom);
                }
                if (!(itCent->win()))
                {
                    win = false; //here we check win
                }
            }
            if (hit)
            {
                continue;
            }
            if (spider.checkCollision(*it))
            {
                hit = true;
                it = blasts.erase(it);
                score += 300;
                spider.restart();
            }
            ++it;
        }
        std::list<sf::Sprite> sprites = centipedes.front().getTailSprites();
        for (std::list<sf::Sprite>::iterator itS = sprites.begin();
            itS != sprites.end();
            ++itS)
        {
            if (itS->getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
            {
                alive = false;
            }
        }   
        window.draw(playerSprite);
        if (lives == 2)
        {
            window.draw(life2);
            window.draw(life1);
        } else if (lives == 1)
        {
            window.draw(life1);
        }
        //Check spider hits here (mushrooms and player)
        spider.move();
        for (auto it = mushrooms.begin(); it != mushrooms.end();)
        {
            if (spider.checkCollision(*it))
            {
                it = mushrooms.erase(it);  // Erase returns the next valid iterator
            }
            else
            {
                ++it;  // Only increment if nothing is erased
            }
        }
        if (spider.checkCollision(playerSprite))
        {
            lives--;
            if (!(lives == 0))
            {
                spider.restart(); //only restart spider if gameover doesn't occur (that way it displays where you died)
                playerX = playerStartX; //set player back at origin
                playerY = playerStartY;
            }
        }
        for (auto& c : centipedes)
        {
            c.update(mushrooms);
            c.draw(window);
            if (c.centipedeGameOver())
            {
                alive = false;
            }
        }
        spider.draw(window);
        scoreText.setString(std::to_string(score));
        window.draw(scoreText);
        window.display();
        if (lives < 0)
        {
            alive = false;
        }
        while (!alive || win)
        {
            //New event for pausing
            sf::Event gameOverEvent;
            while (window.pollEvent(gameOverEvent))
            {
                if (gameOverEvent.type == sf::Event::Closed)
                {
                    alive = true; //only way to get out of this loop
                    win = false; //only way to get out of loop
                    window.close();
                }
                if (gameOverEvent.key.code == sf::Keyboard::Enter)
                {
                    return false;
                }
            }
            spider.draw(window);
            window.clear();
            window.draw(gameBackground);
            for (const auto& m : mushrooms)
            {
                window.draw(m);
            }
            for (ECE_LaserBlast b : blasts)
            {
                b.draw(window);
            }
            if (lives == 2)
            {
                window.draw(life2);
                window.draw(life1);
            } else if (lives == 1)
            {
                window.draw(life1);
            }
            for (auto& c : centipedes)
            {
                c.draw(window);
            }
            scoreText.setString(std::to_string(score));
            window.draw(scoreText);
            window.draw(playerSprite);
            if (!alive)
            {
                window.draw(gameOverText);
            } else if (win)
            {
                window.draw(winText);
            }
            window.display();
        }
    }
    return true; //WILL PROBABLY EDIT THIS LATER
}

std::list<sf::Sprite> setupMushrooms(sf::Texture& t)
{
    std::list<sf::Sprite> mushrooms;

    //Random Number Generator Stuff:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distributionX(101,1799);
    std::uniform_int_distribution<int> distributionY(201,799);
    //Create 30 random mushrooms at the beginning:
    for (int i = 0; i < 30; ++i)
    {
        sf::Sprite s;
        s.setTexture(t);
        //I will divide by 100 and then multiply by 100 to get it on a grid system
        //the sprite is 100 both x and y dimensions
        int x = distributionX(generator) / 100;
        int y = distributionY(generator) / 100;
        s.setPosition(x*100, y*100);
        mushrooms.push_back(s);
    }
        
    //For Debugging:
    //for (const auto& m : mushrooms)
    //{
    //    std::cout << "Mushroom at (" << m.x << ", " << m.y << ")\n";
    //}

    return mushrooms;
}


