#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"
class Zwierze : public Organizm
{
protected:
	int _zasieg;

public:
	virtual void akcja() = 0;

protected:
	virtual void rusz(Zwierze *nowy);
	virtual void ustal_kierunek(int x[], int y[], int *ilosc);
	virtual void mieszaj(int x[], int y[], int ilosc);
};
#endif