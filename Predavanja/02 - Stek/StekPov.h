#pragma once
#include "Cvor.h"

template <typename Tip>
class StekPov
{
	Cvor<Tip> *prvi;
public:
	StekPov() : prvi(nullptr)
	{
	}

	~StekPov()
	{
		while (prvi)
		{
			Cvor<Tip> *temp = prvi;
			prvi = prvi->link;
			delete temp;
		}
	}

	bool isPrazan() const { return !prvi; };
	void Push(Tip element)
	{
		Cvor<Tip> *noviCvor = new Cvor<Tip>(element, prvi);
		prvi = noviCvor;
	}

	Tip Pop()
	{
		if (isPrazan()) throw std::exception("Stek je prazan!");

		Cvor<Tip> *tempCvor = prvi;
		prvi = prvi->link;

		Tip temp = tempCvor->info;
		delete tempCvor;
		return temp;
	}

	Tip Top() const
	{
		if (isPrazan()) throw std::exception("Stek je prazan!");

		return prvi->info;
	}
};

