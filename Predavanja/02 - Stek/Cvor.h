#pragma once

template <typename Tip>
class Cvor
{
public:

	Tip info;
	Cvor<Tip> *link;

	Cvor(Cvor<Tip> *linkVrijednost = nullptr)
		: link(linkVrijednost)
	{
	}

	Cvor(Tip infoVrijednost, Cvor<Tip> *linkVrijednost = nullptr)
		: info(infoVrijednost),
		link(linkVrijednost)
	{
	}
};