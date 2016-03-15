#ifndef GUARANA_H
#define GUARANA_H
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(int x, int y, Swiat *swiat);
	Guarana(Swiat *swiat);
	~Guarana();
	void akcja();
	void kolizja(Organizm *napastnik);
};
#endif
