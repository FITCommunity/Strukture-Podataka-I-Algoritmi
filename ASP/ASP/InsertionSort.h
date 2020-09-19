#pragma once
#include <functional>

template<typename T, typename F = std::function<bool(const T&, const T&)>>
void InsertionSort
(
	T* array,
	int size,
	const F &compare = [](const T& x, const T& y) {return x > y; }
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