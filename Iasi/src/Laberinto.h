/*
 * Laberinto.h
 *
 *  Created on: 26 feb. 2019
 *      Author: usuario
 */

#ifndef LABERINTO_H_
#define LABERINTO_H_
#include "Casilla.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Laberinto {

private:
	Casilla Matrix[10][10];
	int umbral;

public:
Laberinto();
~Laberinto();
	int getUmbral() ;
	void setUmbral(int umbral);
	void GenerarTablero(string laberinto);
	void get0(int &x,int &y);
	Casilla getPos(int x, int y);
	void putExplorado(int x, int y);
	void putVisitado(int x, int y);
	int getValor(int x, int y);
	bool getExplorado(int x, int y);
	bool getVisitado(int x, int y);
	int getH(int x, int y);
	void putH();
	void resetVisitado();

};

#endif /* LABERINTO_H_ */
