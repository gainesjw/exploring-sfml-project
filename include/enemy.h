#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <utility>
//#include "detect.h"
#include "configuration.h"
#include "entity.h"

namespace Enemy 
{
    class Enemy : public Entity::Entity
    {
        public:
            Enemy(const Enemy&) = delete;
            Enemy& operator=(const Enemy&) = delete;

            Enemy(World::World& world);

            void processEvents();
            virtual void update(sf::Time deltaTime) override;

        private:
            bool _isMoving;
            int _rotation;
    };
}

#endif