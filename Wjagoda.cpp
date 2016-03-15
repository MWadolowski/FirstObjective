#include "Wjagoda.h"
#include "Swiat.h"

Wjagoda::Wjagoda(int x, int y, Swiat *swiat)
{
	_wiek = 0;
	wyglad = JAGODA;
	_sila = 99;
	_inicjatywa = 0;
	_swiat = swiat;
	ustaw_x_y(x, y);
	this->_swiat->ustaw_istote(x, y, this);
	this->_swiat->skolejkuj(this);
}

Wjagoda::Wjagoda(Swiat *swiat)
{
	_wiek = 0;
	wyglad = JAGODA;
	_sila = 99;
	_inicjatywa = 0;
	_swiat = swiat;
}

Wjagoda::~Wjagoda()
{

}

void Wjagoda::akcja()
{
	Wjagoda *nowy = new Wjagoda(_swiat);
	rozmnoz(nowy);
}

void Wjagoda::kolizja(Organizm *napastnik)
{
	this->_swiat->wyzeruj_pole(napastnik->gdzie_x(), napastnik->gdzie_y());
	zabij(napastnik->gdzie_x(), napastnik->gdzie_y());
	this->_swiat->wyzeruj_pole(_x, _y);
	zabij(_x, _y);
}