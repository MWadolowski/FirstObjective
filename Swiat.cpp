#include "Swiat.h"


Swiat::Swiat()
{
	_ilosc = 0;
	_kopiailosc = 0;
	for (int i = 0; i < ILOSC; i++)
	{
		for (int j = 0; j < ILOSC; j++)
		{
			tablica[i][j] = NULL;
		}
	}
}

Swiat::~Swiat()
{
	cout << "game over";
}

void Swiat::rysuj()
{
	gotoxy(50, 10);
	cout << _kopiailosc << " " << _ilosc;
	for (int i = 0; i < ILOSC; i++)
	{
		for (int k = 0; k < ILOSC; k++)
		{
			if (tablica[i][k] != NULL)
				tablica[i][k]->rysuj();
		}
	}
}

void Swiat::wykonaj()
{
	for (int i = 0; i < _ilosc; i++)
	{
		{
			if (i <= 400)
			{
				if (kolejka[i] != NULL)
				{
					kolejka[i]->akcja();
				}
			}

		}
	}
}

void Swiat::czysc()
{
	gotoxy(1, 1);
	for (int i = 0; i < ILOSC; i++)
	{
		cout << "--------------------" << endl;
	}
}

void Swiat::czysc_HUD()
{
	//dokoñczyæ
}

void Swiat::interfejs()
{
	gotoxy(1, 21);
	cout << "wilk: " << WILKU << "		owca: " << OWCA << endl;
	cout << "lis: " << LISEK << "		antylopa: " << ANTYLOPA << endl;
	cout << "zolw: " << ZOLWIK << endl;
	cout << "trawa: " << TRAWKA << "	w.jagoda: " << JAGODA << endl;
	cout << "guarana: " << GUARANA << "	mlecz: " << MLECZ << endl;
}

void Swiat::gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Swiat::ustaw_gracza(Ludz *gracz)
{
	tablica[gracz->gdzie_x()-1][gracz->gdzie_y()-1] = gracz;
}

bool Swiat::sprawdz_obecnosc(int x, int y)
{
	if (tablica[x - 1][y - 1] != NULL)
		return true;
	else return false;
}

void Swiat::wyzeruj_pole(int x, int y)
{
	tablica[x - 1][y - 1] = NULL;
}

void Swiat::przesun(int x, int y, Organizm *kto)
{
	tablica[x - 1][y - 1] = kto;
}

int Swiat::okresl_sile(int x, int y)
{
	return tablica[x - 1][y - 1]->okresl_sile();
}

char Swiat::okresl_wyglad(int x, int y)
{
	return tablica[x - 1][y - 1]->okresl_wyglad();
}

void Swiat::wywolaj_obrone(int x, int y, Organizm *napastnik)
{
	tablica[x - 1][y - 1]->kolizja(napastnik);
}

void Swiat::ustaw_istote(int x, int y, Organizm *nowy)
{
	tablica[x - 1][y - 1] = nowy;
}

void Swiat::zabij(Organizm *trup)
{
	usun_zkolejki(trup);
	delete trup;
}

void Swiat::zabij(int x, int y)
{
	this->zabij(tablica[x - 1][y - 1]);
}

void Swiat::skolejkuj(Organizm *nowy)
{
	kolejka[_kopiailosc] = nowy;
	if (_kopiailosc < 400)
		_kopiailosc++;
}

int Swiat::okresl_inicjatywe(int x, int y)
{
	return tablica[x - 1][y - 1]->okresl_inicjatywe();
}

int Swiat::okresl_wiek(int x, int y)
{
	return tablica[x - 1][y - 1]->okresl_wiek();
}

void Swiat::sortuj()
{
	for (int i = _ilosc - 1; i >= 0; i--)
	{
		skopcuj(i, _ilosc);
		postarz(kolejka[i]);
	}
}

void Swiat::usun_zkolejki(int x, int y)
{
	usun_zkolejki(tablica[x - 1][y - 1]);
}

void Swiat::usun_zkolejki(Organizm *trup)
{
	for (int i = 0; i < ILOSC*ILOSC; i++)
	{
		if (kolejka[i] == trup)
		{
			_ilosc--;
			_kopiailosc--;
			kolejka[i] = NULL;
			for (int j = i; j < 400-1; j++)
			{
				kolejka[j] = kolejka[j + 1];
			}
			break;
		}
	}
}

void Swiat::ustaw_ilosc_stworzen()
{
	_ilosc = _kopiailosc;
}

void Swiat::skopiuj(Swiat *gdzie, Organizm *kto)
{
	if (gdzie->sprawdz_obecnosc(kto->gdzie_x(), kto->gdzie_y()))
	{
		gdzie->ustaw_istote(kto->gdzie_x(), kto->gdzie_y(),kto);
		usun_zkolejki(kto);
		wyzeruj_pole(kto->gdzie_x(), kto->gdzie_y());
		gdzie->skolejkuj(kto);
	}
}

int Swiat::ile_zwierzat()
{
	return _kopiailosc;
}

void Swiat::postarz(Organizm *kto)
{
	kto->postarz();
}

int Swiat::lewy(int i)
{
	return i * 2;
}

int Swiat::prawy(int i)
{
	return i * 2 + 1;
}

int Swiat::mama(int i)
{
	return i / 2;
}

void Swiat::zamien(int i, int j)
{
	Organizm *temp;
	temp = kolejka[i];
	kolejka[i] = kolejka[j];
	kolejka[j] = temp;
}

void Swiat::skopcuj(int i, int ilosc)
{
	int duza;
	int p = prawy(i), l = lewy(i), rodzic = mama(i);
	if (l<ilosc && (kolejka[l]->okresl_inicjatywe() > kolejka[i]->okresl_inicjatywe() || (kolejka[l]->okresl_inicjatywe()==kolejka[i]->okresl_inicjatywe() && kolejka[l]->okresl_wiek()>kolejka[i]->okresl_wiek())))
		duza = l;
	else duza = i;
	if (p<ilosc && (kolejka[p]->okresl_inicjatywe() > kolejka[duza]->okresl_inicjatywe() || (kolejka[p]->okresl_inicjatywe() == kolejka[duza]->okresl_inicjatywe() && kolejka[p]->okresl_wiek()>kolejka[duza]->okresl_wiek())))
		duza = p;
	if (duza != i)
	{
		zamien(i, duza);
		skopcuj(duza, ilosc);
	}
}
