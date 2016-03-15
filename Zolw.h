#ifndef ZOLW_H
#define ZOLW_H
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(int x, int y, Swiat *swiat);
	Zolw(Swiat *swiat);
	Zolw(int x, int y, Swiat *swiat, int sila);
	~Zolw();
	void akcja();
	void kolizja(Organizm *napastnik);
};
#endif