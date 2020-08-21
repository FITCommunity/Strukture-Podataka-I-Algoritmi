#pragma once
#include "PrioritetniRedPov.h"

template<typename Tip>
Tip getMax(Tip *niz, int velicina)
{
	int maxI = 0;
	for (int i = 1; i < velicina; i++)
		if (niz[i] > niz[maxI])
			maxI = i;
	return niz[maxI];
}

template<typename Tip>
void BucketSort(Tip *niz, int velicina)
{
	PrioritetniRedPov<Tip> *red = new PrioritetniRedPov<Tip>[velicina];

	int max = getMax(niz, velicina);
	for (int i = 0; i < velicina; i++)
	{
		int j = niz[i] * velicina / (max + 1);
		red[j].Dodaj(niz[i]);
	}

	int indeks = velicina - 1;
	for (int i = velicina - 1; i >= 0; i--)
		while (!red[i].isPrazan())
			niz[indeks--] = red[i].Ukloni();

	delete[] red;
}
