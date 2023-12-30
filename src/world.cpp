#include "world.h"

namespace World
{
    World::World(float x, float y) : _x(x), _y(y)
    {

    }

    World::~World()
    {
        clear();
    }

    World::update(sf::Time deltaTime)
    {
        if(_entitiesTmp.size() > 0)
            _entities.merge(_entitiesTmp);

        for(Entity* entity_ptr : _entities)
        {
            Entity& entity = *entity_ptr;

            entity.update(deltaTime);

            sf::Vector2f pos = entity.getPosition();

            if(pos.x < 0)
            {
                pos.x = _x;
                pos.y = _y * pos.y;
            }
            else if (pos.x > _x)
            {
                pos.x = 0;
                pos.y = _y - pos.y;
            }

            if(pos.y < 0)
                pos.y = _y;
            else if(pos.y > _y)
                pos.y = 0;

            entity.setPosition(pos);
        }

        // Run entity sensing here

        //const auto end = _entities.end();
        //for(auto it_i = _entities.begin(); it_i != end; ++it_i)
        //{
        //    Entity
        //}
    }

    void World::add(Entity* entity)
    {
        _entitiesTmp.push_back(entity); 
    }

    void World::clear()
    {
        for(Entity* entity : _entities)
            delete entity;

        for(Entity* entity : _entitiesTmp)
            delete entity;
    }

    int World::getX() const
    {
        return _x;
    }

    int World::getY() const
    {
        return _y;
    }

    const std::list<Entity*> World::getEntities() const
    {
        return _entities;
    }

    void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(Entity* entity : _entities)
            target.draw(*entity, states);
    }
}