#include "GameObjects.h"

#include "cannonball.h"
#include <cmath>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

double Cannonball::getPosX() const {
    // write your code here,
    // and change the return value
    return 0;
}

double Cannonball::getPosY() const {
    // write your code here,
    // and change the return value
    return 0;
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

Target::Target(double size, double position): size(size), position(position) {
    shape = sf::RectangleShape(sf::Vector2f(static_cast<float>(size), static_cast<float>(size)));
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(static_cast<float>(position), 0);
}

void Target::update() {}

void Target::draw(sf::RenderWindow &window) {
    window.draw(shape);
}














