#ifndef __WORLD_H__
#define __WORLD_H__

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include "configuration.h"
#include "entity.h"

namespace World
{

    class World : public sf::Drawable
    {
        public:
            World(const World&) = delete;
            World& operator=(const World&) = delete;

            World(float x, float y);
            ~World(); 

            void update(sf::Time deltaTime);
            void add(Entity::Entity* entity);
            void clear();

            int size();

            int getX() const;
            int getY() const;

            const std::list<Entity::Entity*> getEntities() const;

        private:
            std::list<Entity::Entity*> _entities;
            std::list<Entity::Entity*> _entitiesTmp;

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            const int _x;
            const int _y;
    };
}
#endif