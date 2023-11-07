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

    Ball oBall;

    Brick obrick;

    std::vector<Brick*> oBrick;

    //GameLoop
    //sf::Clock oClock;
    //float fDeltaTime;
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
        //oBall.Move(fDeltaTime);
        //DRAW
        oWindow.clear();

        //oWindow.draw(oCircle);
        oWindow.draw(oRectangle);

        oWindow.display();

        //fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
