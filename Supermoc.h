#pragma once
#include "Organizm.h"
class Supermoc
{
protected:
	Organizm *wlasciciel;
	int cooldown;
	int czas_dzialania;
	bool aktywna;

public:
	virtual void akcja() = 0;
	virtual void wykonaj_bezwzglednie() = 0;
	virtual void akcja_obronna() = 0;
	virtual void zmien_aktywnosc();
	virtual bool sprawdz_aktywnosc();
	virtual int zwroc_cd();
	virtual int zwroc_czas();
};

