#pragma once
#include <functional>

template<typename T>
void QuickSort
(
	T* array,
	int size,
	std::function<bool(const T&, const T&)> compare = [](const T& x, const T& y) {return x < y; }
)
{
	QSort(array, 0, size, compare);
}

template<typename T>
void QSort
(
	T* array,
	int beginning,
	int ending,
	std::function<bool(const T&, const T&)> compare = [](const T& x, const T& y) {return x < y; }
)
{
	if (beginning < ending)
	{
		int pivot = Partition(array, beginning, ending, compare);

		QSort(array, beginning, pivot - 1);
		QSort(array, pivot + 1, ending);
	}
}

template<typename T>
int Partition
(
	T* array,
	int beginning,
	int ending,
	std::function<bool(const T&, const T&)> compare = [](const T& x, const T& y) {return x < y; }
)
{
	T pivot = array[ending];
	int i = beginning - 1;

	for (int j = beginning; j < ending; j++)
	{
		if (compare(array[j], pivot))
		{
			i++;
			std::swap(array[i], array[j]);
		}
	}

	i++;
	std::swap(array[i], array[ending]);

	return i;
}



