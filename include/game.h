#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "player.h"
#include "enemy.h"

namespace Game
{
    class Game
    {
        public:
            Game(const Game&) = delete;
            Game& operator=(const Game&) = delete;

            Game();

            void run(int minimumFPS);

        private:
            void processEvents();
            void update(sf::Time deltaTime);
            void render();

            sf::RenderWindow _window;
            Player::Player _player;
            Enemy::Enemy _enemy;

    };
} 

#endif