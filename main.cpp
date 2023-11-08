#include <SFML/Graphics.hpp>
#include "GameObject.cpp"
#include "Brick.h"
#include "Ball.h"
#include "Cannon.h"


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(640.f, 5.f));
    //A la position 100, 100
    oRectangle.setPosition(0.f, 475.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);

    //Création d'un cercle de radius 100
    sf::CircleShape oCircle(100.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Green);

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE
        
        //DRAW
        oWindow.clear();

        //oWindow.draw(oCircle);
        oWindow.draw(oRectangle /*oCircle*/);

        oWindow.display();

        //fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
