#pragma once

#include "Edge.h"
#include "ArrayList.h"

class AdjacencyMatrix
{
    int** matrix;
    int size;
public:
    AdjacencyMatrix(int size);
    int Size() const;
    void Add(const Edge& edge);
    bool IsCorrect() const;
    int OutDegree(int node) const;
    int InDegree(int node) const;
    ArrayList<int>* NeighboursTo(int node) const;
    ArrayList<int>* NeighboursFrom(int node) const;
    bool AreNeighbours(int from, int to) const;
    int ClosestNeighbour(int node) const;
    int Weight(int from, int to) const;
    ~AdjacencyMatrix();
};

AdjacencyMatrix::AdjacencyMatrix(int size) : size(size)
{
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size] {0};
}

int AdjacencyMatrix::Size() const
{
    return size;
}

void AdjacencyMatrix::Add(const Edge& edge)
{
    matrix[edge.GetStartNode()][edge.GetEndNode()] = edge.GetWeight();
    matrix[edge.GetEndNode()][edge.GetStartNode()] = edge.GetWeight();
}

bool AdjacencyMatrix::IsCorrect() const
{
    for (int i = 0; i < size; i++)
        if (matrix[i][i] != 0)
            return false;
    return true;
}

int AdjacencyMatrix::OutDegree(int node) const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[node][i];
    }
    return sum;
}

int AdjacencyMatrix::InDegree(int node) const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][node];
    }
    return sum;
}

ArrayList<int>* AdjacencyMatrix::NeighboursTo(int node) const
{
    ArrayList<int>* list = new ArrayList<int>;

    for (int i = 0; i < size; i++)
        if (AreNeighbours(node, i))
            list->Add(i);

    return list;
}

ArrayList<int>* AdjacencyMatrix::NeighboursFrom(int node) const
{
    ArrayList<int>* list = new ArrayList<int>;

    for (int i = 0; i < size; i++)
        if (AreNeighbours(i, node))
            list->Add(i);

    return list;
}

int AdjacencyMatrix::Weight(int from, int to) const
{
    return matrix[from][to];
}

bool AdjacencyMatrix::AreNeighbours(int from, int to) const
{
    return matrix[from][to] != 0;
}

int AdjacencyMatrix::ClosestNeighbour(int node) const
{
    ArrayList<int>* neighbours = NeighboursTo(node);

    int minNeighbour = -1;
    int minWeight = INT_MAX;

    for (int i = 0; i < neighbours->Size(); i++)
    {
        int neighbour = neighbours->Get(i);
        int weight = Weight(node, neighbour);

        if (weight < minWeight)
        {
            minWeight = weight;
            minNeighbour = neighbour;
        }
    }

    return minNeighbour;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}

