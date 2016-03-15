#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(int x, int y, Swiat *swiat)
{
	_wiek = 0;
	wyglad = MLECZ;
	_sila = 0;
	_inicjatywa = 0;
	_swiat = swiat;
	ustaw_x_y(x, y);
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Mlecz::Mlecz(Swiat *swiat)
{
	_wiek = 0;
	wyglad = MLECZ;
	_sila = 0;
	_inicjatywa = 0;
	_swiat = swiat;
}

Mlecz::~Mlecz()
{

}

void Mlecz::akcja()
{
	Mlecz *nowy = new Mlecz(_swiat);
	rozmnoz(nowy);
	Mlecz *nowy1 = new Mlecz(_swiat);
	rozmnoz(nowy1);
	Mlecz *nowy2 = new Mlecz(_swiat);
	rozmnoz(nowy2);
}