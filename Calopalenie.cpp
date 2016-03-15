#include "Calopalenie.h"


Calopalenie::Calopalenie(Organizm *owner)
{
	cooldown = 0;
	czas_dzialania = 5;
	aktywna = false;
	wlasciciel = owner;
}


Calopalenie::~Calopalenie()
{
}

void Calopalenie::akcja()
{
	if (cooldown == 0)
	{
		if (aktywna == true)
		{
			int x, y;
			int poz_x = wlasciciel->gdzie_x();
			int poz_y = wlasciciel->gdzie_y();
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (i != 0 || j != 0)
					{
						x = poz_x + i;
						y = poz_y + j;
						if (this->wlasciciel->spytaj_obecnosc(x, y));
						{
							this->wlasciciel->popros_odkolejkowanie(x, y);
							this->wlasciciel->popros_wyzerowanie(x, y);
							this->wlasciciel->zabij(x, y);
							
						}
					}
				}
			}
			czas_dzialania--;
			if (czas_dzialania == 0)
			{
				cooldown = 5;
				aktywna = false;
			}
		}
	}
	else
	{
		czas_dzialania = 5;
		cooldown--;
	}
}

void Calopalenie::akcja_obronna()
{

}

void Calopalenie::wykonaj_bezwzglednie()
{
	if (cooldown == 0)
	{
		if (aktywna == true)
		{
			int x, y;
			int poz_x = wlasciciel->gdzie_x();
			int poz_y = wlasciciel->gdzie_y();
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (i != 0 || j != 0)
					{
						x = poz_x + i;
						y = poz_y + j;
						if (this->wlasciciel->spytaj_obecnosc(x, y));
						{
							this->wlasciciel->popros_odkolejkowanie(x, y);
							this->wlasciciel->popros_wyzerowanie(x, y);
							this->wlasciciel->zabij(x, y);

						}
					}
				}
			}
		}
	}
}