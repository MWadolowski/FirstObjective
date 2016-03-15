#include "Swiat.h"
#include "Plik.h"

using namespace std;
int main(){
	int licznik = 1;
	Swiat *gra = new Swiat;
	Swiat *zapas = new Swiat;
	gra->interfejs();
	Plik *nowy = new Plik(gra);
	//nowy->otworz();
	Mlecz *mleczyk = new Mlecz(4, 4, gra);
	Ludz *moj = new Ludz(1, 2, gra, nowy);
	Wilk *nowa = new Wilk(6, 6, gra);
	Wilk *nowa2 = new Wilk(6, 7, gra);
	Wilk *nowa3 = new Wilk(6, 8, gra);
	Lis *lis1 = new Lis(4, 5, gra);
	Lis *lis2 = new Lis(5, 5, gra);
	Trawa *terawa = new Trawa(1, 3, gra);
	Guarana *g = new Guarana(9, 9, gra);
	Wjagoda *jagoda = new Wjagoda(10, 10, gra);
	Zolw *zolw = new Zolw(11, 11, gra);
	Zolw *z2 = new Zolw(11, 12, gra);
	Antylopa *k1 = new Antylopa(15, 15, gra);
	Antylopa *k4 = new Antylopa(15, 17, gra);
	Owca *ggg = new Owca(20, 19, gra);
	Owca *u4 = new Owca(19, 20, gra);
	gra->ustaw_ilosc_stworzen();
	while (true)
	{
		gra->gotoxy(1,1);
		gra->czysc();
		gra->rysuj();
		gra->gotoxy(25, 8);	
		cout << licznik;
		licznik++;
		gra->wykonaj();
		gra->ustaw_ilosc_stworzen();
		gra->sortuj();
		gra->ustaw_ilosc_stworzen();
		//gra->czysc();
		//gra->rysuj();
	}
	delete nowy;
	return 0;
}