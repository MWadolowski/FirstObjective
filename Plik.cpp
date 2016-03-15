#include "Plik.h"
#include "Swiat.h"
#include <fstream>
#include "Organizm.h"

Plik::Plik(Swiat *swiat)
{
	_swiat = swiat;
}


Plik::~Plik()
{

}

void Plik::zapisz()
{
	zmien_nazwe();
	ofstream plik(nazwa);
	for (int i = 0; i < ILOSC; i++)
	{
		for (int j = 0; j < ILOSC; j++)
		{
			if (this->_swiat->sprawdz_obecnosc(i + 1, j + 1))
			{
				plik << char(this->_swiat->okresl_wyglad(i + 1, j + 1));
				plik << this->_swiat->okresl_sile(i + 1, j + 1);
			}
			else
				plik << "-0";
		}
		plik << endl;
	}
	plik.close();
}

void Plik::otworz()
{
	int x = 1, y = 1, sila;
	char wyglad, znak_sily;
	//zmien_nazwe();
	//ifstream plik(nazwa);
	ifstream plik("test.txt");
	for (int i = 0; i < ILOSC; i++)
	{
		for (int j = 0; j < ILOSC; j++)
		{
			plik >> wyglad >> znak_sily;
			sila = atoi(&znak_sily);
			if (wyglad == LISEK)
				stworz_lisa(j + 1, i + 1, sila);
			else if (wyglad == OWCA)
				stworz_owce(j + 1, j + 1, sila);
			else if (wyglad == ANTYLOPA)
				stworz_antylope(j + 1, i + 1, sila);
			else if (wyglad == CZLOWIEK)
				stworz_ludzia(j + 1, i + 1, sila, this);
			else if (wyglad == MLECZ)
				stworz_mlecz(j + 1, i + 1);
			else if (wyglad == TRAWKA)
				stworz_trawe(j + 1, i + 1);
			else if (wyglad == WILKU)
				stworz_wilka(j + 1, i + 1, sila);
			else if (wyglad == JAGODA)
				stworz_jagode(j + 1, i + 1);
			else if (wyglad == ZOLWIK)
				stworz_zolwia(j + 1, i + 1, sila);
			else if (wyglad == GUARANA)
				stworz_guarane(j + 1, i + 1);

		}
	}
	plik.close();
}

void Plik::zmien_nazwe()
{
	this->_swiat->gotoxy(45,3);
	cout << "podaj nazwe z rozszerzeniem";
	this->_swiat->gotoxy(45, 4);
	int i = 0;
	char zn;
	while (zn = getchar())
	{
		if (zn == '\n')
			break;
		nazwa[i] = zn;
		this->_swiat->gotoxy(45+i, 4);
		i++;
		cout << zn;
	}
	sprawdz_nazwe(i);
}

void Plik::stworz_lisa(int x, int y, int sila)
{
	Lis *nowy = new Lis(x, y,_swiat,  sila);
}

void Plik::stworz_owce(int x, int y, int sila)
{
	Owca *nowa = new Owca(x, y, _swiat, sila);
}

void Plik::stworz_antylope(int x, int y, int sila)
{
	Antylopa *nowa = new Antylopa(x, y, _swiat, sila);
}

void Plik::stworz_guarane(int x, int y)
{
	Guarana *nowa = new Guarana(x, y, _swiat);
}

void Plik::stworz_ludzia(int x, int y, int sila, Plik *plik)
{
	Ludz *nowy = new Ludz(x, y, _swiat, sila, this);
}

void Plik::stworz_mlecz(int x, int y)
{
	Mlecz *nowy = new Mlecz(x, y, _swiat);
}

void Plik::stworz_trawe(int x, int y)
{
	Trawa *nowa = new Trawa(x, y, _swiat);
}

void Plik::stworz_wilka(int x, int y, int sila)
{
	Wilk *nowy = new Wilk(x, y, _swiat, sila);
}

void Plik::stworz_jagode(int x, int y)
{
	Wjagoda *nowa = new Wjagoda(x, y, _swiat);
}

void Plik::stworz_zolwia(int x, int y, int sila)
{
	Zolw *nowy = new Zolw(x, y, _swiat, sila);
}

void Plik::sprawdz_nazwe(int i) throw(string)
{
	string wyjatek = "wpisz poprawna nazwe";
	if (i<4 || nazwa[i - 1] != 't' || nazwa[i - 2] != 'x' || nazwa[i - 3] != 't' || nazwa[i - 4] != '.')
		throw wyjatek;
}