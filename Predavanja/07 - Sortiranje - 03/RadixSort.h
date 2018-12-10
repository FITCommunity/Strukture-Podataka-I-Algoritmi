#pragma once

//template<typename Tip>
//Tip getMax(Tip *niz, int velicina)
//{
//	int maxI = niz[0];
//	for (int i = 1; i < velicina; i++)
//		if (niz[i] > niz[maxI])
//			maxI = i;
//	return niz[maxI];
//}

template<typename Tip>
void Sort(Tip *niz, int velicina, int eksponent)
{
	int brojac[10] = {};

	//Podjeliti niz u buckete
	for (int i = 0; i < velicina; i++)
		brojac[(niz[i] / eksponent) % 10]++;

	//Izracunati od koje do koje pozicije u nizu ce se nalaziti koji bucket
	for (int i = 1; i < 10; i++)
		brojac[i] += brojac[i - 1];

	//Prepisi sve clanove iz orginalnog niza u pomocni proracunavanjem njihovih pozicija 
	//bazirano na broju elemenata svakog bucketa
	Tip *temp = new Tip[velicina];
	for (int i = velicina - 1; i >= 0; i--)
	{
		int brBucketa = (niz[i] / eksponent) % 10;
		temp[--brojac[brBucketa]] = niz[i];
	}

	//Kopiraj iz temp niza u orginalni
	for (int i = 0; i < velicina; i++)
		niz[i] = temp[i];
	delete[] temp;
}

template<typename Tip>
void RadixSort(Tip *niz, int velicina)
{
	int eksponent = 1;
	int max = getMax(niz, velicina);

	while (max)
	{
		Sort(niz, velicina, eksponent);
		eksponent *= 10;
		max /= 10;
	}
}