#include "player.h"

namespace Player
{
    Player::Player() :  ActionTarget(Configuration::Configuration::player_inputs)
                        ,_isMoving(false)
                        ,_rotation(0)
    {
        _ship.setTexture(Configuration::Configuration::textures.get(Configuration::Configuration::Textures::Player));
        _ship.setOrigin(49.5,37.5);

        bind(PlayerInputs::Up, [this](const sf::Event&)
        {
            _isMoving = true;
        });

        bind(PlayerInputs::Left, [this](const sf::Event&)
        {
            _rotation -= 1;
        });

        bind(PlayerInputs::Right, [this](const sf::Event&)
        {
            _rotation += 1;
        });
    }

    void Player::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
        Action::ActionTarget<int>::processEvents();
    }

    void Player::update(sf::Time deltaTime)
    {
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

    void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_ship, states);
    }

    Action::ActionMap<int> Player::_playerInputs;
}