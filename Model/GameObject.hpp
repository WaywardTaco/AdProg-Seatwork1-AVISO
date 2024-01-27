
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *    Do NOT alter ANYTHING below THIS COMMENT.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

namespace models {
    class GameObject {
        protected:
            sf::Texture CTexture;
            sf::Sprite imgSprite;

        public:
            /* The constructor for this class. It accepts a [strImage]
             * parameter that is loaded and set as its sprite texture. */
            GameObject(std::string strImage);
        
        public:
            /* Setter for the [CTexture] field. It also sets the
             * [imgSprite] field's texture. */
            void setTexture(sf::Texture CTexture);
            
            /* Getter for the [imgSprite] field's address. */
            sf::Sprite* getSprite();
            
            /* Getter for [imgSprite]'s [x] position. */
            int getX();
            
            /** Getter for [imgSprite]'s [y] position. */
            int getY();

            /* Getter for [imgSprite]'s [width] dimension. */
            int getWidth();

            /* Getter for [imgSprite]'s [height] dimension. */
            int getHeight();
    };
}
