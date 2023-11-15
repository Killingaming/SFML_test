#include "GameObject.h"

int main() {

    //Création d'une fenêtre
    const sf::Vector2i window_size(700, 800);
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "SFML", sf::Style::Close);
    window.setFramerateLimit(120);

    //Objects Declarations
    GameObject rect({ 350, 600 }, { 50, 100 }, sf::Color::Red);
    GameObject rect1({ 325, 100 }, { 100, 50 }, sf::Color::Cyan);
    GameObject circle({ 350, 600 }, 10, sf::Color::Green);

    sf::Clock clock;
    sf::Time time;
    float deltaTime = 0;
    float Xset = 0;
    float Yset = 0;
    float angle;
    float mouseX;
    float mouseY;
    

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
                mouseX = mouse.x;
                mouseY = mouse.y;
                angle = -atan2(mouse.x - rect.getPosition().x, mouse.y - rect.getPosition().y);
                angle = angle * 180 / 3.14159;
                if (angle > -115 && angle <= 0) {
                    angle = -115;
                }
                if (angle < 115 && angle >= 0) {
                    angle = 115;
                }
                rect.setRotation(angle);
            }
            if (o_event.type == sf::Event::MouseButtonPressed) {
                Yset = ((angle / 100) + 1) * 1.25;
                Xset = 1 - ((angle / 100) * 1.25);
                if (angle > 0) {
                    Yset = -((angle / 100) - 1) * 1.25;
                    Xset = -(1 + ((angle / 100) * 1.25));
                }
            }
            if (o_event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (circle.getPosition().x > window_size.x - 2 * 10 || circle.getPosition().x < 0) {
            Xset = -Xset;
        }
        if (circle.getPosition().y < 0 || circle.getPosition().y > window_size.y - 2 * 10) {
            Yset = -Yset;
        }


        //UPDATE
        /*circle.setDirection({ Xset,Yset });
        circle.move(deltaTime);*/
        circle.setPosition({ mouseX,mouseY });
        

        time = clock.restart();
        deltaTime = time.asSeconds();

        //DRAW
        window.clear();

        if (rect1.checkCollisions(circle) == true) {
            std::cout << "touch";
        }

        rect1.draw(window);
        rect.draw(window);
        circle.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}