#ifndef ANTYLOPA_H
#define ANTYLOPA_H
#include "Zwierze.h"
class Antylopa : public Zwierze
{
public:
	Antylopa(int x, int y, Swiat *swiat);
	Antylopa(Swiat *swiat);
	Antylopa(int x, int y, Swiat *swiat, int sila);
	~Antylopa();
	void akcja();
	void kolizja(Organizm *napastnik);
};
#endif
