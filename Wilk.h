#ifndef WILK_H
#define WILK_H
#include "Zwierze.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(int x, int y, Swiat *swiat);
	Wilk(Swiat *swiat);
	Wilk(int x, int y, Swiat *swiat, int sila);
	~Wilk();
	void akcja();
};
#endif