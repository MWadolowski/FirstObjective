#include "Owca.h"
#include "Swiat.h"

Owca::Owca(int x, int y, Swiat *swiat)
{
	ustaw_x_y(x, y);
	_sila = 4;
	_zasieg = 1;
	_wiek = 0;
	_inicjatywa = 4;
	_swiat = swiat;
	wyglad = OWCA;
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Owca::Owca(Swiat *swiat)
{
	_sila = 4;
	_zasieg = 1;
	_wiek = 0;
	_inicjatywa = 4;
	_swiat = swiat;
	wyglad = OWCA;
}

Owca::Owca(int x, int y, Swiat *swiat, int sila)
{
	ustaw_x_y(x, y);
	_sila = sila;
	_zasieg = 1;
	_wiek = 0;
	_inicjatywa = 4;
	_swiat = swiat;
	wyglad = OWCA;
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Owca::~Owca()
{
}

void Owca::akcja()
{
	Owca *nowa = new Owca(_swiat);
	rusz(nowa);
}
