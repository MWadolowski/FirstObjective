#pragma once
#include "Organizm.h"
class Swiat;
class Plik
{
	Swiat *_swiat;
	char nazwa[100];

public:
	Plik(Swiat *swiat);
	~Plik();
	void zapisz();
	void otworz();
protected:
	void zmien_nazwe();
	void stworz_lisa(int x, int y, int sila);
	void stworz_owce(int x, int y, int sila);
	void stworz_antylope(int x, int y, int sila);
	void stworz_guarane(int x, int y);
	void stworz_ludzia(int x, int y, int sila, Plik *plik);
	void stworz_mlecz(int x, int y);
	void stworz_trawe(int x, int y);
	void stworz_wilka(int x, int y, int sila);
	void stworz_jagode(int x, int y);
	void stworz_zolwia(int x, int y, int sila);
	void sprawdz_nazwe(int i) throw(string);
};

