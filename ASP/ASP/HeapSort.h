#pragma once
#include <utility>

namespace
{
	template<typename T>
	void BubbleDown(T* array, int size, int index)
	{
		int maxIndex = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < size && array[left] > array[maxIndex])
			maxIndex = left;

		if (right < size && array[right] > array[maxIndex])
			maxIndex = right;

		if (maxIndex != index)
		{
			std::swap(array[index], array[maxIndex]);
			BubbleDown(array, size, maxIndex);
		}
	}
}

template<typename T>
void HeapSort(T* array, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		BubbleDown(array, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(array[0], array[i]);
		size--;
		BubbleDown(array, size, 0);
	}
}
