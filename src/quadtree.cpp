#include "quadtree.h"

namespace Quadtree
{
    Quadtree::Quadtree()
    {
        topLeft = sf::Vector2f(0.f, 0.f);
        botRight = sf::Vector2f(3200.f, 3200.f);

        _shape.setPrimitiveType(sf::LineStrip);
        _shape.resize(4);
        _shape[0].position = topLeft;
        _shape[1].position = sf::Vector2f(botRight.x, topLeft.y);
        _shape[2].position = botRight;
        _shape[3].position = sf::Vector2f(topLeft.x, botRight.y);

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    Quadtree::Quadtree(sf::Vector2f topL, sf::Vector2f botR)
    {
        topLeft = topL;
        botRight = botR;

        _shape.setPrimitiveType(sf::LineStrip);
        _shape.resize(4);
        _shape[0].position = topL;
        _shape[1].position = sf::Vector2f(botR.x, topL.y);
        _shape[2].position = botR;
        _shape[3].position = sf::Vector2f(topL.x, botR.y);

        tlQuadtree = NULL;
        trQuadtree = NULL;
        blQuadtree = NULL;
        brQuadtree = NULL;
    }

    void Quadtree::insert(Entity::Entity* _entity)
    {
        //printf("1\n");
        if(_entity == NULL) return;
        //printf("2\n");
        if(!inBoundary(_entity)) return;
        //printf("3\n");
        if( abs(topLeft.x - botRight.x) <= 25 && abs(topLeft.y - botRight.y) <= 25) return;

        if(_entities.size() <= objMaxSize)
        {
            _entities.push_back(_entity);
            return;
        }

        if( (topLeft.x + botRight.x) / 2 >= _entity->getPosition().x )
        {
            // Top Left
            if( (topLeft.y + botRight.y) / 2 >= _entity->getPosition().y )
            {   if(tlQuadtree == NULL)
                    tlQuadtree = new Quadtree(
                        topLeft,
                        sf::Vector2f((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2));
                tlQuadtree->insert(_entity);
                //printf("Entity Stored tl!\n");
            } else {    
                // Bot Left
                if(blQuadtree == NULL)
                    blQuadtree = new Quadtree(
                        sf::Vector2f(topLeft.x, (topLeft.y + botRight.y) / 2),
                        sf::Vector2f((topLeft.x + botRight.x) / 2, botRight.y));
                blQuadtree->insert(_entity);
                //printf("Entity Stored bl!\n");
            }
        } else {
            // Top Right
            if( (topLeft.y + botRight.y) / 2 >= _entity->getPosition().y )
            {   if(trQuadtree == NULL)
                    trQuadtree = new Quadtree(
                        sf::Vector2f((topLeft.x + botRight.x) / 2, topLeft.y),
                        sf::Vector2f(botRight.x, (topLeft.y + botRight.y) / 2));
                trQuadtree->insert(_entity);
                //printf("Entity Stored tr!\n");
            } else {   
                // Bottom Right
                if(brQuadtree == NULL)
                    brQuadtree = new Quadtree(
                        sf::Vector2f((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2),
                        sf::Vector2f(botRight.x, botRight.y));
                brQuadtree->insert(_entity);
                //printf("Entity Stored br!\n");
            }
        }
    }

    bool Quadtree::inBoundary(Entity::Entity* _entity)
    {
        return (_entity->getPosition().x >= topLeft.x && _entity->getPosition().x <= botRight.x
                && _entity->getPosition().y >= topLeft.y && _entity->getPosition().y <= botRight.y);
    }

    void Quadtree::update()
    {
        if(tlQuadtree != NULL) tlQuadtree->update();
        if(trQuadtree != NULL) trQuadtree->update();
        if(blQuadtree != NULL) blQuadtree->update();
        if(brQuadtree != NULL) brQuadtree->update();

        //printf("Sensing entities!\n");
        Sensing::SensorManager SensorManager;
        SensorManager.update(_entities);

        /*if(!_entities.empty()) //return
        {
             _entities.clear();
            //printf("Flush List!\n");
        }*/
    }

    void Quadtree::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if(tlQuadtree != NULL) tlQuadtree->draw(target, states);
        if(trQuadtree != NULL) trQuadtree->draw(target, states);
        if(blQuadtree != NULL) blQuadtree->draw(target, states);
        if(brQuadtree != NULL) brQuadtree->draw(target, states);

        target.draw(_shape, states);
    }

    void Quadtree::reset()
    {
        if(tlQuadtree != NULL) tlQuadtree->reset();
        delete tlQuadtree;
        tlQuadtree = NULL;

        if(trQuadtree != NULL) trQuadtree->reset();
        delete trQuadtree;
        trQuadtree = NULL;

        if(blQuadtree != NULL) blQuadtree->reset();
        delete blQuadtree;
        blQuadtree = NULL;

        if(brQuadtree != NULL) brQuadtree->reset();
        delete brQuadtree;
        brQuadtree = NULL;

        if(_entities.size() > 0)
            printf("lots\n");
            /*for (auto entityPtr : _entities) 
            {
                delete entityPtr;
            }*/
    }
}