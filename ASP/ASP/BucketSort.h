#pragma once

#include "LinkedPriorityQueue.h"

template<typename T>
T GetMax(T* array, int size)
{
	int maxI = 0;
	for (int i = 1; i < size; i++)
		if (array[i] > array[maxI])
			maxI = i;
	return array[maxI];
}

template<typename T>
void BucketSort(T* array, int size)
{
	LinkedPriorityQueue<T>* queue = new LinkedPriorityQueue<T>[size];

	int max = GetMax(array, size);
	for (int i = 0; i < size; i++)
	{
		int j = array[i] * size / (max + 1);
		queue[j].Add(array[i]);
	}

	int index = size - 1;
	for (int i = size - 1; i >= 0; i--)
		while (!queue[i].IsEmpty())
			array[index--] = queue[i].Remove();

	delete[] queue;
}
