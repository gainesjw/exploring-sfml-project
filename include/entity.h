#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SFML/Graphics.hpp>
#include "configuration.h"

namespace Entity
{
    class World;
    class Entity : public sf::Drawable
    {
        public:
        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;
        Entity(Configuration::Configuration::Textures texture_id, World& world);
        virtual ~Entity();

        template<typename ... Args>
        void setPosition(Args&& ... args)
        {
            _sprite.setPosition(std::forward<Args>(args) ...);
        }

        virtual void update(sf::Time) = 0;
        const sf::Vector2f& getPosition() const;

        protected:
            friend class Player;
            friend class Enemy;

            sf::Vector2f    _velocity;
            sf::Sprite      _sprite;
            World& _world;
            bool _alive;

        private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}

#endif