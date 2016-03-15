#ifndef MLECZ_H
#define MLECZ_H
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(int x, int y, Swiat *swiat);
	Mlecz(Swiat *swiat);
	~Mlecz();
	void akcja();
};
#endif