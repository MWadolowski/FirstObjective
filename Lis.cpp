#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int x, int y, Swiat *swiat)
{
	_sila = 4;
	_inicjatywa = 7;
	_wiek = 0;
	wyglad = LISEK;
	ustaw_x_y(x, y);
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Lis::Lis(Swiat *swiat)
{
	_sila = 4;
	_inicjatywa = 7;
	_wiek = 0;
	wyglad = LISEK;
	_zasieg = 1;
	_swiat = swiat;
}

Lis::Lis(int x, int y, Swiat *swiat, int sila)
{
	_sila = sila;
	_inicjatywa = 7;
	_wiek = 0;
	wyglad = LISEK;
	ustaw_x_y(x, y);
	_zasieg = 1;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Lis::~Lis()
{

}

void Lis::akcja()
{
	int ilosc = 0, nowy_x = _x, nowy_y = _y;
	int x[9];
	int y[9];
	ustal_kierunek(x, y, &ilosc);
	mieszaj(x, y, ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		nowy_x = x[i];
		nowy_y = y[i];
		if (nowy_x != _x || nowy_y != _y)
		{
			if (!this->_swiat->sprawdz_obecnosc(nowy_x, nowy_y))
			{
				this->_swiat->przesun(nowy_x, nowy_y, this);
				this->_swiat->wyzeruj_pole(_x, _y);
				_x = nowy_x;
				_y = nowy_y;
				break;
			}
			else if (this->_swiat->okresl_wyglad(nowy_x, nowy_y) == wyglad)
			{
				Lis *nowy = new Lis(_swiat);
				rozmnoz(nowy);
				break;
			}
			else if (_sila >= this->_swiat->okresl_sile(nowy_x,nowy_y))
			{
				this->_swiat->wywolaj_obrone(nowy_x, nowy_y, this);
				break;
			}	
		}
	}
}


void Lis::kolizja(Organizm *napastnik)
{
	walcz(napastnik);
}