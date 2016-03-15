#include "Wilk.h"
#include "Swiat.h"

Wilk::Wilk(int x, int y, Swiat *swiat)
{
	_sila = 9;
	_inicjatywa = 5;
	_wiek = 0;
	wyglad = WILKU;
	ustaw_x_y(x, y);
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Wilk::Wilk(Swiat *swiat)
{
	_sila = 9;
	_inicjatywa = 5;
	_wiek = 0;
	wyglad = WILKU;
	_zasieg = 1;
	_swiat = swiat;
}

Wilk::Wilk(int x, int y, Swiat *swiat, int sila)
{
	_sila = sila;
	_inicjatywa = 5;
	_wiek = 0;
	wyglad = WILKU;
	ustaw_x_y(x, y);
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Wilk::~Wilk()
{
}

void Wilk::akcja()
{
	Wilk *nowy = new Wilk(_swiat);
	rusz(nowy);
}