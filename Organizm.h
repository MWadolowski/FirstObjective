#pragma once
#ifndef Organizm_H
#define Organizm_H
#include <iostream>
#include <windows.h>
#include <time.h>
#include "dyrektywy.h"
class Swiat;
using namespace std;
class Organizm
{
protected:
	int _sila, _x, _y, _inicjatywa, _wiek;
	char wyglad;
	Swiat *_swiat;

public:
	virtual void akcja() = 0;
	virtual void kolizja(Organizm *napastnik);
	virtual void rysuj() final;
	virtual void gotoxy(int x, int y) final;
	virtual int gdzie_x() final;
	virtual int gdzie_y() final;
	virtual int okresl_sile() final;
	virtual char okresl_wyglad() final;
	virtual int okresl_inicjatywe() final;
	virtual int okresl_wiek();
	virtual void ustaw_x_y(int x, int y) final;
	virtual bool spytaj_obecnosc(int x, int y);
	virtual void popros_odkolejkowanie(int x, int y);
	virtual void popros_wyzerowanie(int x, int y);
	virtual void zabij(int x, int y);
	virtual void grow_stronger();
	void postarz();

protected:
	virtual void walcz(Organizm *napastnik) final;
	virtual void rozmnoz(Organizm *nowy) final;

};
#endif
