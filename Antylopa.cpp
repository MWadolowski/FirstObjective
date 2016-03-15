#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int x, int y, Swiat *swiat)
{
	_sila = 4;
	_inicjatywa = 4;
	_wiek = 0;
	wyglad = ANTYLOPA;
	ustaw_x_y(x, y);
	_zasieg = 2;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Antylopa::Antylopa(Swiat *swiat)
{
	_sila = 4;
	_inicjatywa = 4;
	_wiek = 0;
	wyglad = ANTYLOPA;
	_zasieg = 2;
	_swiat = swiat;
}

Antylopa::Antylopa(int x, int y, Swiat *swiat, int sila)
{
	_sila = sila;
	_inicjatywa = 4;
	_wiek = 0;
	wyglad = ANTYLOPA;
	ustaw_x_y(x, y);
	_zasieg = 2;
	_swiat = swiat;
	this->_swiat->skolejkuj(this);
	this->_swiat->ustaw_istote(_x, _y, this);
}

Antylopa::~Antylopa()
{

}

void Antylopa::akcja()
{
	Antylopa *nowa = new Antylopa(_swiat);
	rusz(nowa);
}

void Antylopa::kolizja(Organizm *napastnik)
{
	srand(time(NULL));
	int m = rand() % 2;
	if (m == 1)
	{
		int x, y;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (i != 0 || j != 0)
				{
					x = _x + _zasieg*i;
					y = _y + _zasieg*j;
					if (!this->_swiat->sprawdz_obecnosc(x, y))
					{
						this->_swiat->przesun(x, y, this);
						ustaw_x_y(x, y);
						break;
					}
				}
			}
		}
	}
}