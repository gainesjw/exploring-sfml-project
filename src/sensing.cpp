#include "sensing.h"

namespace Sensing
{
    void SensorManager::update(std::list<Entity::Entity*> _entities)
    {
        // Update detectors for each object
        for(Entity::Entity* entityA_ptr : _entities)
        {
            Entity::Entity& entityA = *entityA_ptr;

            for(Entity::Entity* entityB_ptr : _entities)
            {
                if(entityB_ptr == entityA_ptr) continue;
                Entity::Entity& entityB = *entityB_ptr;

                sense(entityA, entityB);
                //printf("OK\n");
            }
        }
    }

    void SensorManager::sense(Entity::Entity& targetEntity, Entity::Entity& foreignEntity)
    {
        std::vector<std::pair<float, Detect::Detect*>> _tgtsensorMap = targetEntity.getDetectors();

        for(std::pair<float, Detect::Detect*> _tgtsensor : _tgtsensorMap)
        {
            Detect::Detect& _tgtdetect = *_tgtsensor.second;
            sf::VertexArray _tgtdetector = _tgtdetect.getDetector();
            sf::FloatRect _tgtdetectShape = _tgtdetector.getBounds();
            sf::FloatRect _frnShape = foreignEntity.getBounds();
            _tgtdetect.setColor();
            if(_tgtdetectShape.intersects(_frnShape))
            {
                _tgtdetect.setActivity(1);
                /*std::cout << "Detector Bounds: Left = " << _tgtdetectShape.left
                << ", Top = " << _tgtdetectShape.top
                << ", Width = " << _tgtdetectShape.width
                << ", Height = " << _tgtdetectShape.height
                << " : Foreign Bounds: Left = " << _frnShape.left
                << ", Top = " << _frnShape.top
                << ", Width = " << _frnShape.width
                << ", Height = " << _frnShape.height << std::endl;*/
                break;
            }   
            //_tgtdetect.setActivity(0);

            //std::cout << _tgtdetect.getActivity() << std::endl;
        }
    }
}