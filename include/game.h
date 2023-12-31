#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "world.h"
#include "configuration.h"
#include "player.h"
#include "enemy.h"

namespace Game
{
    class Game
    {
        public:
            Game(const Game&) = delete;
            Game& operator=(const Game&) = delete;

            Game(int x=1600, int y=900);

            void run(int minimumFPS);

        private:
            void processEvents();
            void update(sf::Time deltaTime);
            void render();

            sf::RenderWindow _window;
            World::World _world;
    };
} 

#endif