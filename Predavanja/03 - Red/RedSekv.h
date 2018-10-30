#pragma once

template <typename Tip>
class RedSekv
{
	int maxVelicina;
	int brojac;
	int pocetak;
	int kraj;
	Tip *niz;

	void ProsiriRed()
	{
		Tip *temp = niz;
		niz = new Tip[2 * maxVelicina];
		
		for (int j = 0, i = pocetak; j < brojac; j++, i++)
		{
			niz[j] = temp[i];

			if (i == maxVelicina) i = 0;
		}

		pocetak = 0;
		kraj = brojac;
		maxVelicina *= 2;

		delete[] temp;
	}
public:
	RedSekv(int max = 10)
		: maxVelicina(max),
		  brojac(0),
		  pocetak(0),
		  kraj(0),
		  niz(new Tip[maxVelicina])
	{
	}

	~RedSekv() { delete[] niz; }

	bool isPrazan() const { return brojac == 0; }
	bool isPun() const { return brojac == maxVelicina; }

	void Dodaj(const Tip &element)
	{
		if (isPun()) ProsiriRed();

		niz[kraj++] = element;
		if (kraj == maxVelicina) kraj = 0;
		brojac++;
	}

	Tip Ukloni()
	{
		if (isPrazan()) throw std::exception("Red je prazan!");

		Tip temp = niz[pocetak++];
		if (pocetak == maxVelicina) pocetak = 0;
		brojac--;
		
		return temp;
	}
};