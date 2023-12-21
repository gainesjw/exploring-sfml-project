namespace Detect
{
    template<typename A>
    void DetectManager<A>::map(const A& agent)
    {
        _agents.insert(agent);
    }

    template<typename A>
    void DetectManager<A>::unmap(const int& agentlisting)
    {
        _agents.remove(agentlisting);
    }
}