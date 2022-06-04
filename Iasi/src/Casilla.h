/*
 * Casilla.h
 *
 *  Created on: 4 mar. 2019
 *      Author: usuario
 */

#ifndef CASILLA_H_
#define CASILLA_H_

class Casilla {
	int h;
	int valor;
	bool explorado;
	bool visitado;
public:
	Casilla();
	~Casilla();
	bool isExplorado() ;
	void setExplorado(bool explorado);
	bool getVisitado();
	void setVisitado(bool visitado);
	int getH();
	void setH(int h);
	int getValor();
	void setValor(int valor);
};

#endif /* CASILLA_H_ */
