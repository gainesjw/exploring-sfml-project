#ifndef __SENSING__H__
#define __SENSING__H__

#include "entity.h"
#include "detect.h"

namespace Sensing
{
    class SensorManager
    {
        public:
            SensorManager(const SensorManager&) = delete;
            SensorManager& operator=(const SensorManager&) = delete;
            SensorManager() = default;

            void update(std::list<Entity::Entity*> _entities);
            void sense(Entity::Entity& targetEntity, Entity::Entity& foreignEntity);
            //const Detect& get(const int& agentlisting);
    };
}


#endif