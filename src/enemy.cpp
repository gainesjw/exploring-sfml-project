#include "enemy.h"
#include "random.h"
namespace Enemy
{
    Enemy::Enemy(World::World& world) : Entity::Entity(Configuration::Configuration::Textures::Enemy, world)
                        ,_isMoving(false)
                        ,_rotation(0)
    {   
        sf::Vector2f _frontLength(0.001, -100); // bug to bounding shape does not recognize completely vertical lines
        sf::Vector2f _frontEnd;
        _frontEnd = _sprite.getPosition() + _frontLength;
        std::pair _frontVision(_sprite.getPosition(), _frontEnd);

        Detect::Detect* _frontDetector =  new Detect::Detect(_frontVision);
        _detectors.attach(0, _frontDetector);

        sf::Vector2f _leftLength(-70.7, -70.7);
        sf::Vector2f _leftEnd;
        _leftEnd = _sprite.getPosition() + _leftLength;
        std::pair _leftVision(_sprite.getPosition(), _leftEnd);

        Detect::Detect* _leftDetector = new Detect::Detect(_leftVision);
        _detectors.attach(45, _leftDetector);

        sf::Vector2f _rightLength(70.7, -70.7);
        sf::Vector2f _rightEnd;
        _rightEnd = _sprite.getPosition() + _rightLength;
        std::pair _rightVision(_sprite.getPosition(), _rightEnd);

        Detect::Detect* _rightDetector = new Detect::Detect(_rightVision);
        _detectors.attach(-45, _rightDetector);
    }

    void Enemy::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
    }

    void Enemy::update(sf::Time deltaTime)
    {
        const int choiceList[3] = {-1, 0, 1};
        const int moveList[2] = {0, 1};
        int randRotation = Random::random(0, 2);
        int randMovement = Random::random(0, 1);

        _rotation = choiceList[randRotation];
        _isMoving = moveList[randMovement];

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