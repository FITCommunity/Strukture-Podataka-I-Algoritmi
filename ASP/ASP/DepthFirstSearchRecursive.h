#pragma once

#include "AdjacencyMatrix.h"
#include "ArrayList.h"


class DepthFirstSearchRecursive
{
	AdjacencyMatrix* matrix;
	int startNode;
	ArrayList<int>* visited;

	DepthFirstSearchRecursive(AdjacencyMatrix* matrix, int node) : 
		matrix(matrix), 
		startNode(node), 
		visited(new ArrayList<int>(matrix->Size()))
	{}

	void DepthFirstSearch(int node);

public:
	static ArrayList<int>* DepthFirstSearch(AdjacencyMatrix* matrix, int node);
};

void DepthFirstSearchRecursive::DepthFirstSearch(int node)
{
	visited->Add(node);
	for (int i = 0; i < matrix->Size(); i++)
	{
		if (matrix->AreNeighbours(node, i) && !visited->Contains(i))
		{
			DepthFirstSearch(i);
		}
	}
}

ArrayList<int>* DepthFirstSearchRecursive::DepthFirstSearch(AdjacencyMatrix* matrix, int node)
{
	DepthFirstSearchRecursive dfs = DepthFirstSearchRecursive(matrix, node);
	dfs.DepthFirstSearch(node);
	return dfs.visited;
}
