#include "iostream"
#include "vector"
#include "unordered_map"
#include "SFML/Graphics.hpp"

/* [NOTE] : You may include as many [cpp] files here, as necessary. */

#include "Model/Foreground.cpp"
#include "Model/GameObject.cpp"
#include "Controller/Game.cpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *    Do NOT alter ANYTHING below THIS COMMENT.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

int main() {
    Game CGame;
    CGame.run();
    return 0;
}
