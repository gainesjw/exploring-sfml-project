#include "configuration.h"

namespace Configuration
{
    ResourceManager::ResourceManager<sf::Texture, int> Configuration::textures;
    Action::ActionMap<int> Configuration::player_inputs;

    void Configuration::initialize()
    {
        initTextures();
        initPlayerInputs();
    }

    void Configuration::initTextures()
    {
        textures.load(Textures::Player, "media/Player/Ship.png");
        textures.load(Textures::Enemy, "media/Enemy/Ship.png");
    }

    void Configuration::initPlayerInputs()
    {
        player_inputs.map(PlayerInputs::Up, Action::Action(sf::Keyboard::Up));
        player_inputs.map(PlayerInputs::Right, Action::Action(sf::Keyboard::Right));
        player_inputs.map(PlayerInputs::Left, Action::Action(sf::Keyboard::Left));
    }

}