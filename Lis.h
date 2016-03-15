#ifndef LIS_H
#define LIS_H
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis(int x, int y, Swiat *swiat);
	Lis(Swiat *swiat);
	Lis(int x, int y, Swiat *swiat, int sila);
	~Lis();
	void akcja();
	void kolizja(Organizm *napastnik);
};
#endif