#pragma once

template<typename T>
void RadixSort(T* array, int size)
{
	int exponent = 1;
	int max = GetMax(array, size);

	while (max)
	{
		Sort(array, size, exponent);
		exponent *= 10;
		max /= 10;
	}
}

namespace
{
	template<typename T>
	T GetMax(T* array, int size)
	{
		int maxI = array[0];
		for (int i = 1; i < size; i++)
			if (array[i] > array[maxI])
				maxI = i;
		return array[maxI];
	}

	template<typename T>
	void Sort(T* array, int size, int exponent)
	{
		int counter[10] = {};

		//Podjeliti array u buckete
		for (int i = 0; i < size; i++)
			counter[(array[i] / exponent) % 10]++;

		//Izracunati od koje do koje pozicije u arrayu ce se nalaziti koji bucket
		for (int i = 1; i < 10; i++)
			counter[i] += counter[i - 1];

		//Prepisi sve clanove iz orginalnog arraya u pomocni proracunavanjem njihovih pozicija 
		//bazirano na broju elemenata svakog bucketa
		T* temp = new T[size];
		for (int i = size - 1; i >= 0; i--)
		{
			int bucketNumber = (array[i] / exponent) % 10;
			temp[--counter[bucketNumber]] = array[i];
		}

		//Kopiraj iz temp arraya u orginalni
		for (int i = 0; i < size; i++)
			array[i] = temp[i];
		delete[] temp;
	}
}