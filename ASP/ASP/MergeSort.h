#pragma once
#include <functional>

template<typename T, typename F = std::function<bool(const T&, const T&)>>
void MergeSort
(
	T* array,
	int size,
	const F &compare = [](const T& x, const T& y) {return x < y; }
)
{
	MSort(array, 0, size - 1, compare);
}

namespace
{
	template<typename T, typename F = std::function<bool(const T&, const T&)>>
	void MSort
	(
		T* array,
		int beginning,
		int ending,
		const F& compare = [](const T& x, const T& y) {return x < y; }
	)
	{
		if (beginning < ending)
		{
			int middle = (beginning + ending) / 2;
			MSort(array, beginning, middle, compare);
			MSort(array, middle + 1, ending, compare);

			Merge(array, beginning, middle, ending, compare);
		}
	}

	template<typename T, typename F = std::function<bool(const T&, const T&)>>
	void Merge
	(
		T* array,
		int beginning,
		int middle,
		int ending,
		const F& compare = [](const T& x, const T& y) {return x < y; }
	)
	{
		int iTemp = 0;
		int i1 = beginning;
		int i2 = middle + 1;
		int size = ending - beginning + 1;

		T* tempArray = new T[size];

		//Spoji 2 arraya
		while (i1 <= middle && i2 <= ending)
			compare(array[i1], array[i2]) ? tempArray[iTemp++] = array[i1++]
										  : tempArray[iTemp++] = array[i2++];


		//Kopiraj ostatak
		while (i1 <= middle)
			tempArray[iTemp++] = array[i1++];
		while (i2 <= ending)
			tempArray[iTemp++] = array[i2++];


		//Kopiraj temp array u orginal
		for (int i = beginning, j = 0; i <= ending; i++, j++)
			array[i] = tempArray[j];

		delete[] tempArray;

	}
}