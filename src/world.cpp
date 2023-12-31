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

    void World::update(sf::Time deltaTime)
    {
        if(_entitiesTmp.size() > 0)
            _entities.merge(_entitiesTmp);

        for(Entity::Entity* entity_ptr : _entities)
        {
            Entity::Entity& entity = *entity_ptr;

            entity.update(deltaTime);

            sf::Vector2f pos = entity.getPosition();

            if(pos.x < 0)
            {
                pos.x = _x;
                pos.y = _y - pos.y;
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

    void World::add(Entity::Entity* entity)
    {
        _entitiesTmp.push_back(entity); 
    }

    void World::clear()
    {
        for(Entity::Entity* entity : _entities)
            delete entity;

        for(Entity::Entity* entity : _entitiesTmp)
            delete entity;
    }

    int World::size()
    {
        return _entities.size() + _entitiesTmp.size();
    }

    int World::getX() const
    {
        return _x;
    }

    int World::getY() const
    {
        return _y;
    }

    const std::list<Entity::Entity*> World::getEntities() const
    {
        return _entities;
    }

    void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(Entity::Entity* entity : _entities)
            target.draw(*entity, states);
    }
}