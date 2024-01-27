#include "Game.hpp"

using namespace controllers;

Game::Game() : CWindow(sf::VideoMode(1280, 720), "Josiah Kurt B. Aviso", sf::Style::Titlebar | sf::Style::Close),
               CBackground("image_0.png"),
               vecElements({
                    new Foreground("image_1.png"),
                    new Foreground("image_2.png"),
                    new Foreground("image_3.png"),
                    new Foreground("image_4.png")
               }) {
    this->bReset = false;

    /* [TODO][2] :
     * Initialize 4 [Foreground] objects here, with
     * their appropriate Textures (i.e. images.).
     * 
     * [IMPORTANT] :
     * Only pass the image name (with the extension) to
     * [Foreground]'s parameter. Do NOT include the entire
     * path. The actual texture loading is done in
     * [GameObject]'s constructor. */

    // In initializer list

    /* [TODO][3] :
     * Set the sprite positions of the previously initialized
     * [Foreground] images such that they are just outside of
     * the window. Each position SHOULD also be passed as
     * the values in each [Foreground]'s [setInitialPosition()].
     * 
     * Then, pass the correct (i.e. final) position of each
     * [Foreground] image in [setTargetPosition()].
     * 
     * Refer to the lecture explanations.
     * 
     * [IMPORTANT] :
     * You must properly use the [getX()], [getY()], [getWidth()],
     * and [getHeight()] functions of [Foreground]. in your
     * solution. */
    this->vecElements[0]->setInitialPosition({0.f, -static_cast<float>(this->vecElements[0]->getHeight())});
    this->vecElements[1]->setInitialPosition({0.f, static_cast<float>(this->CWindow.getSize().y)});
    this->vecElements[2]->setInitialPosition({static_cast<float>(this->CWindow.getSize().x), 0.f});
    this->vecElements[3]->setInitialPosition({-static_cast<float>(this->vecElements[3]->getWidth()), 0.f});
 
    int iElementCount = this->vecElements.size();
    for(int i = 0; i < iElementCount; i++){
        this->vecElements[i]->reset();
    }
 
    this->vecElements[0]->setTargetPosition({0.f, 0.f});
    this->vecElements[1]->setTargetPosition({0.f, static_cast<float>(this->CWindow.getSize().y - this->vecElements[1]->getHeight())});
    this->vecElements[2]->setTargetPosition({static_cast<float>(this->CWindow.getSize().x - this->vecElements[2]->getWidth()), 0.f});
    this->vecElements[3]->setTargetPosition({0.f, 0.f});
}

void Game::run() {
    while (this->CWindow.isOpen()) {
        this->processEvents();
        this->update();
        this->render();
    }
}

void Game::processEvents() {
    sf::Event CEvent;
    while(this->CWindow.pollEvent(CEvent)) {
        switch(CEvent.type) {
            case sf::Event::Closed:
                this->CWindow.close();
                break;

            case sf::Event::KeyPressed:
                this->processKeyboardInput(CEvent.key.code, true);
                break;

            case sf::Event::KeyReleased:
                this->processKeyboardInput(CEvent.key.code, false);
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    if(this->bReset) {
        /* [TODO][7] :
         * Call the [reset()] of ALL [Foreground] objects here. */
        int iElementCount = this->vecElements.size();
        for(int i = 0; i < iElementCount; i++){
            this->vecElements[i]->reset();
        }

        this->bReset = false;
    }

    /* [TODO][6] :
     * When a certain [Foreground]'s flag is TRUE, move it
     * towards its target position by [1] pixel. If a given
     * [Foreground] is already in its target position, don't
     * allow it to move anymore. Do NOT allow any [Foreground]
     * to go past their target position.
     * 
     *      - [image_1.png] travels DOWN.
     *      - [image_2.png] travels UP.
     *      - [image_3.png] travels LEFT.
     *      - [image_4.png] travels RIGHT. */
    if(this->vecElements[0]->getMoving() && 
        this->vecElements[0]->getSprite()->getPosition() != this->vecElements[0]->getTargetPosition()){
            this->vecElements[0]->getSprite()->move({0.f, 1.f});
        }
    
    if(this->vecElements[1]->getMoving() && 
        this->vecElements[1]->getSprite()->getPosition() != this->vecElements[1]->getTargetPosition()){
            this->vecElements[1]->getSprite()->move({0.f, -1.f});
        }
    
    if(this->vecElements[2]->getMoving() && 
        this->vecElements[2]->getSprite()->getPosition() != this->vecElements[2]->getTargetPosition()){
            this->vecElements[2]->getSprite()->move({-1.f, 0.f});
        }
    
    if(this->vecElements[3]->getMoving() && 
        this->vecElements[3]->getSprite()->getPosition() != this->vecElements[3]->getTargetPosition()){
            this->vecElements[3]->getSprite()->move({1.f, 0.f});
        }
}

void Game::render() {
    this->CWindow.clear();
    this->CWindow.draw(*this->CBackground.getSprite());

    /* [TODO][4] : Render necessary sprites here. */
    int iElementCount = this->vecElements.size();
    for(int i = 0; i < iElementCount; i++){
        this->CWindow.draw(*this->vecElements[i]->getSprite());
    }
    
    this->CWindow.display();
}

void Game::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    /* [TODO][5] :
     * Add cases to [switch()] so that it detects the keys below.
     * It must also set the correct flags for each [Foreground]
     * objec, based on the keyboard inputs.
     *      - [W] sets the FLAG for [image_2.png]
     *      - [A] sets the FLAG for [image_3.png]
     *      - [S] sets the FLAG for [image_1.png]
     *      - [D] sets the FLAG for [image_4.png] */

    switch(CKey) {
        case sf::Keyboard::Space:
            this->bReset = bPressed;
            break;

        case sf::Keyboard::W:
            this->vecElements[1]->setMoving(bPressed);
            break;

        case sf::Keyboard::A:
            this->vecElements[2]->setMoving(bPressed);
            break;

        case sf::Keyboard::S:
            this->vecElements[0]->setMoving(bPressed);
            break;

        case sf::Keyboard::D:
            this->vecElements[3]->setMoving(bPressed);
            break;

        default:
            break;
    }
}
