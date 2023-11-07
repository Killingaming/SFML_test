#include "Slidebar.h"

Slidebar::Slidebar() {
    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(640.f, 5.f));
    //A la position 100, 100
    oRectangle.setPosition(0.f, 475.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);
}