#pragma once
#include <functional>

template<typename T>
void InsertionSort
(
	T* array,
	int size,
	std::function<bool(const T&, const T&)> compare = [](const T& x, const T& y) {return x > y; }
)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && compare(array[j - 1], array[j]))
		{
			std::swap(array[j - 1], array[j]);
			j--;
		}
	}
}