#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    sf::RectangleShape rec;
    sf::CircleShape cir;
    sf::Shape* sha;

public:
    //Constructeur

    void setPosition(sf::Vector2f _position);
    sf::Vector2f returnPosition();
    void setSize(sf::Vector2f _size);
    sf::Vector2f returnSize();
    void setColor(sf::Color _color);
    sf::Color returnColor();
};
