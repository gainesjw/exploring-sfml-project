#include "detect.h"

namespace Detect
{
    Detect::Detect(const std::pair<sf::Vector2f, sf::Vector2f>& line)
    {
        _detectLine.setPrimitiveType(sf::LineStrip);
        _detectLine.resize(2);
        _detectLine[0].position = line.first;
        _detectLine[1].position = line.second;
    }

    bool Detect::operator==(const Detect& other) const
    {
        return _active == other._active;
    }

    sf::VertexArray Detect::Detect::get()
    {
        return _detectLine;
    }

    void Detect::move(const sf::Vector2f& offset)
    {
        _detectLine[0].position += offset;
        _detectLine[1].position += offset;

    }

    void Detect::rotate(const float& degree)
    {   

        //float magnitude = std::sqrt(_detectLine[1].position * _detectLine[1].position + _detectLine[0].position * _detectLine[0].position);
        //_detectLine[1].position.x += std::sin(degree) * magnitude;
        //_detectLine[1].position.y += std::cos(degree) * magnitude;

    }
}