/**
 *  \file konozol.cpp
 *  Konzol osztály tagfüggvényeinek megvalósítása
 */
#include "konzol.h"
#include <iomanip>
#include <cstddef>

/**
*  Kirajzolas függvény
*  kirajzolja a medadott pályát
*/
void Konzol::Kirajzolas(Tabla t, enum Szin Kovetkezo) {
	os << endl << endl;
	os << "Feher(O):" << t.getFeher() << ", Fekete(X):" << t.getFekete() << endl;
	os <<  "- A B C D E F G H -" << endl;
	for (size_t i = 0; i < 8; i++)
	{
		os << " " << i+1;
		for (size_t j = 0; j < 8; j++)
		{
			Szin temp = t.getMezo(i, j);
			if (temp == Feher) os  << "O ";
			else if (temp == Fekete) os  << "X ";
			else os <<  "  ";
		}
		os <<  i + 1 << endl;
	}
	os << "- A B C D E F G H -" << endl;
	if (Kovetkezo != Ures) {
		if (Kovetkezo == Feher) os << "A Feher(O) jatekos jon. Lepes(nagybetu szam formatumban):";
		else os << "A Fekete(X) jatekos jon. Lepes(nagybetu szam formatumban):";
	}
}


/**
*  RosszLepes függvény
*  értesíti a jelenleg jövő játékost hogy nem érvényes a lépése
*/
void Konzol::RosszLepes(bool FeherJonE) {
	if (FeherJonE) os << "A megadott lepes nem lehetseges, ujra a Feher(O) jatekos jon. Lepes(nagybetu szam formatumban):";
	else os << "A megadott lepes nem lehetseges, ujra a Fekete(X) jatekos jon. Lepes(nagybetu szam formatumban):";
}

/**
*  RosszBemenetHossz függvény
*  értesíti a jelenleg jövő játékost hogy nem jó mennyiségű karaktert írt be
*/
void Konzol::RosszBemenetHossz(bool FeherJonE) {
	if (FeherJonE) os << "Nem 2db karaktert adott meg, ujra a Feher(O) jatekos jon. Lepes(nagybetu szam formatumban):";
	else os << "Nem 2db karaktert adott meg, ujra a Fekete(X) jatekos jon. Lepes(nagybetu szam formatumban):";
}

/**
*  RosszBemenetFormatum függvény
*  értesíti a jelenleg jövő játékost hogy nem jó formátumban adta meg a lépését
*/
void Konzol::RosszBemenetFormatum(bool FeherJonE) {
	if (FeherJonE) os << "Rossz a lepes formatuma, elso karakter A-H lehet, masodik karakter 1-8 lehet, ujra a Feher(O) jatekos jon. Lepes(nagybetu szam formatumban):";
	else os << "Rossz a lepes formatuma, elso karakter A-H lehet, masodik karakter 1-8 lehet, ujra a Fekete(X) jatekos jon. Lepes(nagybetu szam formatumban):";
}

/**
*  Kimarad függvény
*  értesíti a jelenleg jövő játékost hogy nem tud lépni
*/
void Konzol::Kimarad(bool FeherJonE) {
	if (FeherJonE) os << "A Feher(O) jatekos kimarad mert nem tud lepni." << endl;
	else os << "A Fekete(X) jatekos kimarad mert nem tud lepni." << endl;
}


/**
*  Kirajzolas függvény
*  kirajzolja a medadott pályát
*/
void Konzol::Vege(enum Szin Nyertes) {
	if (Nyertes == Feher) os << "A Feher(O) jatekos nyert!" << endl;
	else if (Nyertes == Fekete) os << "A Fekete(X) jatekos nyert!" << endl;
	else os << "Dontetlen lett a meccs!" << endl;
}