#pragma once
class Edge
{
    int startNode;
    int endNode;
    int weight;
public:
    Edge(int startNode, int endNode, int weight) : startNode(startNode), endNode(endNode), weight(weight)
    {}

    int GetStartNode() const { return startNode; }
    void SetStartNode(int node) { startNode = node; }

    int GetEndNode() const { return endNode; }
    void SetEndNode(int node) { endNode = node; }

    int GetWeight() const { return weight; }
    void SetWeight(int w) { weight = w; }
};

