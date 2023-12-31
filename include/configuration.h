#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "action.h"
#include "resourcemanager.h"
#include "detect.h"

namespace Player 
{
    class Player;
}

namespace Configuration 
{

    class Configuration
    {
        public:
            Configuration(const Configuration&) = delete;
            Configuration& operator=(const Configuration&) = delete;

            Configuration() = delete;

            enum Textures : int {Player,Enemy};
            static ResourceManager::ResourceManager<sf::Texture, int> textures;

            enum PlayerInputs : int {Up,Left,Right};
            static Action::ActionMap<int> player_inputs;

            static Player::Player* player;

            static void initialize();

        private:
            static void initTextures();
            static void initPlayerInputs();
    };
}

#endif