#include "game.h"

namespace Game
{
    Game::Game() : _window(sf::VideoMode(1200, 800), "project_002")
    {
        _player.setPosition(600, 400);
        _enemy.setPosition(sf::Vector2f(600, 400));
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
        _enemy.processEvents();
        _player.processEvents();
    }

    void Game::update(sf::Time deltaTime)
    {
        _enemy.update(deltaTime);
        _player.update(deltaTime);
    }

    void Game::render()
    {
        _window.clear();
        _window.draw(_enemy);
        _window.draw(_player);
        _window.display();
    }
}