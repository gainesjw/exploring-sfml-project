#ifndef __DETECT_H__
#define __DETECT_H__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <list>
#include <unordered_map>
#include <utility>

namespace Detect
{
    class Detect
    {
        public:
            Detect(const std::pair<sf::Vector2f, sf::Vector2f>& line);

            bool operator==(const Detect& other) const;
            sf::VertexArray getDetector();
            void setPosition(const sf::Vector2f& point);
            void move(const sf::Vector2f& offset);
            void rotate(const float& angle);

        private:
            template<typename> friend class DetectTarget;
            int _active = 0;
            sf::VertexArray _detectLine;
            

    };
    
    template<typename A>
    class DetectManager 
    {
        public:
            DetectManager(const DetectManager<A>&) = delete;
            DetectManager<A>& operator=(const DetectManager<A>&) = delete;

            DetectManager() = default;

            void map(const A& agent);
            void unmap(const int& agentlisting);

            //const Detect& get(const int& agentlisting);
            //void update();

        private:
            std::list<A> _agents;

    };

    template<typename D>
    class DetectTarget
    {
        public:
            DetectTarget(const DetectTarget<D>&) = delete;
            DetectTarget<D>& operator=(const DetectTarget<D>&) = delete;

            DetectTarget() = default;

            void attach(const float& degree, const D& detector);
            void detach(const float& degree);

            std::vector<std::pair<float, D>> getDetectors();
            void setPosition(const sf::Vector2f& offset);
            void move(const sf::Vector2f& offset);
            void rotate(const float& degree);

            //bool sense(const sf::Rect& object) const;

        private:
            std::vector<std::pair<float, D>> _sensorMap;
    };
}

#include "detectmanager.tpl"
#include "detecttarget.tpl"

#endif