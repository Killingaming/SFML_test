#include <SFML/Graphics.hpp>


#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    //Cr�ation d'un cercle de radius 100
    sf::CircleShape oCircle(100.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Green);


    //Cr�ation d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
    //A la position 100, 100
    oCircle.setPosition(100.f, 100.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);

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

        oWindow.draw(oCircle);
        oWindow.draw(oRectangle);

        oWindow.display();
    }

    return 0;
    //Fuck you 
}
