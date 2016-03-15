#ifndef OWCA_H
#define OWCA_H
#include "Zwierze.h"
class Owca :
	public Zwierze
{
public:
	Owca(int x, int y, Swiat *nowy);
	Owca(Swiat *nowy);
	Owca(int x, int y, Swiat *swiat, int sila);
	~Owca();
	void akcja();
};
#endif