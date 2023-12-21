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

    sf::VertexArray Detect::Detect::getDetector()
    {
        return _detectLine;
    }

    void Detect::move(const sf::Vector2f& offset)
    {
        _detectLine[0].position += offset;
        _detectLine[1].position += offset;

    }

    void Detect::setPosition(const sf::Vector2f& point)
    {
        sf::Vector2f startPoint = _detectLine[0].position;
        sf::Vector2f endPoint = _detectLine[1].position;
        sf::Vector2f relativeEndPoint = endPoint - startPoint;

        _detectLine[0].position = point;
        _detectLine[1].position = point + relativeEndPoint;

    }

    void Detect::rotate(const float& degree)
    {   
        float radians = degree * (M_PI / 180);

        float xLength = _detectLine[1].position.x - _detectLine[0].position.x;
        float yLength = _detectLine[1].position.y - _detectLine[0].position.y;

        _detectLine[1].position.x = (xLength * std::cos(radians) - yLength * std::sin(radians)) + _detectLine[0].position.x;
        _detectLine[1].position.y = (yLength * std::cos(radians) + xLength * std::sin(radians)) + _detectLine[0].position.y;

    }
}