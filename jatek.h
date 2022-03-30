#pragma once
/**
 *  file jatek.h
 *  Jatek osztály deklarációja
 */
#ifndef JATEK_H
#define JATEK_H

#include <iostream>
#include <cstddef>
#include "tabla.h"
#include "kimenet.h"

class Jatek {

	bool FeherJonE;

	size_t FeherNyeresei;

	size_t FeketeNyeresei;

	Tabla T;

	Kimenet *ki;

	std::istream &bemenet;
public:
	Jatek(Kimenet *ki, std::istream &be) :ki(ki), bemenet(be) {
		FeherNyeresei = 0;
		FeketeNyeresei = 0;
	}
	void BemenetEllenorzessel(size_t &sor, size_t &oszlop, std::istream &is);
	void Start();
};

#endif // JATEK_H