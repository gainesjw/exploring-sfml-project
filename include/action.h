#ifndef __ACTION_H__
#define __ACTION_H__

#include <SFML/Graphics.hpp>
#include <unordered_map> // unordered_map
#include <list> // list
#include <utility> // pair
#include <functional> //function

namespace Action
{
    class Action
    {
        public:
            enum Type
            {
                RealTime = 1
                ,Pressed = 1 << 1
                ,Released = 1 << 2
            };

            Action(const sf::Keyboard::Key& key, int type=Type::RealTime|Type::Pressed);
            Action(const sf::Mouse::Button& button, int type=Type::RealTime|Type::Pressed);

            bool test() const;
            bool operator==(const sf::Event& event) const;
            bool operator==(const Action& other) const;

        private:
            template<typename> friend class ActionTarget;
            sf::Event _event;
            int _type;
    };

    template<typename T = int>
    class ActionMap
    {
        public:
            ActionMap(const ActionMap<T>&) = delete;
            ActionMap<T>& operator=(const ActionMap<T>&) = delete;

            ActionMap() = default;

            void map(const T& key, const Action& action);
            const Action& get(const T& key) const;

        private:
            std::unordered_map<T, Action> _map;
    };

    template<typename T = int>
    class ActionTarget
    {
        public:
            ActionTarget(const ActionTarget<T>&) = delete;
            ActionTarget<T>& operator=(const ActionTarget<T>&) = delete;

            ActionTarget(const ActionMap<T>& map);

            using FuncType = std::function<void(const sf::Event&)>;

            bool processEvent(const sf::Event& event) const;
            void processEvents() const;

            void bind(const T&, const FuncType& callback);
            void unbind(const T& key);

        private:
            std::list<std::pair<T, FuncType>> _eventsRealTime;
            std::list<std::pair<T, FuncType>> _eventsPoll;

            const ActionMap<T>& _actionMap;
    };
}

#include "actionmap.tpl"
#include "actiontarget.tpl"

#endif