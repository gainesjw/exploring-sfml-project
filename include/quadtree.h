#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <SFML/Graphics.hpp>
#include <list>
#include <cmath>
#include "entity.h"
#include "sensing.h"

namespace Quadtree
{
    class Quadtree : public sf::Drawable
    {
        public:
            Quadtree();
            Quadtree(sf::Vector2f topL, sf::Vector2f botR);

            std::list<Entity::Entity*> _entities;

            sf::Vector2f topLeft;
            sf::Vector2f botRight;

            void insert(Entity::Entity* _entity);
            bool inBoundary(Entity::Entity* _entity);
            void setShape();
            void update();
            void reset();

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        private:
            Quadtree* tlQuadtree;
            Quadtree* trQuadtree;
            Quadtree* blQuadtree;
            Quadtree* brQuadtree;

            sf::VertexArray _shape;

    };
}

#endif