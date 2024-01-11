#include "sensing.h"

namespace Sensing
{
    void SensorManager::update(std::list<Entity::Entity*> _entities)
    {
        // Update detectors for each object
        const std::list<Entity::Entity*>::iterator endIter = _entities.end();
        for(std::list<Entity::Entity*>::iterator entityAIter = _entities.begin(); entityAIter != endIter; ++entityAIter)
        {
            Entity::Entity* entityAptr = *entityAIter;

            for(std::list<Entity::Entity*>::iterator entityBIter = _entities.begin(); entityAIter != endIter || entityAIter != entityBIter; ++entityBIter)
            {
                Entity::Entity* entityB = *entityBIter;

                //sense(entityA&, entityB&);
                printf("OK");
            }
        }
    }

    void SensorManager::sense(Entity::Entity& targetEntity, Entity::Entity& foreignEntity)
    {
        std::vector<std::pair<float, Detect::Detect>> _sensorMap = targetEntity.getDetectors();

        for(std::pair<float, Detect::Detect> _sensor : _sensorMap)
        {
            printf("OK");
        }
    }
}