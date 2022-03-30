#pragma once
/**
 *  file konzol.h
 *  Konzol osztály deklarációja
 */
#ifndef KONZOL_H
#define KONZOL_H

#include <iostream>
#include <cstddef>
#include "kimenet.h"
#include "tabla.h"

using namespace std;

class Konzol: public Kimenet{
	ostream& os;
public:
	Konzol():Kimenet(""), os(std::cout) {};
	Konzol(const char* n, ostream& os):Kimenet(n), os(os) {}
	void Kirajzolas(Tabla t, enum Szin Kovetkezo);
	void RosszLepes(bool FeherJonE);
	void RosszBemenetHossz(bool FeherJonE);
	void RosszBemenetFormatum(bool FeherJonE);
	void Kimarad(bool FeherJonE);
	void Vege(enum Szin Nyertes);
};

#endif // KONZOL_H