#include <list>
#include <functional>
#include <algorithm>

#include "HashNode.h"

template<typename Kljuc, typename Vrijednost>
class Chained_Hash
{
	int maxVelicina;
	std::list<HashNode<Kljuc, Vrijednost>> *lista;
	int getHash(const Kljuc &kljuc)
	{
		return std::hash<Kljuc>{}(kljuc) % maxVelicina;
	}
public:
	Chained_Hash(int max = 10) : maxVelicina(max)
	{
		lista = new std::list<HashNode<Kljuc, Vrijednost>>[maxVelicina];
	}

	~Chained_Hash()
	{
		delete[] lista;
	}

	void Dodaj(const Kljuc &kljuc, const Vrijednost &vrijednost)
	{
		lista[getHash(kljuc)].push_back({ kljuc, vrijednost });
	}

	bool Ukloni(const Kljuc &kljuc)
	{
		return lista[getHash(kljuc)].erase(kljuc);
	}

	HashNode<Kljuc, Vrijednost> *Get(const Kljuc &kljuc, const Vrijednost &vrijednost)
	{
		int i = getHash(kljuc);
		HashNode<Kljuc, Vrijednost> temp(kljuc, vrijednost);
		auto it = std::find_if
		(
			lista[i].begin(),
			lista[i].end(),
			[temp](const HashNode<Kljuc, Vrijednost> &x)
			{
				return x.getKljuc() == temp.getKljuc() && x.getVrijednost() == temp.getVrijednost();
			}
		);

		return it != lista[i].end() ? &*it : nullptr;
	}
};
