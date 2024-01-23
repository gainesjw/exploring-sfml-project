#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <SFML/Graphics.hpp>
#include <list>
#include <cmath>
#include "entity.h"
#include "sensing.h"

namespace Quadtree
{
    class Quadtree
    {
        public:
            Quadtree();
            Quadtree(sf::Vector2f topL, sf::Vector2f botR);

            int objMaxSize = 100;
            std::list<Entity::Entity*> _entities;

            sf::Vector2f topLeft;
            sf::Vector2f botRight;

            void insert(Entity::Entity* _entity);
            //_entities* search(Entity::Entity _entity);
            bool inBoundary(Entity::Entity* _entity);
            void update();

        private:
            Quadtree* tlQuadtree;
            Quadtree* trQuadtree;
            Quadtree* blQuadtree;
            Quadtree* brQuadtree;

    };
}

#endif