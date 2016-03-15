#pragma once
#include "Supermoc.h"
class Calopalenie :
	public Supermoc
{
public:
	Calopalenie(Organizm *wlasciciel);
	~Calopalenie();
	void akcja();
	void akcja_obronna();
	void wykonaj_bezwzglednie();
};

