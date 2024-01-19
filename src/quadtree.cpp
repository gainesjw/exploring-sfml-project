#include "quadtree.h"

namespace Quadtree
{
    Quadtree::Quadtree()
    {
        xBound = sf::Vector2f(0f, 0f);
        yBound = sf::Vector2f(0f, 0f);

        _entities = NULL;

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    Quadtree::Quadtree(sf::Vector2f topL. sf::Vector2f botR)
    {
        topLeft = topL;
        botRight = botR;

        _entities = NULL;

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    void Quadtree::insert(Entity::Entity* _entity)
    {
        if(_entity == NULL) return;

        if(!inBoundary(_entity->getPosition())) return;

        if( abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1)
        {
            if(_entities == NULL)
                _entities.push_back(Entity);
            return;
        }

        if( (topLeft.x + botRight.x) / 2 >= _entity->getPosition().x )
            if( (topLeft.y + botRight.y) / 2 >= _entity->getPosition().x )
                if(tlQuadtree == NULL)
                    tlQuadtree = new Quadtree(
                        topLeft,
                        sf::Vector2f((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2));
                    tlQuadtree->insert(_entity);
    }
}