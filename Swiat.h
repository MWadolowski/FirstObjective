#ifndef _SWIAT_H
#define _SWIAT_H
#include "Organizm.h"
#include "Wilk.h"
#include "Zwierze.h"
#include "Lis.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Ludz.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Wjagoda.h"
#include "dyrektywy.h"
class Swiat
{
	Organizm *tablica[20][20];
	Organizm *kolejka[400];
	int _ilosc;
	int _kopiailosc;

public:
	Swiat();
	~Swiat();
	void rysuj();
	void wykonaj();
	void czysc();
	void czysc_HUD();
	void interfejs();
	void gotoxy(int x, int y);
	void ustaw_gracza(Ludz *gracz);
	bool sprawdz_obecnosc(int x, int y);
	void wyzeruj_pole(int x, int y);
	void przesun(int x, int y, Organizm *kto);
	int okresl_sile(int x, int y);
	char okresl_wyglad(int x, int y);
	void wywolaj_obrone(int x, int y, Organizm *napastnik);
	void ustaw_istote(int x, int y, Organizm *nowy);
	void zabij(Organizm *trup);
	void zabij(int x, int y);
	void skolejkuj(Organizm *nowy);
	int okresl_inicjatywe(int x, int y);
	int okresl_wiek(int x, int y);
	void sortuj();
	void usun_zkolejki(int x, int y);
	void usun_zkolejki(Organizm *trup);
	void ustaw_ilosc_stworzen();
	void skopiuj(Swiat *gdzie, Organizm *kto);
	int ile_zwierzat();
	void postarz(Organizm *kto);
protected:
	void skopcuj(int i, int ilosc);
	int lewy(int i);
	int prawy(int i);
	int mama(int i);
	void zamien(int i, int j);
};
#endif
