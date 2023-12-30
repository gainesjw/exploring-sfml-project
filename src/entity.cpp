#include  "entity.h"

namespace Entity
{
    Entity::Entity(Configuration::Configuration::Textures texture_id, World& world) : _world(world)
    {
        sf::Texture& texture = Configuration::Configuration::textures.get(texture_id);
        _sprite.setTexture(texture);
        _sprite.setOrigin(texture.getSize().x/2.f, texture.getSize().y/2.f);
    }

    Entity::~Entity()
    {

    }

    const sf::Vector2f& Entity::getPosition() const
    {
        return _sprite.getPosition();
    }

    void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    }

}