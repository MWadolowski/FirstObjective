#include "Organizm.h"
#include "Swiat.h"

void Organizm::kolizja(Organizm *napastnik)
{
	walcz(napastnik);
}

void Organizm::rysuj(){
	gotoxy(_x, _y);
	cout << wyglad;
}

void Organizm::gotoxy(int x, int y){
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int Organizm::gdzie_x(){
	return _x;
}

int Organizm::gdzie_y(){
	return _y;
}

int Organizm::okresl_sile()
{
	return this->_sila;
}

char Organizm::okresl_wyglad()
{
	return this->wyglad;
}

int Organizm::okresl_inicjatywe()
{
	return this->_inicjatywa;
}

int Organizm::okresl_wiek()
{
	return this->_wiek;
}

void Organizm::ustaw_x_y(int x, int y)
{
	_x = x;
	_y = y;
}

bool Organizm::spytaj_obecnosc(int x, int y)
{
	return this->_swiat->sprawdz_obecnosc(x, y);
}

void Organizm::popros_odkolejkowanie(int x, int y)
{
	this->_swiat->usun_zkolejki(x, y);
}

void Organizm::popros_wyzerowanie(int x, int y)
{
	this->_swiat->wyzeruj_pole(x, y);
}

void Organizm::zabij(int x, int y)
{
	this->_swiat->zabij(x, y);
}

void Organizm::grow_stronger()
{
	_sila++;
}

void Organizm::postarz()
{
	_wiek++;
}

void Organizm::walcz(Organizm *napastnik)
{
	int nap_x = napastnik->gdzie_x();
	int nap_y = napastnik->gdzie_y();
	if (_sila > napastnik->okresl_sile())
	{
		this->_swiat->wyzeruj_pole(nap_x, nap_y);
		this->_swiat->zabij(napastnik);
	}
	else
	{
		napastnik->ustaw_x_y(_x, _y);
		this->_swiat->przesun(_x, _y, napastnik);
		this->_swiat->wyzeruj_pole(nap_x, nap_y);
		this->_swiat->zabij(this);
	}
}

void Organizm::rozmnoz(Organizm *nowy)
{
	bool czy_ma_miejsce = false;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!this->_swiat->sprawdz_obecnosc(_x + i, _y + j) && _x + i<21 && _x + i>0 && _y + j<21 && _y + j>0 && _swiat->ile_zwierzat()<400)
			{
				nowy->ustaw_x_y(_x + i, _y + j);
				this->_swiat->ustaw_istote(_x + i, _y + j, nowy);
				this->_swiat->skolejkuj(nowy);
				czy_ma_miejsce = true;
				break;
			}
		}
		if (czy_ma_miejsce)
			break;
	}
	if (!czy_ma_miejsce)
	{
		delete nowy;
	}
}

