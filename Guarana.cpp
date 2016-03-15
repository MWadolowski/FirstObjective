#include "Guarana.h"
#include"Swiat.h"

Guarana::Guarana(int x, int y, Swiat *swiat)
{
	wyglad = GUARANA;
	_x = x;
	_y = y;
	_sila = 0;
	_swiat = swiat;
	_inicjatywa = 0;
	_wiek = 0;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Guarana::Guarana(Swiat *swiat)
{
	wyglad = GUARANA;
	_sila = 0;
	_swiat = swiat;
	_inicjatywa = 0;
	_wiek = 0;
}

Guarana::~Guarana()
{

}

void Guarana::akcja()
{
	Guarana *nowy = new Guarana(_swiat);
	rozmnoz(nowy);
}

void Guarana::kolizja(Organizm *napastnik)
{
	napastnik->grow_stronger();
	walcz(napastnik);
}