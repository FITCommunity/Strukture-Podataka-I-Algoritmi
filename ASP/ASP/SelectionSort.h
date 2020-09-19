#pragma once
#include <functional>

template<typename T, typename F = std::function<bool(const T&, const T&)>>
void SelectionSort
(
	T* array,
	int size,
	const F &compare = [](const T& x, const T& y) {return x < y; }
)
{
	for (int i = 0; i < size - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < size; j++)
			if (compare(array[j], array[index]))
				index = j;

		if (index != i)
			std::swap(array[index], array[i]);
	}
}