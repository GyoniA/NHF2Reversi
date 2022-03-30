/**
 *  \file jatek.cpp
 *  Jatek osztály tagfüggvényeinek megvalósítása
 */
#include "jatek.h"
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

/**
 *	BemenetEllenorzessel függvény
 *	a megadott bemenetről beolvas egy sor és oszlop értéket,
 *	ezeket a megadott size_t változókba rakja,
 *	ha nem jó, akkor addig kérdez, amíg jót nem ad a felhasználó
 */
void Jatek::BemenetEllenorzessel(size_t &sor, size_t &oszlop, std::istream &is) {
	string tempBemenet;
	is >> tempBemenet;
	while (tempBemenet.size() != 2)
	{
		ki->RosszBemenetHossz(FeherJonE);
		is >> tempBemenet;
	}
	oszlop = tempBemenet[0] - 65;
	sor = tempBemenet[1] - 48 - 1;
	
	while (oszlop < 0 || oszlop > 7 || sor < 0 || sor > 7)
	{
		ki->RosszBemenetFormatum(FeherJonE);
		is >> tempBemenet;
		while (tempBemenet.size() != 2)
		{
			ki->RosszBemenetHossz(FeherJonE);
			is >> tempBemenet;
		}
		oszlop = tempBemenet[0] - 65;
		sor = tempBemenet[1] - 48 - 1;
	}
}

/**
 *	Start függvény
 *	elindít egy játékot üres táblával
 *	és a Jatek kimenetere ábrázolja
 *	a játékosok lépéseit a konzolról olvassa be
 */
void Jatek::Start() {
	FeherJonE = false;
	T.AlapAllapot();
	enum Szin szin;
	enum Szin masik;
	size_t sor;
	size_t oszlop;
	bool TudnakLepni = true;
	while (T.getFeher() + T.getFekete() < 64 && TudnakLepni)
	{
		if (FeherJonE) { szin = Feher; masik = Fekete; }
		else { szin = Fekete; masik = Feher; }
		if (T.TudLepni(szin)) {
			ki->Kirajzolas(T, szin);
			BemenetEllenorzessel(sor, oszlop, bemenet);
			while (!T.Lepes(szin, sor, oszlop, true))
			{
				ki->RosszLepes(FeherJonE);
				BemenetEllenorzessel(sor, oszlop, bemenet);
			}
		}
		else if (T.TudLepni(masik))
		{
			ki->Kimarad(FeherJonE);
		}
		else {
			TudnakLepni = false;
		}

		FeherJonE = !FeherJonE;
	}
	ki->Kirajzolas(T, Ures);
	if (T.getFeher() > T.getFekete()) {
		ki->Vege(Feher);
		FeherNyeresei++;
	}
	else if (T.getFeher() < T.getFekete()) {
		ki->Vege(Fekete);
		FeketeNyeresei++;
	}
	else ki->Vege(Ures);
}
