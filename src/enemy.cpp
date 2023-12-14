#include "enemy.h"

namespace Enemy
{
    Enemy::Enemy() :    _isMoving(false)
                        ,_rotation(0)
    {
        _ship.setTexture(Configuration::Configuration::textures.get(Configuration::Configuration::Textures::Enemy));
        _ship.setOrigin(49.5,37.5);
    }

    void Enemy::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
    }

    void Enemy::update(sf::Time deltaTime)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const int choiceList[3] = {-1, 0, 1};
        int randRotation = rand() % 3;
        int randMovement = rand() % 3;

        _rotation += choiceList[randRotation];
        _isMoving += choiceList[randMovement];

        float seconds = deltaTime.asSeconds();
        if(_rotation != 0)
        {
            float angle = _rotation * 180 * seconds;
            _ship.rotate(angle);
        }
        if(_isMoving)
        {
            float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;
            _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
        }
        _ship.move(seconds * _velocity);
    }

    void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_ship, states);
    }
}