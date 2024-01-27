
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *    Do NOT alter ANYTHING below THIS COMMENT.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Foreground.hpp"

using namespace models;

Foreground::Foreground(std::string strImage) : GameObject(strImage) {
    this->bMoving = false;
}

void Foreground::reset() {
    this->imgSprite.setPosition(this->vecInitialPosition);
}

bool Foreground::getMoving() {
    return this->bMoving;
}

void Foreground::setMoving(bool bMoving) {
    this->bMoving = bMoving;
}

sf::Vector2f Foreground::getTargetPosition() {
    return this->vecTargetPosition;
}

void Foreground::setTargetPosition(sf::Vector2f vecTargetPosition) {
    this->vecTargetPosition = vecTargetPosition;
}

void Foreground::setInitialPosition(sf::Vector2f vecInitialPosition) {
    this->vecInitialPosition = vecInitialPosition;
}
