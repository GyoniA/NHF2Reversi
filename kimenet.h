#pragma once
/**
 *  file kimenet.h
 *  Kimenet osztály deklarációja
 */
#ifndef KIMENET_H
#define KIMENET_H

#include <cstddef>
#include "tabla.h"

class Kimenet {
	const char* nev;
public:
	Kimenet(const char* n):nev(n) {};

	/**
	*  Kirajzolas függvény
	*  kirajzolja a medadott pályát
	*/
	virtual void Kirajzolas(Tabla t, enum Szin Kovetkezo) = 0;

	/**
	*  RosszLepes függvény
	*  értesíti a jelenleg jövő játékost hogy nem érvényes a lépése
	*/
	virtual void RosszLepes(bool FeherJonE) = 0;

	/**
	*  RosszBemenetHossz függvény
	*  értesíti a jelenleg jövő játékost hogy nem jó mennyiségű karaktert írt be
	*/
	virtual void RosszBemenetHossz(bool FeherJonE) = 0;

	/**
	*  RosszBemenetFormatum függvény
	*  értesíti a jelenleg jövő játékost hogy nem jó formátumban adta meg a lépését
	*/
	virtual void RosszBemenetFormatum(bool FeherJonE) = 0;

	/**
	*  Kimarad függvény
	*  értesíti a jelenleg jövő játékost hogy nem tud lépni
	*/
	virtual void Kimarad(bool FeherJonE) = 0;

	/**
	*  Kirajzolas függvény
	*  kirajzolja a medadott pályát
	*/
	virtual void Vege(enum Szin Nyertes) = 0;
};

#endif // KIMENET_H