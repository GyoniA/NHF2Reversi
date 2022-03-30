#pragma once
/**
 *  file tabla.h
 *  Tabla osztály deklarációja
 */
#include <cstddef>

#ifndef TABLA_H
#define TABLA_H

enum Szin { Ures, Feher, Fekete };

class Tabla {

	size_t dbFeher;

	size_t dbFekete;

	enum Szin Mezok[8][8];
public:
	Tabla();

	size_t getFeher() { return dbFeher; }

	size_t getFekete() { return dbFekete; }

	bool LephetIranyba(enum Szin sz, size_t sor, size_t oszlop, int sorValtozas, int oszlopValtozas, bool forditE);

	bool IranybaKeres(enum Szin sz, enum Szin masik, int sor, int oszlop, int sorValtozas, int oszlopValtozas, bool forditE);

	bool TudLepni(enum Szin sz);

	bool Lepes(enum Szin sz, size_t sor, size_t oszlop, bool forditE);

	void AlapAllapot();

	enum Szin getMezo(size_t sor, size_t oszlop) { return Mezok[sor][oszlop]; }
};

#endif // TABLA_H