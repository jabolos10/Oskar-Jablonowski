#pragma once
#include <memory>
#include <vector>

//#include "AnimatedBackground.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "EnemyShip2.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "EnemyBullet2.h"
#include "FloatingText.h"
#include "GameObject.h"
//#include "Healthbar.h"

enum class GameState {
    Menu,
    Level1,
    Level2,
    GameOver,
};

extern GameState gameState;

class Game {
public:
    Game(); // Constructor to initialize the game
    void run(); // Main game loop
    void addBullet(std::unique_ptr<Bullet> bullet); // Method to add bullets

private:

    float windowWidth = 1000;
    float windowHeight=800;

    void resetGame();
    void handleEvents(); // Handle user input and game events
    void update(sf::Time dt); // Update the game state
    void render(); // Render all game elements
    void spawnEnemies();
    void spawnEnemies2();
    void handleCollisions();
    void testCollision();
    sf::Texture backgroundTexture; // Texture for the background during game
    sf::Sprite backgroundSprite; // Sprite for the background during game
    float backgroundSpeed = 80.f; // Positive to move downwards (in pixels per second)
    sf::Texture backgroundTexture2; // Texture for the background during game
    sf::Sprite backgroundSprite2; // Sprite for the background during game

    sf::Texture backgroundTextureGameOver; // Background texture when the Game is over
    sf::Sprite backgroundSpriteGameOver; // Background sprite when the Game is over

    sf::Texture backgroundTextureMenu; // Background texture when Game is started or restarted after losing
    sf::Sprite backgroundSpriteMenu; // Background sprite  when Game is started or restarted after losing


    sf::RenderWindow window; // Main game window
    std::vector<std::unique_ptr<GameObject>> gameObjects;

    std::unique_ptr<PlayerShip> playerShip;

    sf::Clock clock; // Clock to manage time and animations
    bool running; // Boolean to check if the game is running

    sf::Clock spawnClock; // Clock to track time for enemy spawning
    sf::Time spawnInterval = sf::seconds(1.8); // Set the spawn interval of EnemyShip in seconds
    sf::Clock spawnClock2;
    sf::Time spawnInterval2 = sf::seconds(5.7);   // Set the spawn interval of EnemyShip2 in seconds
    bool playerShipDestroyed = false;

    void handleMenuInput(sf::Event event);
    void startLevel1();
    void startLevel2();

    sf::Font font;               // Font for text rendering
    sf::Text healthText;         // Text to display player HP percentage
    std::vector<FloatingText> floatingTexts; // Floating damage or health points

    sf::Text scoreText; //Text for displaying the score
    int score = 0; // High score variable



};
