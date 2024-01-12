#include  "entity.h"

namespace Entity
{
    Entity::Entity(Configuration::Configuration::Textures texture_id, World::World& world) : _world(world)
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

    const sf::FloatRect& Entity::getBounds() const
    {
        return _sprite.getGlobalBounds();
    }

    std::vector<std::pair<float, Detect::Detect>> Entity::getDetectors() const
    {
        return _detectors.getDetectors();
    }

    void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);

        std::vector<std::pair<float, Detect::Detect>> _detectorList = _detectors.getDetectors();
        for(std::pair<float, Detect::Detect>& _detectorPair : _detectorList)
        {
            Detect::Detect _detector = _detectorPair.second;
            target.draw(_detector.getDetector(), states);
        } 
    }
}