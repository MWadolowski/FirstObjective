#include "Zwierze.h"
#include "Swiat.h"

void Zwierze::rusz(Zwierze *ten)
{
	int ilosc = 0, nowy_x = _x, nowy_y = _y;
	int x[8];
	int y[8];
	ustal_kierunek(x, y, &ilosc);
	mieszaj(x, y, ilosc);
	for (int i = 0; i < ilosc;i++)
	{
		nowy_x =x[i];
		nowy_y =y[i];
		if (nowy_x != _x || nowy_y != _y)
		{
			if (!this->_swiat->sprawdz_obecnosc(nowy_x, nowy_y))
			{
				this->_swiat->przesun(nowy_x, nowy_y, this);
				this->_swiat->wyzeruj_pole(_x, _y);
				_x = nowy_x;
				_y = nowy_y;
				delete ten;
			}
			else
			{
				if (this->_swiat->okresl_wyglad(nowy_x, nowy_y) == wyglad)
					rozmnoz(ten);	
				else
				{
					this->_swiat->wywolaj_obrone(nowy_x, nowy_y, this);
					delete ten;
				}
			}
			break;
		}
	}
}

void Zwierze::ustal_kierunek(int x[], int y[], int *ilosc)
{
	int nowy_x, nowy_y;
	for (int i = 1; i >= -1; i--)
	{
		for (int j = 1; j >= -1; j--)
		{
			nowy_x = _x + _zasieg*i;
			nowy_y = _y + _zasieg*j;
			if (nowy_x <= 20 && nowy_x>= 1 && nowy_y <= 20 && nowy_y>= 1 && (i != 0 || j != 0))
			{
				x[*ilosc] = nowy_x;
				y[*ilosc] = nowy_y;
				(*ilosc)++;
			}
		}
	}
}

void Zwierze::mieszaj(int x[], int y[], int ilosc)
{
	int mieszana1, mieszana2;
	srand(time(NULL));
	for (int i = 0; i<11; i++)
	{
		if (ilosc > 1)
		{
			mieszana1 = rand() % ilosc;
			mieszana2 = rand() % ilosc;
			swap(x[mieszana1], x[mieszana2]);
			swap(y[mieszana1], y[mieszana2]);
		}

	}
}