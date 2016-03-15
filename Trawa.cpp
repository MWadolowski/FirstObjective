#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(int x, int y, Swiat *swiat)
{
	wyglad = TRAWKA;
	_x = x;
	_y = y;
	_sila = 0;
	_inicjatywa = 0;
	_wiek = 0;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Trawa::Trawa(Swiat *swiat)
{
	wyglad = TRAWKA;
	_sila = 0;
	_inicjatywa = 0;
	_wiek = 0;
	_swiat = swiat;
}

Trawa::~Trawa()
{

}

void Trawa::akcja()
{
	Trawa *nowy = new Trawa(_swiat);
	rozmnoz(nowy);
}