
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *    Do NOT alter ANYTHING below THIS COMMENT.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strImage) {
    sf::Texture CTexture;
    if(!CTexture.loadFromFile("View/Image/" + strImage)) {
        std::cout << "[ERROR] : Image failed to load." << std::endl;
    }
    this->setTexture(CTexture);
}

void GameObject::setTexture(sf::Texture CTexture) {
    this->CTexture = CTexture;
    this->imgSprite.setTexture(this->CTexture);
}

sf::Sprite* GameObject::getSprite() {
    return &this->imgSprite;
}

int GameObject::getX() {
    return this->imgSprite.getGlobalBounds().left;
}

int GameObject::getY() {
    return this->imgSprite.getGlobalBounds().top;
}

int GameObject::getWidth() {
    return this->imgSprite.getGlobalBounds().width;
}

int GameObject::getHeight() {
    return this->imgSprite.getGlobalBounds().height;
}
