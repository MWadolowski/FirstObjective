#ifndef TRAWA_H
#define TRAWA_H
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(int x, int y, Swiat *swiat);
	Trawa(Swiat *swiat);
	~Trawa();
	void akcja();
};
#endif