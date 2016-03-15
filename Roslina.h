#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	virtual void akcja() = 0;
	virtual void kolizja(Organizm *napastnik);
protected:
	virtual void rozmnoz(Roslina *nowy);
};
#endif