#include "Ludz.h"
#include "Swiat.h"
Ludz::Ludz(Swiat *swiat, Plik *plik)
{
	_plik = plik;
	_swiat = swiat;
	_sila = 5;
	_inicjatywa = 4;
	_x = 10;
	_y = 10;
	_wiek = 0;
	_zasieg = 1;
	wyglad = '#';
	this->_swiat->ustaw_gracza(this);
	this->_swiat->skolejkuj(this);
	moc = new Calopalenie(this);
}

Ludz::Ludz(int x, int y, Swiat *swiat, int sila, Plik *plik)
{
	_plik = plik;
	_swiat = swiat;
	_sila = sila;
	_inicjatywa = 4;
	_x = x;
	_y = y;
	_wiek = 0;
	_zasieg = 1;
	wyglad = '#';
	this->_swiat->ustaw_gracza(this);
	this->_swiat->skolejkuj(this);
	moc = new Calopalenie(this);
}

Ludz::Ludz(int x, int y, Swiat *swiat, Plik *plik)
{
	_plik = plik;
	_swiat = swiat;
	_sila = 5;
	_inicjatywa = 4;
	_x = x;
	_y = y;
	_wiek = 0;
	_zasieg = 1;
	wyglad = '#';
	this->_swiat->skolejkuj(this);
	moc = new Calopalenie(this);
}

Ludz::~Ludz()
{
	cout << "smierc";
	delete moc;
}

void Ludz::akcja()
{
	gdzie();
	_swiat->czysc();
	_swiat->rysuj();
	rysuj();
	int nowy_x = _x;
	int nowy_y = _y;
	int zn = _getch();
	if (_kbhit())
	{
		zn = _getch();
		if (zn == 0x48 && _y > 1)
			nowy_y--;
		else if (zn == 0x50 && _y<20)
			nowy_y++;
		else if (zn == 0x4b && _x>1)
			nowy_x--;
		else if (zn == 0x4d && _x < 20)
			nowy_x++;
	}
	if (zn == 'h' && !moc->sprawdz_aktywnosc() && moc->zwroc_cd() == 0)
		moc->zmien_aktywnosc();
	if (zn == 's')
		_plik->zapisz();
	moc->akcja();
	if (this->_swiat->sprawdz_obecnosc(nowy_x, nowy_y) && (_x != nowy_x || _y != nowy_y))
	{
		this->_swiat->wywolaj_obrone(nowy_x, nowy_y, this);
	}
	else
	{
		this->_swiat->wyzeruj_pole(_x, _y);
		this->_swiat->przesun(nowy_x, nowy_y, this);
		_x = nowy_x;
		_y = nowy_y;
	}
	moc->wykonaj_bezwzglednie();
}

void Ludz::gdzie()
{
	gotoxy(25, 3);
	cout << "x: " << _x<<"  ";
	gotoxy(25, 4);
	cout << "y: " << _y<<"  ";
	gotoxy(25, 5);
	cout << "aktywnosc: " << moc->sprawdz_aktywnosc();
	gotoxy(25, 6);
	cout << "czas: " << moc->zwroc_czas();
	gotoxy(25, 7);
	cout << "cd: " << moc->zwroc_cd();
	//gotoxy(45, 3);
	//cout << "cos";
}