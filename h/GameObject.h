#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SFML/Graphics/RenderWindow.hpp"

class GameObject {
public:

    virtual void update(sf::Time dt) = 0; // Pure virtual function
    virtual void draw(sf::RenderWindow& window) const = 0; // Pure virtual function

    virtual ~GameObject() = default; // Virtual destructor for proper cleanup
};

#endif // GAME_OBJECT_H
