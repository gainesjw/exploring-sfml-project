#include "configuration.h"


namespace Configuration
{
    ResourceManager::ResourceManager<sf::Texture, int> Configuration::textures;
    Action::ActionMap<int> Configuration::player_inputs;

    Player::Player* Configuration::Configuration::player = nullptr;

    void Configuration::initialize()
    {
        initTextures();
        initPlayerInputs();
    }

    void Configuration::initTextures()
    {
        std::string exeDirectory = GetExecutableDirectory();
        //std::cout << "Executable path: " << exeDirectory << std::endl;

        textures.load(Textures::Player, exeDirectory + "/media/Player/Ship.png");
        textures.load(Textures::Enemy,  exeDirectory + "/media/Enemy/Ship.png");
    }

    void Configuration::initPlayerInputs()
    {
        player_inputs.map(PlayerInputs::Up, Action::Action(sf::Keyboard::Up));
        player_inputs.map(PlayerInputs::Right, Action::Action(sf::Keyboard::Right));
        player_inputs.map(PlayerInputs::Left, Action::Action(sf::Keyboard::Left));
    }

    std::string GetExecutableDirectory()
    {
        char fullPath[PATH_MAX];
        uint32_t size = sizeof(fullPath);
        if (_NSGetExecutablePath(fullPath, &size) == 0) {
            // Extract the directory from the full path
            std::string exePath = fullPath;
            size_t lastSlash = exePath.find_last_of("/");
            return exePath.substr(0, lastSlash);
        }
        return "";
    }

}