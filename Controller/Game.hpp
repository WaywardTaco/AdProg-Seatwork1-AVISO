#pragma once

#include "../Model/Foreground.hpp"
#include "../Model/GameObject.hpp"

namespace controllers {
    using namespace models; 
    class Game {
        private:
            sf::RenderWindow CWindow;
            GameObject CBackground;
            bool bReset;
            
            /* [TODO][1] :
             * Place [Foreground] field(s) here, each representing
             * images [1] to [4]. You may choose to create a
             * separate field for each [Foreground] object, or use
             * a single compound data type (e.g. vector, hash map,
             * etc.). */
            std::vector<Foreground*> vecElements;
            
        public:
            Game();

        public:
            void run();

        private:
            void processEvents();
            void update();
            void render();

            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);
    };
}
