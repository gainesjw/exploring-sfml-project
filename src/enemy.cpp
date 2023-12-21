#include "enemy.h"
#include <iostream>
namespace Enemy
{
    Enemy::Enemy() :    _isMoving(false)
                        ,_rotation(0)
    {   
        _ship.setTexture(Configuration::Configuration::textures.get(Configuration::Configuration::Textures::Enemy));
        _ship.setOrigin(49.5,37.5);

        sf::Vector2f length(0, -100);
        sf::Vector2f end;
        end = _ship.getPosition() + length;
        std::pair vision(_ship.getPosition(), end);

        Detect::Detect forwardDetector(vision);
        _detectors.attach(0, forwardDetector);
    }

    void Enemy::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
    }

    void Enemy::update(sf::Time deltaTime)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const int choiceList[3] = {0, 0, -1};
        const int moveList[2] = {0, 1};
        int randRotation = rand() % 3;
        int randMovement = rand() % 2;

        _rotation += choiceList[randRotation];
        _isMoving += moveList[randMovement];

        float seconds = deltaTime.asSeconds();
        if(_rotation != 0)
        {
            float angle = _rotation * 180 * seconds;
            _ship.rotate(angle);
            _detectors.rotate(angle);
        }
        if(_isMoving)
        {
            float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;
            _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
        }
        _ship.move(seconds * _velocity);
        _detectors.move(seconds * _velocity);
    }

    void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_ship, states);
        target.draw(_detectors.getDetectors()[0].second.getDetector(), states);
    }

    Detect::DetectTarget<Detect::Detect> Enemy::_detectors;
}