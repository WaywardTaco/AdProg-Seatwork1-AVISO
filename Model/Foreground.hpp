
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *    Do NOT alter ANYTHING below THIS COMMENT.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include "GameObject.hpp"

namespace models {
    class Foreground : public GameObject {
        private:
            /* Field denoting the FLAG for movement. */
            bool bMoving;
            
            /* Field denoting the initial position of [imgSprite]. */
            sf::Vector2f vecInitialPosition;

            /* Field denoting the target position of [imgSprite]. */
            sf::Vector2f vecTargetPosition;

        public:
            /* The constructor for this class. It accepts a [strImage]
             * parameter that is loaded and set as its sprite texture
             * through its parent class. */
            Foreground(std::string strImage);

        public:
            /* Resets the position of the sprite to its logged initial
             * position. */
            void reset();

        public:
            /* Getter for the [bMoving] field. */
            bool getMoving();
            
            /* Setter for the [bMoving] field. */
            void setMoving(bool bMoving);

            /* Getter for the [vecTargetPosition] field. */
            sf::Vector2f getTargetPosition();

            /* Setter for the [vecTargetPosition] field. */
            void setTargetPosition(sf::Vector2f vecTargetPosition);

            /* Setter for the [vecInitialPosition] field. */
            void setInitialPosition(sf::Vector2f vecInitialPosition);
    };
}
