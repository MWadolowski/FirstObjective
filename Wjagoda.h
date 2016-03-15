#ifndef WJAGODA_H
#define WJAGODA_H
#include "Roslina.h"
class Wjagoda :
	public Roslina
{
public:
	Wjagoda(int x, int y, Swiat *swiat);
	Wjagoda(Swiat *swiat);
	Wjagoda(Swiat *swiat, int x);
	~Wjagoda();
	void akcja();
	void kolizja(Organizm *napastnik);
};
#endif