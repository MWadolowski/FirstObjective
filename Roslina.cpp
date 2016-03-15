#include "Roslina.h"
#include"Swiat.h"

void Roslina::kolizja(Organizm *napastnik)
{
	walcz(napastnik);
}

void Roslina::rozmnoz(Roslina *nowy)
{
	bool juz = false;
	srand(time(NULL));
	int losowanie = rand() % 5;
	if (losowanie == 3)
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (_x + i>0 && _x + i <= ILOSC && _y + j <= ILOSC && _y + j>0)
				{
					if (!this->_swiat->sprawdz_obecnosc(_x + i, _y + j) && this->_swiat->ile_zwierzat()<400)
					{
						nowy->ustaw_x_y(_x + i, _y + j);
						this->_swiat->ustaw_istote(_x + i, _y + j, nowy);
						this->_swiat->skolejkuj(nowy);
						juz = true;
					}
				}
				if (juz)
					break;
			}
			if (juz)
				break;
		}
	}
	else 
		delete nowy;
}