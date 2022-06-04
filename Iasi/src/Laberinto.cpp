/*
 * Laberinto.cpp
 *
 *  Created on: 26 feb. 2019
 *      Author: usuario
 */

#include "Laberinto.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

Laberinto::Laberinto() {
	this->umbral=0;


}

Laberinto::~Laberinto() {

}



int Laberinto::getUmbral()  {
	return umbral;
}

void Laberinto::setUmbral(int umbral) {
	this->umbral = umbral;
}

void Laberinto::GenerarTablero(string laberinto) {


string aux;


		int i=0;int j=0;
		ifstream flujoxd;
		if(laberinto=="laberinto1.txt"){
			flujoxd.open("laberinto1.txt");
		}
		if(laberinto=="laberinto2.txt"){
			flujoxd.open("laberinto2.txt");
		}
		if(laberinto=="laberinto3.txt"){
			flujoxd.open("laberinto3.txt");
		}
		if(laberinto=="laberinto4.txt"){
			flujoxd.open("laberinto4.txt");
		}
		if(laberinto=="laberinto5.txt"){
			flujoxd.open("laberinto5.txt");
		}
		if(laberinto=="laberinto6.txt"){
			flujoxd.open("laberinto6.txt");
		}
		if(laberinto=="laberinto7.txt"){
			flujoxd.open("laberinto7.txt");
		}
		if(laberinto=="laberinto8.txt"){
			flujoxd.open("laberinto8.txt");
		}
		if(laberinto=="laberinto9.txt"){
			flujoxd.open("laberinto9.txt");
		}
		if(laberinto=="laberinto10.txt"){
			flujoxd.open("laberinto10.txt");
		}
		if(laberinto=="laberinto11.txt"){
			flujoxd.open("laberinto11.txt");
		}
		if(laberinto=="laberinto12.txt"){
			flujoxd.open("laberinto12.txt");
		}
		if(laberinto=="laberinto13.txt"){
			flujoxd.open("laberinto13.txt");
		}
		if(laberinto=="laberinto14.txt"){
			flujoxd.open("laberinto14.txt");
		}
			if (flujoxd.is_open()) {
				getline(flujoxd, aux);
				this->umbral=atoi(aux.c_str());
				while (!flujoxd.eof()) {
					if (j==10){
						getline(flujoxd, aux);
					}
					if (!flujoxd.eof()) {//Para que no pase uno vacío.
						for( i =0; i<9; i++){
							getline(flujoxd, aux, ',');

							this->Matrix[j][i].setValor(atoi(aux.c_str()));
						}

						getline(flujoxd, aux);
						this->Matrix[j][i].setValor(atoi(aux.c_str()));
						j++;
					}

				}
				cout<<"Laberinto generado"<< endl;
				flujoxd.close();
			} else
				cout << "Error al abrir el fichero." << endl;

}

void Laberinto::get0(int& x, int& y) {
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(this->Matrix[i][j].getValor()==0){
				x=i;y=j;
			}
		}
	}

}

void Laberinto:: putH(){
	int x, y;
	get0(x,y);
	for(int j=0; j<10; j++){
		for(int i=0; i<10; i++){
			this->Matrix[j][i].setH(abs(i-y)+abs(j-x));
		}
	}
}

Casilla Laberinto::getPos(int x, int y){
	return Matrix[x][y];
}

void Laberinto:: putExplorado(int x, int y){
	Matrix[x][y].setExplorado(true);
}

void Laberinto:: putVisitado(int x, int y){
	Matrix[x][y].setVisitado(true);
}

int Laberinto:: getValor(int x, int y){
	return Matrix[x][y].getValor();
}

int Laberinto:: getH(int x, int y){
	return Matrix[x][y].getH();
}

bool Laberinto:: getExplorado(int x, int y){
	return Matrix[x][y].isExplorado();
}

bool Laberinto:: getVisitado(int x, int y){
	return Matrix[x][y].getVisitado();
}

void Laberinto:: resetVisitado(){
	for(int j=0; j<10; j++){
		for(int i=0; i<10; i++){
			this->Matrix[j][i].setVisitado(false);
		}
	}
}
