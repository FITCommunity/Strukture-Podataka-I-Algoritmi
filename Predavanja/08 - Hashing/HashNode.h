#pragma once

template<typename K, typename V>
class HashNode
{
	K _kljuc;
	V _vrijednost;
public:
	HashNode();

	HashNode(const K &kljuc, const V &vrijednost) :
		_kljuc(kljuc),
		_vrijednost(vrijednost)
	{}

	K getKljuc() const { return _kljuc; };
	void setKljuc(const K &kljuc) { _kljuc = kljuc; }

	V getVrijednost() const { return _vrijednost; }
	void setVrijednost(const V &vrijednost) { _vrijednost = vrijednost; }
};