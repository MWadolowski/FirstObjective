#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(int x, int y, Swiat *swiat)
{
	wyglad = ZOLWIK;
	_sila = 2;
	ustaw_x_y(x, y);
	_inicjatywa = 1;
	_wiek = 0;
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Zolw::Zolw(Swiat *swiat)
{
	wyglad = ZOLWIK;
	_sila = 2;
	_inicjatywa = 1;
	_wiek = 0;
	_zasieg = 1;
	_swiat = swiat;
}

Zolw::Zolw(int x, int y, Swiat *swiat, int sila)
{
	wyglad = ZOLWIK;
	_sila = sila;
	ustaw_x_y(x, y);
	_inicjatywa = 1;
	_wiek = 0;
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Zolw::~Zolw()
{
}

void Zolw::akcja()
{
	srand(time(NULL));
	int i = rand() % 4;
	if (i == 4)
	{
		Zolw *nowy = new Zolw(_swiat);
		rusz(nowy);
	}
}

void Zolw::kolizja(Organizm *napastnik)
{
	if (napastnik->okresl_sile() > 5)
		walcz(napastnik);
}