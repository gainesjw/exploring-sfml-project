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

    Detect::~Detect()
    {

    }

    bool Detect::operator==(const Detect& other) const
    {
        return _active == other._active;
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

    void Detect::setPosition(float x, float y)
    {
        sf::Vector2f startPoint = _detectLine[0].position;
        sf::Vector2f endPoint = _detectLine[1].position;
        sf::Vector2f relativeEndPoint = endPoint - startPoint;

        _detectLine[0].position.x = x;
        _detectLine[0].position.y = y;
        _detectLine[1].position.x = x + relativeEndPoint.x;
        _detectLine[1].position.y = y + relativeEndPoint.y;

    }

    void Detect::rotate(const float& degree)
    {   
        float radians = degree * (M_PI / 180);

        float xLength = _detectLine[1].position.x - _detectLine[0].position.x;
        float yLength = _detectLine[1].position.y - _detectLine[0].position.y;

        _detectLine[1].position.x = (xLength * std::cos(radians) - yLength * std::sin(radians)) + _detectLine[0].position.x;
        _detectLine[1].position.y = (yLength * std::cos(radians) + xLength * std::sin(radians)) + _detectLine[0].position.y;

    }

    sf::VertexArray Detect::Detect::getDetector()
    {
        return _detectLine;
    }

    void Detect::setActivity(bool indicator)
    {
        _active = indicator;
    }

    bool Detect::getActivity()
    {
        return _active;
    }
}