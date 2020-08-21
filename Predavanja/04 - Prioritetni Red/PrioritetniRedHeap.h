#pragma once

template <typename Tip>
class PrioritetniRedHeap
{
	int maxVelicina;
	int brojac;
	Tip *niz;

	void Zamijeni(int &x, int &y)
	{
		Tip temp = x;
		x = y;
		y = temp;
	}

	int getPozDesnoDijete(int i) const { return 2 * i + 2; }
	int getPozLijevoDijete(int i) const { return 2 * i + 1; }
	int getPozRoditelja(int i) const { return (i - 1) / 2; }

	bool imaDesnoDijete(int i) const { return getPozDesnoDijete(i) < brojac; }
	bool imaLijevoDijete(int i) const { return getPozLijevoDijete(i) < brojac; }

	bool isKorijen(int i) const { return i == 0; }
	bool isList(int i) const { return !imaLijevoDijete(i); }

	void ProsiriRed()
	{
		Tip *temp = niz;
		niz = new Tip[2 * maxVelicina];
		for (int i = 0; i < maxVelicina; i++)
			niz[i] = temp[i];
		maxVelicina *= 2;

		delete[] temp;
	}

	void BubbleUp(int i)
	{
		if (!isKorijen(i))
		{
			int roditelj = getPozRoditelja(i);

			if (niz[roditelj] < niz[i])
			{
				Zamijeni(niz[roditelj], niz[i]);
				BubbleUp(roditelj);
			}
		}
	}

	void BubbleDown(int i = 0)
	{
		if (!isList(i))
		{
			int lijevoDijete = getPozLijevoDijete(i);

			int maxIndeks = i;
			if (niz[lijevoDijete] > niz[maxIndeks]) maxIndeks = lijevoDijete;


			if (imaDesnoDijete(i))
			{
				int desnoDijete = getPozDesnoDijete(i);

				if (niz[desnoDijete] > niz[maxIndeks]) maxIndeks = desnoDijete;
			}

			if (maxIndeks != i)
			{
				Zamijeni(niz[maxIndeks], niz[i]);
				BubbleDown(maxIndeks);
			}
		}
	}

public:
	PrioritetniRedHeap(int max = 10) 
		: maxVelicina(max),
		  brojac(0),
		  niz(new Tip[maxVelicina])
	{
	}

	~PrioritetniRedHeap()
	{
		delete[] niz;
	}

	bool isPun() const { return brojac == maxVelicina; }
	bool isPrazan() const { return brojac == 0; }

	void Dodaj(const Tip &element)
	{
		if (isPun()) ProsiriRed();

		niz[brojac] = element;
		BubbleUp(brojac);
		brojac++;
	}

	Tip Ukloni()
	{
		if (isPrazan()) throw std::exception("Red je prazan!");

		Tip temp = niz[0];
		niz[0] = niz[brojac - 1];

		BubbleDown();
		brojac--;

		return temp;
	}

};