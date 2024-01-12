#include "game.h"
#include "random.h"

namespace Game
{
    Game::Game(int x, int y) : _window(sf::VideoMode(x, y), "project_002"), _world(x, y)
    {

    }

    void Game::run(int minimumFPS)
    {
        sf::Clock   clock;
        sf::Time    timeSinceLastUpdate;
        sf::Time    TimePerFrame = sf::seconds(1.f / minimumFPS);

        while(_window.isOpen())
        {
            processEvents();
            timeSinceLastUpdate = clock.restart();
            while(timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;
                update(TimePerFrame);
            }

            update(timeSinceLastUpdate);
            render();
        }
    }

    void Game::processEvents()
    {
        sf::Event event;
        while(_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                _window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    _window.close();
            }
        }
        if(Configuration::Configuration::player != nullptr)
            Configuration::Configuration::player->processEvents();
    }

    void Game::update(sf::Time deltaTime)
    {
        Random::rand_init();

        _world.update(deltaTime);

        if(_world.size() <= 1)
        {
            Enemy::Enemy* enemy = new Enemy::Enemy(_world);
            enemy->setPosition(Random::random(0.f,(float)_world.getX()),Random::random(0.f,(float)_world.getY()));
            _world.add(enemy);
        }

        if(Configuration::Configuration::player == nullptr)
        {
            Configuration::Configuration::player = new Player::Player(_world);
            Configuration::Configuration::player->setPosition(_world.getX()/2,_world.getY()/2);
            _world.add(Configuration::Configuration::player);
        }
    }

    void Game::render()
    {
        _window.clear();
        _window.draw(_world);
        _window.display();
    }
}