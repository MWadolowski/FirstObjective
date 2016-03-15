#ifndef LUDZ_H
#define LUDZ_H
#include "Calopalenie.h"
#include "Zwierze.h"
#include"Plik.h"
#include <conio.h>
class Ludz : public Zwierze
{
	Plik *_plik;
	Supermoc *moc;
public:
	Ludz(Swiat *swiat, Plik *plik);
	Ludz(int x, int y, Swiat *swiat, int sila, Plik *plik);
	Ludz(int x, int y, Swiat *swiat, Plik *plik);
	~Ludz();
	void akcja();
	void gdzie();
};
#endif