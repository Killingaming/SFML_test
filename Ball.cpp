#include "Ball.h"

Ball::Ball() {
    //Création d'un cercle de radius 100
    sf::CircleShape oCircle(100.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Green);
}
/*
void Ball::Move(float fDeltaTime) {
    m_fX += m_oDirection.x * fDeltaTime * 10.f;
    m_fY += m_oDirection.y * fDeltaTime * 10.f;
}*/