#pragma once


template <typename Tip>
class PrioritetniRedSekv
{
	int maxVelicina;
	int brojac;
	Tip *niz;

	void ProsiriRed()
	{
		Tip *temp = niz;
		niz = new Tip[2 * maxVelicina];
		for (int i = 0; i < maxVelicina; i++)
			niz[i] = temp[i];
		maxVelicina *= 2;

		delete[] temp;
	}
public:
	PrioritetniRedSekv(int max = 10)
		: maxVelicina(max),
		  brojac(0),
		  niz(new Tip[maxVelicina])
	{
	}

	~PrioritetniRedSekv()
	{
		delete[] niz;
	}

	bool isPun() const { return brojac == maxVelicina; }
	bool isPrazan() const { return brojac == 0; }

	void Dodaj(const Tip &element)
	{
		if (isPun()) ProsiriRed();

		niz[brojac++] = element;
	}

	Tip Ukloni()
	{
		if (isPrazan()) throw std::exception("Red je prazan!");


		int max = 0;
		for (int i = 1; i < brojac; i++)
			if (niz[i] > niz[max])
				max = i;

		Tip temp = niz[max];
		brojac--;
		niz[max] = niz[brojac];

		return temp;
	}
};