#include "enemy.h"
#include "iostream"
namespace Enemy
{
    Enemy::Enemy(World::World& world) : Entity::Entity(Configuration::Configuration::Textures::Enemy, world)
                        ,_isMoving(false)
                        ,_rotation(0)
    {   
        sf::Vector2f _frontLength(0, -100);
        sf::Vector2f _frontEnd;
        _frontEnd = _sprite.getPosition() + _frontLength;
        std::pair _frontVision(_sprite.getPosition(), _frontEnd);

        Detect::Detect _frontDetector(_frontVision);
        _detectors.attach(0, _frontDetector);

        sf::Vector2f _leftLength(-70.7, -70.7);
        sf::Vector2f _leftEnd;
        _leftEnd = _sprite.getPosition() + _leftLength;
        std::pair _leftVision(_sprite.getPosition(), _leftEnd);

        Detect::Detect _leftDetector(_leftVision);
        _detectors.attach(45, _leftDetector);

        sf::Vector2f _rightLength(70.7, -70.7);
        sf::Vector2f _rightEnd;
        _rightEnd = _sprite.getPosition() + _rightLength;
        std::pair _rightVision(_sprite.getPosition(), _rightEnd);

        Detect::Detect _rightDetector(_rightVision);
        _detectors.attach(-45, _rightDetector);
    }

    void Enemy::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
    }

    void Enemy::update(sf::Time deltaTime)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const int choiceList[3] = {0, 0, 1};
        const int moveList[2] = {0, 1};
        int randRotation = rand() % 3;
        int randMovement = rand() % 2;

        _rotation = choiceList[randRotation];
        _isMoving = moveList[randMovement];

        //std::cout << _rotation << std::endl;

        float seconds = deltaTime.asSeconds();
        if(_rotation != 0)
        {
            float angle = _rotation * 180 * seconds;
            _sprite.rotate(angle);
            _detectors.rotate(angle);
        }
        if(_isMoving)
        {
            float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
            _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
        }
        _sprite.move(seconds * _velocity);
        _detectors.move(seconds * _velocity);
    }
}