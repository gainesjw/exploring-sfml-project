#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>
#include "configuration.h"
#include <ctime>
#include <cstdlib>

namespace Enemy 
{
    class Enemy : public sf::Drawable
    {
        public:
            Enemy(const Enemy&) = delete;
            Enemy& operator=(const Enemy&) = delete;

            Enemy();

            void processEvents();
            void update(sf::Time deltaTime);


        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            sf::Sprite      _ship;
            sf::Vector2f    _velocity;

            bool _isMoving;
            int _rotation;
    };
}

#endif