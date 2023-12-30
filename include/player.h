#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include "configuration.h"
#include "entity.h"

namespace Player {

    class Player : public Entity::Entity
                   ,public Action::ActionTarget<int> 
    {
        public:
            Player(const Player&) = delete;
            Player& operator=(const Player&) = delete;

            Player(Entity& world);

            void processEvents();
            virtual void update(sf::Time deltaTime);

            enum PlayerInputs {Up,Left,Right};

        private:
            bool _isMoving;
            int _rotation;

            static Action::ActionMap<int> _playerInputs;
    };

}

#endif