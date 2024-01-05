#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"

#include <iostream>
#include <filesystem>

int main()
{
    Configuration::Configuration::initialize();
    Game::Game Game;
    Game.run(30);
}