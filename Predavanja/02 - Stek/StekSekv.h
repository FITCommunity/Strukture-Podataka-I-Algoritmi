#pragma once

template <typename Tip>
class StekSekv
{
	int maxVelicina;
	int brojElemenata;
	Tip *niz;

	void ProsiriStek()
	{
		Tip *temp = niz;
		niz = new Tip[2 * maxVelicina];
		for (int i = 0; i < maxVelicina; i++)
			niz[i] = temp[i];
		maxVelicina *= 2;
		
		delete[] temp;
	}
public:
	StekSekv(int velicina = 10)
		: maxVelicina(velicina),
		  brojElemenata(0),
		  niz(new Tip[maxVelicina])
	{
	}

	~StekSekv()
	{
		delete[] niz;
	}

	bool isPrazan() const { return brojElemenata == 0; }
	bool isPun() const { return brojElemenata == maxVelicina; }

	void Push(const Tip &element)
	{
		if (isPun()) ProsiriStek();

		niz[brojElemenata++] = element;
	}

	Tip Pop()
	{
		if (isPrazan()) throw std::exception("Stek je prazan!");

		Tip temp = niz[--brojElemenata];
		return temp;
	}

	Tip Top() const
	{
		if(isPrazan()) throw std::exception("Stek je prazan!");

		return niz[brojElemenata - 1];
	}
};