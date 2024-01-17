namespace Detect
{
    template<typename D>
    void DetectTarget<D>::attach(const float& degree, const D& detector)
    {
        _sensorMap.emplace_back(degree, detector);
    }

    template<typename D>
    void DetectTarget<D>::detach(const float& degree)
    {
        auto remove_detector = [&degree](const std::pair<float, D>& pair) -> bool
        {
            return pair.first == degree;
        };

        _sensorMap.remove_if(remove_detector);
    }

    template<typename D>
    std::vector<std::pair<float, D>> DetectTarget<D>::getDetectors() const
    {
        return _sensorMap;
    }

    template<typename D>
    void DetectTarget<D>::setPosition(const sf::Vector2f& offset)
    {
        for(auto& pair : _sensorMap)
        {
            D& detector = pair.second;
            detector->setPosition(offset);
            
        }
    }

    template<typename D>
    void DetectTarget<D>::setPosition(float x, float y)
    {
        for(auto& pair : _sensorMap)
        {
            D& detector = pair.second;
            detector->setPosition(x, y);
            
        }
    }

    template<typename D>
    void DetectTarget<D>::move(const sf::Vector2f& offset)
    {
        for(auto& pair : _sensorMap)
        {
            D& detector = pair.second;
            detector->move(offset);
            
        }
    }

    template<typename D>
    void DetectTarget<D>::rotate(const float& degree)
    {
        for(auto& pair : _sensorMap)
        {
            D& detector = pair.second;
            detector->rotate(degree);
            
        }
    }
}