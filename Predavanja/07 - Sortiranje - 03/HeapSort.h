#pragma once

template<typename Tip>
void BubbleDown(Tip *niz, int velicina, int indeks)
{
	int maxIndeks = indeks;
	int lijevo = 2 * indeks + 1;
	int desno = 2 * indeks + 2;

	if (lijevo < velicina && niz[lijevo] > niz[maxIndeks]) 
		maxIndeks = lijevo;

	if (desno < velicina && niz[desno] > niz[maxIndeks])
		maxIndeks = desno;

	if (maxIndeks != indeks)
	{
		std::swap(niz[indeks], niz[maxIndeks]);
		BubbleDown(niz, velicina, maxIndeks);
	}
}

template<typename Tip>
void HeapSort(Tip *niz, int velicina)
{
	for (int i = velicina / 2 - 1; i >= 0; i--)
		BubbleDown(niz, velicina, i);

	for (int i = velicina - 1; i >= 0; i--)
	{
		std::swap(niz[0], niz[i]);
		velicina--;
		BubbleDown(niz, velicina, 0);
	}
}