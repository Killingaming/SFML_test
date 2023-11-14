#include "GameObject.h"

int main() {

    //Cr�ation d'une fen�tre
    const sf::Vector2i window_size(700, 800);
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "SFML", sf::Style::Close);
    window.setFramerateLimit(120);

    //Objects Declarations
    GameObject rect({ 350, 600 }, { 50, 100 }, sf::Color::Red);
    GameObject circle({ 350, 50 }, 10, sf::Color::Green);

    sf::Clock clock;
    sf::Time time;
    float deltaTime = 0;
    int deplace = 0;


    //GameLoop
    while (window.isOpen()) {
        //EVENT
        sf::Event o_event{};

        //Poll for Events
        while (window.pollEvent(o_event)) {
            if (o_event.type == sf::Event::KeyPressed) {
                if (o_event.key.code == sf::Keyboard::R) {
                    rect.rotate(45);
                }
                if (o_event.key.code == sf::Keyboard::Z) {
                    rect.setDirection({ rect.getDirection().x,-1 });
                    rect.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::Q) {
                    rect.setDirection({ -1,rect.getDirection().y });
                    rect.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::S) {
                    rect.setDirection({ rect.getDirection().x,1 });
                    rect.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::D) {
                    rect.setDirection({ 1,rect.getDirection().y });
                    rect.move(deltaTime);
                }
            }

            if (o_event.type == sf::Event::KeyReleased) {
                if (o_event.key.code == sf::Keyboard::Z) {
                    rect.setDirection({ rect.getDirection().x,0 });
                }
                if (o_event.key.code == sf::Keyboard::Q) {
                    rect.setDirection({ 0,rect.getDirection().y });
                }
                if (o_event.key.code == sf::Keyboard::S) {
                    rect.setDirection({ rect.getDirection().x,0 });
                }
                if (o_event.key.code == sf::Keyboard::D) {
                    rect.setDirection({ 0,rect.getDirection().y });
                }
            }

            if (o_event.type == sf::Event::MouseMoved) {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                float angle;
                angle = -atan2(mouse.x - rect.getPosition().x, mouse.y - rect.getPosition().y) * 180 / 3.14159;
                rect.setRotation(angle);
            }
            if (o_event.type == sf::Event::MouseButtonPressed) {







            }
            if (o_event.type == sf::Event::Closed) {
                window.close();
            }
        }


        //UPDATE
        //circle.setDirection({ circle.getDirection().x,-1 });
        //circle.move(deltaTime);


        time = clock.restart();
        deltaTime = time.asSeconds();

        //DRAW
        window.clear();


        rect.draw(window);
        circle.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}