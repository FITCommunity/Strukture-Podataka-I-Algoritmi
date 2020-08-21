#pragma once

#include "AdjacencyMatrix.h"
#include "ArrayList.h"
#include "LinkedStack.h"

class DepthFirstSearchIterative
{
    AdjacencyMatrix* matrix;
    int startNode;

    DepthFirstSearchIterative(AdjacencyMatrix* matrix, int node) : matrix(matrix), startNode(node)
    {}

    ArrayList<int>* DepthFirstSearch();

public:
    static ArrayList<int>* DepthFirstSearch(AdjacencyMatrix* matrix, int node);
};

ArrayList<int>* DepthFirstSearchIterative::DepthFirstSearch()
{
	ArrayList<int>* visited = new ArrayList<int>(matrix->Size());

	LinkedStack<int> stack;

	stack.Push(startNode);

	while (!stack.IsEmpty())
	{
		int visitedNode = stack.Pop();

		if (!visited->Get(visitedNode))
		{
			visited->Add(visitedNode);

			for (int i = matrix->Size() - 1; i >= 0; i--)
			{
				if (matrix->AreNeighbours(visitedNode, i) && !visited->Contains(i))
				{
					stack.Push(i);
				}
			}
		}
	}

	return visited;
}

ArrayList<int>* DepthFirstSearchIterative::DepthFirstSearch(AdjacencyMatrix* matrix, int node)
{
    DepthFirstSearchIterative dfs = DepthFirstSearchIterative(matrix, node);
    return dfs.DepthFirstSearch();
}
