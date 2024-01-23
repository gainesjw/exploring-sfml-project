#include "quadtree.h"

namespace Quadtree
{
    Quadtree::Quadtree()
    {
        topLeft = sf::Vector2f(0.f, 0.f);
        botRight = sf::Vector2f(0.f, 0.f);

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    Quadtree::Quadtree(sf::Vector2f topL, sf::Vector2f botR)
    {
        topLeft = topL;
        botRight = botR;

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    void Quadtree::insert(Entity::Entity* _entity)
    {
        printf("1\n");
        if(_entity == NULL) return;
        printf("2\n");
        if(!inBoundary(_entity)) return;
        printf("3\n");
        if( abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1)
        {
            if(_entities.empty())
                _entities.push_back(_entity);
            return;
        }

        if( (topLeft.x + botRight.x) / 2 >= _entity->getPosition().x )
        {
            // Top Left
            if( (topLeft.y + botRight.y) / 2 >= _entity->getPosition().x )
            {    if(tlQuadtree == NULL)
                    tlQuadtree = new Quadtree(
                        topLeft,
                        sf::Vector2f((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2));
                    tlQuadtree->insert(_entity);
            }
            // Bot Left
            else {
                if(blQuadtree == NULL)
                    blQuadtree = new Quadtree(
                        sf::Vector2f(topLeft.x, (topLeft.y + botRight.y) / 2),
                        sf::Vector2f((topLeft.x + botRight.x) / 2, botRight.y));
                    blQuadtree->insert(_entity);
            }
        }
        else 
        {
            // Top Right
            if( (topLeft.y + botRight.y) / 2 >= _entity->getPosition().y )
            {    if(trQuadtree == NULL)
                    trQuadtree = new Quadtree(
                        sf::Vector2f((topLeft.x + botRight.x) / 2, topLeft.y),
                        sf::Vector2f(botRight.x, (topLeft.y + botRight.y) / 2));
                    trQuadtree->insert(_entity);
            }
            // Bottom Right
            else {
                if(brQuadtree == NULL)
                {    brQuadtree = new Quadtree(
                        sf::Vector2f((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2),
                        sf::Vector2f(botRight.x, botRight.y));
                    brQuadtree->insert(_entity);
                }
            }
        }
        printf("Entity Stored!\n");
    }

    bool Quadtree::inBoundary(Entity::Entity* _entity)
    {
        return (_entity->getPosition().x >= topLeft.x && _entity->getPosition().x <= botRight.x
                && _entity->getPosition().y <= topLeft.y && _entity->getPosition().y >= botRight.y);
    }

    void Quadtree::update()
    {
        if(_entities.empty())
        {
            printf("Empty List!\n");
            return;
        }

        printf("Filled list!\n");

        tlQuadtree->update();
        trQuadtree->update();
        blQuadtree->update();
        brQuadtree->update();

        /*if(_entities.size() <= objMaxSize) 
        {   printf("Adding entity!");
            Sensing::SensorManager SensorManager;
            SensorManager.update(_entities);
        }*/
    }
}