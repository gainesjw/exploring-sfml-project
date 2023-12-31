#include "enemy.h"
#include "iostream"
namespace Enemy
{
    Enemy::Enemy(World::World& world) : Entity::Entity(Configuration::Configuration::Textures::Enemy, world)
                        ,_isMoving(false)
                        ,_rotation(0)
    {   
        sf::Vector2f length(0, -100);
        sf::Vector2f end;
        end = _sprite.getPosition() + length;
        std::pair vision(_sprite.getPosition(), end);

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
        //std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const int choiceList[3] = {0, 0, 1};
        const int moveList[2] = {0, 1};
        int randRotation = rand() % 3;
        int randMovement = rand() % 2;

        _rotation = choiceList[2];
        _isMoving = moveList[0];

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

    //void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const override
    //{
    //    target.draw(_sprite, states);
        //for(Detect::Detect& _detector : _detectors)
        //{
        //      target.draw(_detector, states);
        //} 
    //}

    Detect::DetectTarget<Detect::Detect> Enemy::_detectors;
}