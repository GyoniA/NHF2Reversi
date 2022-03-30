/**
 *  \file tabla.cpp
 *  Tabla osztály tagfüggvényeinek megvalósítása
 */
#include <cstddef>
#include "tabla.h"

Tabla::Tabla() {
	AlapAllapot();
}


/**
 *  LephetIranyba függvény
 *	megnézi hogy üres-e a mező
 *	megnézi a megadott mezőn a megadott irányba hogy arra átfordulna-e korong,
 *	ha átfordulna korong akkor igaz értéket ad vissza azaz lehetséges ez a lépés,
 *  ha forditE igaz akkor meg is fordítja a korongokat abba az irányba
 */
bool Tabla::LephetIranyba(enum Szin sz, size_t sor, size_t oszlop, int sorValtozas, int oszlopValtozas, bool forditE) {
	if (Mezok[sor][oszlop] != Ures)
	{
		return false;
	}
	Szin masik = ((sz == Feher) ? Fekete : Feher);
	int kovSor = sor + sorValtozas;
	int kovOszlop = oszlop + oszlopValtozas;
	if (kovSor > 7 || kovSor < 0 || kovOszlop > 7 || kovOszlop < 0)
	{
		return false;
	}
	if (Mezok[sor + sorValtozas][oszlop + oszlopValtozas] == masik)
	{
		return IranybaKeres(sz, masik, kovSor, kovOszlop, sorValtozas, oszlopValtozas, forditE);
	}
	return false;
}


/**
 *  IranybaKeres függvény
 *	megnézi a megadott mezőn a megadott irányba a korongot, ha sz színű akkor megfordít minden előzőt (ha forditE is igaz) és igazzal tér vissza
 *  ha masik színű akkor tobább megy
 */
bool Tabla::IranybaKeres(enum Szin sz, enum Szin masik, int sor, int oszlop, int sorValtozas, int oszlopValtozas, bool forditE) {
	int kovSor = sor + sorValtozas;
	int kovOszlop = oszlop + oszlopValtozas;
	if (kovSor > 7 || kovSor < 0 || kovOszlop > 7 || kovOszlop < 0)
	{
		return false;
	}
	if (Mezok[kovSor][kovOszlop] == Ures)
	{
		return false;
	}
	if (Mezok[kovSor][kovOszlop] == sz)
	{
		if (forditE)
		{
			Mezok[sor][oszlop] = sz;
			if (sz == Feher) { dbFeher++; dbFekete--; }
			else { dbFekete++; dbFeher--; }
		}
		return true;
	}
	if (IranybaKeres(sz, masik, kovSor, kovOszlop, sorValtozas, oszlopValtozas, forditE))
	{
		if (forditE)
		{
			Mezok[sor][oszlop] = sz;
			if (sz == Feher) { dbFeher++; dbFekete--; }
			else { dbFekete++; dbFeher--; }
		}
		return true;
	}
	return false;
}


/**
 *  TudLepni függvény
 *	megnézi hogy az sz játékosnak van-e lehetséges lépése a jelenlegi táblán
 */
bool Tabla::TudLepni(enum Szin sz) {
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (Lepes(sz, i, j, false)) return true;
		}
	}
	return false;
}


/**
 *  Lepes függvény
 *	megnézi hogy üres-e a mező
 *	végignézi a megadott mezőn a lehetséges nyolc irányba hogy arra átfordulna-e korong
 *	ha átfordulna korong akkor igaz értéket ad vissza azaz lehetséges ez a lépés
 *  ha forditE igaz akkor meg is fordítja a korongokat és lerakja a lépést
 */
bool Tabla::Lepes(enum Szin sz, size_t sor, size_t oszlop, bool forditE) {
	if (!forditE)
	{
		return (LephetIranyba(sz, sor, oszlop, 0, 1, forditE)/*dél*/ || LephetIranyba(sz, sor, oszlop, -1, 1, forditE)/*délnyugat*/
			|| LephetIranyba(sz, sor, oszlop, -1, 0, forditE)/*nyugat*/ || LephetIranyba(sz, sor, oszlop, -1, -1, forditE)/*északnyugat*/
			|| LephetIranyba(sz, sor, oszlop, 0, -1, forditE)/*észak*/ || LephetIranyba(sz, sor, oszlop, 1, -1, forditE)/*északkelet*/
			|| LephetIranyba(sz, sor, oszlop, 1, 0, forditE)/*kelet*/ || LephetIranyba(sz, sor, oszlop, 1, 1, forditE)/*délkelet*/);
	}
	if (LephetIranyba(sz, sor, oszlop, 0, 1, forditE)/*dél*/ | LephetIranyba(sz, sor, oszlop, -1, 1, forditE)/*délnyugat*/
		| LephetIranyba(sz, sor, oszlop, -1, 0, forditE)/*nyugat*/ | LephetIranyba(sz, sor, oszlop, -1, -1, forditE)/*északnyugat*/
		| LephetIranyba(sz, sor, oszlop, 0, -1, forditE)/*észak*/ | LephetIranyba(sz, sor, oszlop, 1, -1, forditE)/*északkelet*/
		| LephetIranyba(sz, sor, oszlop, 1, 0, forditE)/*kelet*/ | LephetIranyba(sz, sor, oszlop, 1, 1, forditE)/*délkelet*/)
	{
		Mezok[sor][oszlop] = sz;
		if (sz == Feher) dbFeher++;
		else dbFekete++;
		return true;
	}
	return false;
}


/**
 *  AlapAllapot függvény
 *	alapvető állapotba rakja a táblát 
 */
void Tabla::AlapAllapot() {
	dbFeher = 2;
	dbFekete = 2;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			Mezok[i][j] = Ures;
		}
	}
	Mezok[3][3] = Feher;
	Mezok[3][4] = Fekete;
	Mezok[4][4] = Feher;
	Mezok[4][3] = Fekete;

}
