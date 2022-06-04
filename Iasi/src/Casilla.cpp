/*
 * Casilla.cpp
 *
 *  Created on: 4 mar. 2019
 *      Author: usuario
 */

#include "Casilla.h"

Casilla::Casilla() {
	h=0;
	valor=0;
	explorado=false;
	visitado= false;

}

bool Casilla::isExplorado()  {
	return explorado;
}

void Casilla::setExplorado(bool explorado) {
	this->explorado = explorado;
}

bool Casilla::getVisitado()  {
	return visitado;
}

void Casilla::setVisitado(bool visitado) {
	this->visitado = visitado;
}

int Casilla::getH() {
	return h;
}

void Casilla::setH(int h) {
	this->h = h;
}

int Casilla::getValor() {
	return valor;
}

void Casilla::setValor(int valor) {
	this->valor = valor;
}

Casilla::~Casilla() {
	// TODO Auto-generated destructor stub
}

