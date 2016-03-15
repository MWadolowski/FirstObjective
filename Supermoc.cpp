#include "Supermoc.h"

void Supermoc::zmien_aktywnosc()
{
	if (aktywna == true)
		aktywna = false;
	else aktywna = true;
}

bool Supermoc::sprawdz_aktywnosc()
{
	return aktywna;
}

int Supermoc::zwroc_cd()
{
	return cooldown;
}

int Supermoc::zwroc_czas()
{
	return czas_dzialania;
}