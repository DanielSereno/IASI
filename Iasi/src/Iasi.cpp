//============================================================================
// Name        : Iasi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "timer.h"
#include "Laberinto.h"
using namespace std;

void generacionYPrueba(Laberinto lab, int gasto, int pos, bool encontrado, double &t_start, double &t_end){
	char sol [100];
	t_start = Time::getTime();
	t_end = Time::getTime();
	bool nodos [10][10];
	for (int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			nodos[i][j]=false;
		}
	}
	encontrado=false;
	bool hayposibilidades=true;
	gasto=0;
	int umbral= lab.getUmbral();
	int x, y, random, xposible, yposible;
	x=0;
	y=0;
	pos=0;
	while(!encontrado && hayposibilidades&&(t_end-t_start)<2 ){
		if(gasto<= umbral){
			if(x==0){
				if(y==0){
					lab.putVisitado(x, y);
					xposible= x;
					yposible= y;
					if((!lab.getExplorado(x+1, y)&& !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
						while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
							random= rand() %2;
							if(random==0){
								xposible= x;
								yposible= y+1;
								sol[pos]= 'E';
							}
							else{
								xposible= x+1;
								yposible= y;
								sol[pos]= 'S';
							}
						}
						pos++;
						x= xposible;
						y= yposible;
						lab.putVisitado(x,y);
						nodos[x][y]=true;
						gasto= gasto+ lab.getValor(x, y);
						if(lab.getValor(x, y)==0)
							encontrado=true;
						if(lab.getValor(x, y)>6){
							lab.putExplorado(x, y);
							pos=0;
							x=0;
							y=0;
							gasto= 0;
							lab.resetVisitado();
						}
						t_end = Time::getTime();
					}
					else{
						hayposibilidades=false;
					}
				}
				else{
					if(y==9){
						xposible= x;
						yposible= y;
						if((!lab.getExplorado(x+1, y) && !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y-1)  && !lab.getVisitado(x, y-1))){
							while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
								random= rand() %2;
								if(random==0){
									xposible= x;
									yposible= y-1;
									sol[pos]= 'O';
								}
								else{
									xposible= x+1;
									yposible= y;
									sol[pos]= 'S';
								}
							}
							pos++;
							x= xposible;
							y= yposible;
							lab.putVisitado(x,y);
							nodos[x][y]=true;
							gasto= gasto+ lab.getValor(x, y);
							if(lab.getValor(x, y)==0)
								encontrado=true;
							if(lab.getValor(x, y)>6){
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
							}
							t_end = Time::getTime();
						}
						else{
							lab.putExplorado(x, y);
							pos=0;
							x=0;
							y=0;
							gasto= 0;
							lab.resetVisitado();
							t_end = Time::getTime();
						}
					}
					else{
						xposible= x;
						yposible= y;
						if((!lab.getExplorado(x+1, y) && !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y-1) && !lab.getVisitado(x, y-1)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
							while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
								random= rand() %3;
								if(random==0){
									xposible= x;
									yposible= y-1;
									sol[pos]= 'O';
								}
								else{
									if(random==1){
										xposible= x+1;
										yposible= y;
										sol[pos]= 'S';
									}
									else{
										xposible= x;
										yposible= y+1;
										sol[pos]= 'E';
									}
								}
							}
							pos++;
							x= xposible;
							y= yposible;
							lab.putVisitado(x,y);
							nodos[x][y]=true;
							gasto= gasto+ lab.getValor(x, y);
							if(lab.getValor(x, y)==0)
								encontrado=true;
							if(lab.getValor(x, y)>6){
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
							}
							t_end = Time::getTime();
						}
						else{
							lab.putExplorado(x, y);
							pos=0;
							x=0;
							y=0;
							gasto= 0;
							lab.resetVisitado();
							t_end = Time::getTime();
						}
					}
				}
			}
			else{
				if(x==9){
					if(y==0){
						xposible= x;
						yposible= y;
						if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
							while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
								random= rand() %2;
								if(random==0){
									xposible= x;
									yposible= y+1;
									sol[pos]= 'E';
								}
								else{
									xposible= x-1;
									yposible= y;
									sol[pos]= 'N';
								}
							}
							pos++;
							x= xposible;
							y= yposible;
							lab.putVisitado(x,y);
							nodos[x][y]=true;
							gasto= gasto+ lab.getValor(x, y);
							if(lab.getValor(x, y)==0)
								encontrado=true;
							if(lab.getValor(x, y)>6){
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
							}
							t_end = Time::getTime();
						}
						else{
							lab.putExplorado(x, y);
							pos=0;
							x=0;
							y=0;
							gasto= 0;
							lab.resetVisitado();
							t_end = Time::getTime();
						}
					}
					else{
						if(y==9){
							xposible= x;
							yposible= y;
							if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x, y-1) && !lab.getVisitado(x, y-1))){
								while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
										random= rand() %2;
										if(random==0){
											xposible= x;
											yposible= y-1;
											sol[pos]= 'O';
										}
										else{
											xposible= x-1;
											yposible= y;
											sol[pos]= 'N';
										}
									}
									pos++;
									x= xposible;
									y= yposible;
									lab.putVisitado(x,y);
									nodos[x][y]=true;
									gasto= gasto+ lab.getValor(x, y);
									if(lab.getValor(x, y)==0)
										encontrado=true;
									if(lab.getValor(x, y)>6){
										lab.putExplorado(x, y);
										pos=0;
										x=0;
										y=0;
										gasto= 0;
										lab.resetVisitado();
									}
									t_end = Time::getTime();
							}
							else{
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
								t_end = Time::getTime();
							}
						}
						else{
							xposible= x;
							yposible= y;
							if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x, y-1) && !lab.getVisitado(x, y-1)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
								while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
									random= rand() %4;
									if(random==0){
										xposible= x;
										yposible= y-1;
										sol[pos]= 'O';
									}
									else{
										if(random==1){
											xposible= x;
											yposible= y+1;
											sol[pos]= 'E';
										}
										else{
											xposible= x-1;
											yposible= y;
											sol[pos]= 'N';
										}
									}
								}
								pos++;
								x= xposible;
								y= yposible;
								lab.putVisitado(x,y);
								nodos[x][y]=true;
								gasto= gasto+ lab.getValor(x, y);
								if(lab.getValor(x, y)==0)
									encontrado=true;
								if(lab.getValor(x, y)>6){
									lab.putExplorado(x, y);
									pos=0;
									x=0;
									y=0;
									gasto= 0;
									lab.resetVisitado();
								}
								t_end = Time::getTime();
							}
							else{
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
								t_end = Time::getTime();
							}
						}
					}
				}
				else{
					if(y==0){
						xposible= x;
						yposible= y;
						if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x+1, y) && !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
							while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
								random= rand() %3;
								if(random==0){
									xposible= x+1;
									yposible= y;
									sol[pos]= 'S';
								}
								else{
									if(random==1){
										xposible= x;
										yposible= y+1;
										sol[pos]= 'E';
									}
									else{
										xposible= x-1;
										yposible= y;
										sol[pos]= 'N';

									}
								}
							}
							pos++;
							x= xposible;
							y= yposible;
							lab.putVisitado(x,y);
							nodos[x][y]=true;
							gasto= gasto+ lab.getValor(x, y);
							if(lab.getValor(x, y)==0)
								encontrado=true;
							if(lab.getValor(x, y)>6){
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
							}
							t_end = Time::getTime();
						}
						else{
							lab.putExplorado(x, y);
							pos=0;
							x=0;
							y=0;
							gasto= 0;
							lab.resetVisitado();
							t_end = Time::getTime();
						}
					}
					else{
						if(y==9){
							xposible= x;
							yposible= y;
							if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x+1, y) && !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y-1) && !lab.getVisitado(x, y-1))){
								while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
									random= rand() %3;
									if(random==0){
										xposible= x;
										yposible= y-1;
										sol[pos]= 'O';
									}
									else{
										if(random==1){
											xposible= x+1;
											yposible= y;
											sol[pos]= 'S';
										}
										else{
											xposible= x-1;
											yposible= y;
											sol[pos]= 'N';
										}
									}
								}
								pos++;
								x= xposible;
								y= yposible;
								lab.putVisitado(x,y);
								nodos[x][y]=true;
								gasto= gasto+ lab.getValor(x, y);
								if(lab.getValor(x, y)==0)
									encontrado=true;
								if(lab.getValor(x, y)>6){
									lab.putExplorado(x, y);
									pos=0;
									x=0;
									y=0;
									gasto= 0;
									lab.resetVisitado();
								}
								t_end = Time::getTime();
							}
							else{
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
								t_end = Time::getTime();
							}
						}
						else{
							xposible= x;
							yposible= y;
							if((!lab.getExplorado(x-1, y) && !lab.getVisitado(x-1, y)) || (!lab.getExplorado(x+1, y) && !lab.getVisitado(x+1, y)) || (!lab.getExplorado(x, y-1) && !lab.getVisitado(x, y-1)) || (!lab.getExplorado(x, y+1) && !lab.getVisitado(x, y+1))){
								while((lab.getExplorado(xposible, yposible)|| lab.getVisitado(xposible, yposible)) || (xposible==x && yposible==y)){
									random= rand() %4;
									if(random==0){
										xposible= x;
										yposible= y-1;
										sol[pos]= 'O';
									}
									else{
										if(random==1){
											xposible= x+1;
											yposible= y;
											sol[pos]= 'S';
										}
										else{
											if(random==2){
												xposible= x;
												yposible= y+1;
												sol[pos]= 'E';
											}
											else{
												xposible= x-1;
												yposible= y;
												sol[pos]= 'N';
											}
										}
									}
								}
								pos++;
								x= xposible;
								y= yposible;
								lab.putVisitado(x,y);
								nodos[x][y]=true;
								gasto= gasto+ lab.getValor(x, y);
								if(lab.getValor(x, y)==0)
									encontrado=true;
								if(lab.getValor(x, y)>6){
									lab.putExplorado(x, y);
									pos=0;
									x=0;
									y=0;
									gasto= 0;
									lab.resetVisitado();
								}
								t_end = Time::getTime();
							}
							else{
								lab.putExplorado(x, y);
								pos=0;
								x=0;
								y=0;
								gasto= 0;
								lab.resetVisitado();
								t_end = Time::getTime();
							}
						}
					}
				}
			}
		}
		else{
			pos=0;
			x=0;
			y=0;
			gasto= 0;
			lab.resetVisitado();
			t_end = Time::getTime();
		}
	}
	if(encontrado){
		for(int i=0; i<pos; i++){
			cout<< sol[i];
		}
		cout <<endl;
		cout <<"Los nodos generados han sido: "<<endl;
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(nodos[i][j]){
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
		t_end = Time::getTime();
	}
	else{
		cout << "No se ha encontrado una solucion "<<endl;
		cout <<"Los nodos generados han sido: "<<endl;
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(nodos[i][j]){
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
		t_end = Time::getTime();
	}
}

char hallarDirecionAleatoria2opciones(char c, char y) {
	int p = 0;
	srand(time(NULL));
	p = rand() % 2;
	if (p == 0) {
		return c;
	} else {
		return y;
	}

}
char hallarDirecionAleatoria3opciones(char c, char y, char v) {
	int p = 0;
	char x;
	srand(time(NULL));
	p = rand() % 3;
	if (p == 0) {
		x = c;
	}
	if (p == 1) {
		x = y;
	}
	if (p == 2) {
		x = v;
	}
	return x;
}



void MaximaPendiente(Laberinto &lab, double &t_start, double &t_end) {
	bool encontrado = false;
	t_start = Time::getTime();
	t_end = Time::getTime();
	int x, y, pos, umbral;
	char c, h, v, auxSol;
	char sol [100];
	x = 0;
	y = 0;
	pos = 0;
	umbral = lab.getValor(x, y);
	while (!encontrado) {
		if (x == 0) {
			if (y == 0) {
				if ((lab.getH(x+1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
					if(lab.getH(x,y)>lab.getH(x+1,y)){
					if (lab.getUmbral() >= umbral + lab.getValor(x+1, y)) {
						lab.putVisitado(x, y);
						x++;
						sol[pos] = 'S';
						pos++;
						umbral = umbral + lab.getValor(x, y);
						lab.putVisitado(x, y);
					} else {
						encontrado = true;
						cout << "Umbral sobrepasado" << endl;
					}
					}else{
						encontrado=true;
						cout<<"Padre mejor que el mejor hijo"<<endl;
					}
				} else {
					if ((lab.getH(x+1,y) > lab.getH(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
						if(lab.getH(x,y)>lab.getH(x,y+1)){
						if (lab.getUmbral()>= umbral + lab.getValor(x , y+1)) {
							lab.putVisitado(x, y);
							y++;
							sol[pos] = 'E';
							pos++;
							umbral = umbral + lab.getValor(x, y);
							lab.putVisitado(x, y);
						} else {
							encontrado = true;
							cout << "Umbral sobrepasado" << endl;
						}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					} else {

						char c = 'S';
						char h = 'E';
						auxSol = hallarDirecionAleatoria2opciones(c, h);
						if (auxSol == c) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if ((lab.getUmbral()>= umbral + lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
								lab.putVisitado(x, y);
								sol[pos] = auxSol;
								pos++;
								x++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}

							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}


						} else {
							if(lab.getH(x,y)>lab.getH(x,y+1)){
							if ((lab.getUmbral()>= umbral + lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
								lab.putVisitado(x, y);
								sol[pos] = auxSol;
								pos++;
								y++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						}


					}
				}
			} else {
				if (y != 9) {
					if(y-1==0){
						if ((lab.getH(x+1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if (lab.getUmbral()>= umbral + lab.getValor(x + 1, y)) {
								x++;
								sol[pos] = 'S';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);

							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x+1,y) > lab.getH(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
									y++;
									sol[pos] = 'E';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);

								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'S';
								h = 'E';
								auxSol = hallarDirecionAleatoria2opciones(c, h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1,y))&&(!lab.getVisitado(x+1, y))) {
										sol[pos] = auxSol;
										pos++;
										x++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);

									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y + 1))&&(!lab.getVisitado(x, y+1))) {
										sol[pos] = auxSol;
										pos++;
										y++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);

									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
								}

							}

						}

					}else{
					if (sol[pos - 1] == 'O') {
						if ((lab.getH(x+1,y) < lab.getH(x, y - 1))&&(!lab.getVisitado(x+1, y))) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if (lab.getUmbral()>= umbral + lab.getValor(x + 1, y)) {
								x++;
								sol[pos] = 'S';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x+1,y) > lab.getH(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
								if(lab.getH(x,y)>lab.getH(x,y-1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
									y--;
									sol[pos] = 'O';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {

								c = 'S';
								h = 'O';
								auxSol = hallarDirecionAleatoria2opciones(c, h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1,y))&&(!lab.getVisitado(x+1, y))) {
										sol[pos] = auxSol;
										pos++;
										x++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y - 1))&&(!lab.getVisitado(x, y-1))) {
										sol[pos] = auxSol;
										pos++;
										y--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								}

							}

						}
					} else {
						if (sol[pos - 1] == 'E') {
							if ((lab.getH(x+1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
								if(lab.getH(x,y)>lab.getH(x+1,y)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
									x++;
									sol[pos] = 'S';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								if ((lab.getH(x+1,y) > lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
										y++;
										sol[pos] = 'E';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {

									c = 'S';
									h = 'E';
									auxSol = hallarDirecionAleatoria2opciones(c,h);
									if (auxSol == c) {
										if(lab.getH(x,y)>lab.getH(x+1,y)){
										if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
											sol[pos] = auxSol;
											pos++;
											x++;
											umbral = umbral	+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if(lab.getH(x,y)>lab.getH(x,y+1)){
										if ((lab.getUmbral()>= umbral+ lab.getValor(x,y + 1))&&(!lab.getVisitado(x, y+1))) {
											sol[pos] = auxSol;
											pos++;
											y++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}

									}

								}

							}

						} else {
							if (sol[pos - 1] == 'N') {
								if ((lab.getH(x, y + 1) < lab.getH(x, y - 1))&&(!lab.getVisitado(x, y+1))) {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
										y++;
										sol[pos] = 'E';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if ((lab.getH(x+1,y)> lab.getH(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
										if(lab.getH(x,y)>lab.getH(x,y-1)){
										if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
											y--;
											sol[pos] = 'O';
											pos++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										c = 'E';
										h = 'O';
										auxSol =hallarDirecionAleatoria2opciones(c, h);
										if (sol[pos] == c) {
											if(lab.getH(x,y)>lab.getH(x,y+1)){
											if ((lab.getUmbral()>=umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
												sol[pos] = auxSol;
												pos++;
												y++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);

											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if(lab.getH(x,y)>lab.getH(x,y-1)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
												sol[pos] = auxSol;
												pos++;
												y--;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										}
									}

								}
							}
						}
					}
				}

				} else {
					if (sol[pos - 1] == 'N') {
						if(lab.getH(x,y)>lab.getH(x,y-1)){
						if ((lab.getUmbral()>= umbral + lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
							y--;
							sol[pos] = 'O';
							pos++;
							umbral = umbral + lab.getValor(x, y);
							lab.putVisitado(x, y);
						} else {
							encontrado = true;
							cout << "Umbral sobrepasado" << endl;
						}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					} else {
						if(lab.getH(x,y)>lab.getH(x+1,y)){
						if ((lab.getUmbral()>= umbral + lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
							x++;
							sol[pos] = 'S';
							pos++;
							umbral = umbral + lab.getValor(x, y);
							lab.putVisitado(x, y);
						} else {
							encontrado = true;
							cout << "Umbral sobrepasado" << endl;
						}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					}
				}
			}
		} else {
			if (y == 0) {
				if (x != 9) {
					if(x-1==0){
						if ((lab.getH(x+1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if (lab.getUmbral()>= umbral + lab.getValor(x + 1, y)) {
								x++;
								sol[pos] = 'S';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x+1,y) > lab.getH(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
									y++;
									sol[pos] = 'E';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'S';
								h = 'E';
								auxSol = hallarDirecionAleatoria2opciones(c, h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1,y))&&(!lab.getVisitado(x+1, y))) {
										sol[pos] = auxSol;
										pos++;
										x++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y + 1))&&(!lab.getVisitado(x, y+1))) {
										sol[pos] = auxSol;
										pos++;
										y++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								}
							}
						}

					}else{
					if (sol[pos - 1] == 'N') {
						if ((lab.getH(x - 1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x-1, y))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral + lab.getValor(x - 1, y)) {
								x--;
								sol[pos] = 'N';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x - 1,y) > lab.getH(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
									y++;
									sol[pos] = 'E';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'N';
								h = 'E';
								auxSol = hallarDirecionAleatoria2opciones(c, h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1,y))&&(!lab.getVisitado(x-1, y))) {
										sol[pos] = auxSol;
										pos++;
										x--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y + 1))&&(!lab.getVisitado(x, y+1))) {
										sol[pos] = auxSol;
										pos++;
										y++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								}
							}
						}
					} else {
						if (sol[pos - 1] == 'O') {
							if ((lab.getH(x+1,y) < lab.getH(x - 1,y))&&(!lab.getVisitado(x+1, y))) {
								if(lab.getH(x,y)>lab.getH(x+1,y)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
									x++;
									sol[pos] = 'S';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								if ((lab.getH(x+1,y) > lab.getH(x - 1,y))&&(!lab.getVisitado(x-1, y))) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x - 1,y)) {
										x--;
										sol[pos] = 'N';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {

									c = 'S';
									h = 'N';
									auxSol = hallarDirecionAleatoria2opciones(c,h);
									if (auxSol == c) {
										if(lab.getH(x,y)>lab.getH(x+1,y)){
										if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
											sol[pos] = auxSol;
											pos++;
											x++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if(lab.getH(x,y)>lab.getH(x-1,y)){
										if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
											sol[pos] = auxSol;
											pos++;
											x--;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									}
								}
							}
						} else {
							if (sol[pos - 1] == 'S') {
								if ((lab.getH(x+1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x+1, y))) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
										x++;
										sol[pos] = 'S';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if ((lab.getH(x+1,y)> lab.getH(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
										if(lab.getH(x,y)>lab.getH(x,y+1)){
										if (lab.getUmbral()>= umbral+ lab.getValor(x , y+1)) {
											y++;
											sol[pos] = 'E';
											pos++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										c = 'S';
										h = 'E';
										auxSol =hallarDirecionAleatoria2opciones(c, h);
										if (auxSol == c) {
											if(lab.getH(x,y)>lab.getH(x+1,y)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
												sol[pos] = auxSol;
												pos++;
												x++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if(lab.getH(x,y)>lab.getH(x,y+1)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
												sol[pos] = auxSol;
												pos++;
												y++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										}
									}
								}
							}
						}
					}
				}
				} else {
					if (sol[pos - 1] == 'S') {
						if(lab.getH(x,y)>lab.getH(x,y+1)){
						if ((lab.getUmbral()>= umbral + lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
							y++;
							sol[pos] = 'E';
							pos++;
							umbral = umbral + lab.getValor(x, y);
							lab.putVisitado(x, y);
						} else {
							encontrado = true;
							cout << "Umbral sobrepasado" << endl;
						}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					} else {
						if(lab.getH(x,y)>lab.getH(x-1,y)){
						if ((lab.getUmbral()>= umbral + lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
							x--;
							sol[pos] = 'N';
							pos++;
							umbral = umbral + lab.getValor(x, y);
							lab.putVisitado(x, y);
						} else {
							encontrado = true;
							cout << "Umbral sobrepasado" << endl;
						}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					}

				}
			} else {
				if (x != 9 && y != 9) {
					if (sol[pos - 1] == 'N') {
						if (((lab.getH(x - 1,y) < lab.getH(x, y + 1))&& (lab.getH(x - 1,y) < lab.getH(x, y - 1)))&&(!lab.getVisitado(x-1, y))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral + lab.getValor(x - 1, y)) {
								x--;
								sol[pos] = 'N';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if (((lab.getH(x - 1,y) > lab.getH(x, y + 1))&& (lab.getH(x, y - 1) > lab.getH(x, y + 1)))&&(!lab.getVisitado(x, y+1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
									y++;
									sol[pos] = 'E';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								if (((lab.getH(x - 1,y) > lab.getH(x, y - 1))&& (lab.getH(x, y + 1)> lab.getH(x, y - 1)))&&(!lab.getVisitado(x, y-1))) {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
										y--;
										sol[pos] = 'O';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x - 1,y)== lab.getH(x, y - 1)&&lab.getH(x, y - 1)==lab.getH(x, y + 1)){
									c = 'N';
									h = 'E';
									v = 'O';
									auxSol = hallarDirecionAleatoria3opciones(c,h,v);
									if (auxSol == c) {
										if(lab.getH(x,y)>lab.getH(x-1,y)){
										if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
											sol[pos] = auxSol;
											pos++;
											x--;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if (sol[pos] == h) {
											if(lab.getH(x,y)>lab.getH(x,y+1)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
												sol[pos] = auxSol;
												pos++;
												y++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if(lab.getH(x,y)>lab.getH(x,y-1)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
												sol[pos] = auxSol;
												pos++;
												y--;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										}

									}
								}else{
									if(lab.getH(x - 1,y)== lab.getH(x, y - 1)){
										c = 'N';
										h = 'O';
										auxSol =hallarDirecionAleatoria2opciones(c, h);
										if (auxSol == c) {
											if(lab.getH(x,y)>lab.getH(x-1,y)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
												sol[pos] = auxSol;
												pos++;
												x--;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if(lab.getH(x,y)>lab.getH(x,y-1)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
												sol[pos] = auxSol;
												pos++;
												y--;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										}

									}else{
										if(lab.getH(x - 1,y)== lab.getH(x, y +1)){
											c = 'N';
											h = 'E';
											auxSol =hallarDirecionAleatoria2opciones(c, h);
											if (auxSol == c) {
												if(lab.getH(x,y)>lab.getH(x-1,y)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
													sol[pos] = auxSol;
													pos++;
													x--;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if(lab.getH(x,y)>lab.getH(x,y+1)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
													sol[pos] = auxSol;
													pos++;
													y++;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											}

										}else{
											c = 'E';
											h = 'O';
											auxSol =hallarDirecionAleatoria2opciones(c, h);
											if (auxSol == c) {
												if(lab.getH(x,y)>lab.getH(x,y+1)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x , y+1))&&(!lab.getVisitado(x, y+1))) {
													sol[pos] = auxSol;
													pos++;
													y++;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if(lab.getH(x,y)>lab.getH(x,y-1)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
													sol[pos] = auxSol;
													pos++;
													y--;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											}

										}
									}
								}
								}
							}
						}
					} else {
						if (sol[pos - 1] == 'E') {
							if (((lab.getH(x+1,y) < lab.getH(x-1, y ))&& (lab.getH(x+1,y) < lab.getH(x, y + 1)))&&(!lab.getVisitado(x+1, y))) {
								if(lab.getH(x,y)>lab.getH(x+1,y)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
									x++;
									sol[pos] = 'S';
									pos++;
									umbral = umbral + lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								if (((lab.getH(x+1,y) > lab.getH(x - 1,y))&& (lab.getH(x, y + 1)> lab.getH(x - 1,y)))&&(!lab.getVisitado(x-1, y))) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x - 1,y)) {
										x--;
										sol[pos] = 'N';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if (((lab.getH(x+1,y) > lab.getH(x, y +1))&& (lab.getH(x - 1,y)> lab.getH(x, y + 1)))&&(!lab.getVisitado(x, y+1))) {
										if(lab.getH(x,y)>lab.getH(x,y+1)){
										if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
											y++;
											sol[pos] = 'E';
											pos++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if(lab.getH(x - 1,y)== lab.getH(x, y + 1)&&lab.getH(x, y + 1)==lab.getH(x+1, y )){
										c = 'S';
										h = 'N';
										v = 'E';
										auxSol =hallarDirecionAleatoria3opciones(c, h, v);
										if (auxSol == c) {
											if(lab.getH(x,y)>lab.getH(x+1,y)){
											if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
												sol[pos] = auxSol;
												pos++;
												x++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;

											}cout << "Umbral sobrepasado"<< endl;
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if (auxSol == h) {
												if(lab.getH(x,y)>lab.getH(x-1,y)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1,y))&&(!lab.getVisitado(x-1, y))) {
													sol[pos] = auxSol;
													pos++;
													x--;
													umbral =umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if(lab.getH(x,y)>lab.getH(x,y+1)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x,y+ 1))&&(!lab.getVisitado(x, y+1))) {
													sol[pos] = auxSol;
													pos++;
													y++;
													umbral =umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											}
										}
									}else{
										if(lab.getH(x - 1,y)== lab.getH(x, y + 1)){
											c = 'N';
											h = 'E';
											auxSol =hallarDirecionAleatoria2opciones(c, h);
											if (auxSol == c) {
												if(lab.getH(x,y)>lab.getH(x-1,y)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
													sol[pos] = auxSol;
													pos++;
													x--;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if(lab.getH(x,y)>lab.getH(x,y+1)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
													sol[pos] = auxSol;
													pos++;
													y++;
													umbral = umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											}

										}else{
											if(lab.getH(x - 1,y)== lab.getH(x+1, y )){
												c = 'N';
												h = 'S';
												auxSol =hallarDirecionAleatoria2opciones(c, h);
												if (auxSol == c) {
													if(lab.getH(x,y)>lab.getH(x-1,y)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
														sol[pos] = auxSol;
														pos++;
														x--;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												} else {
													if(lab.getH(x,y)>lab.getH(x+1,y)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x+1, y))&&(!lab.getVisitado(x+1, y))) {
														sol[pos] = auxSol;
														pos++;
														x++;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												}

											}else{
												c = 'S';
												h = 'E';
												auxSol =hallarDirecionAleatoria2opciones(c, h);
												if (auxSol == c) {
													if(lab.getH(x,y)>lab.getH(x+1,y)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
														sol[pos] = auxSol;
														pos++;
														x++;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												} else {
													if(lab.getH(x,y)>lab.getH(x,y+1)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
														sol[pos] = auxSol;
														pos++;
														y++;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												}

											}
										}
									}

									}
								}
							}
						} else {
							if (sol[pos - 1] == 'O') {
								if (((lab.getH(x+1,y) < lab.getH(x, y - 1))&& (lab.getH(x+1,y)< lab.getH(x - 1,y)))&&(!lab.getVisitado(x+1, y))) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
										x++;
										sol[pos] = 'S';
										pos++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado" << endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if (((lab.getH(x+1,y) > lab.getH(x - 1,y))&& (lab.getH(x, y - 1)> lab.getH(x - 1,y)))&&(!lab.getVisitado(x-1, y))) {
										if(lab.getH(x,y)>lab.getH(x-1,y)){
										if (lab.getUmbral()>= umbral+ lab.getValor(x - 1, y)) {
											x--;
											sol[pos] = 'N';
											pos++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if (((lab.getH(x+1,y)> lab.getH(x, y - 1))&& (lab.getH(x - 1,y)> lab.getH(x, y - 1)))&&(!lab.getVisitado(x, y-1))) {
											if(lab.getH(x,y)>lab.getH(x,y-1)){
											if (lab.getUmbral()>= umbral+ lab.getValor(x, y - 1)) {
												y--;
												sol[pos] = 'O';
												pos++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if(lab.getH(x - 1,y)== lab.getH(x, y - 1)&&lab.getH(x, y - 1)== lab.getH(x+1, y )){
											c = 'S';
											h = 'N';
											v = 'O';
											auxSol =hallarDirecionAleatoria3opciones(c, h, v);
											if (auxSol == c) {
												if(lab.getH(x,y)>lab.getH(x+1,y)){
												if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1,y))&&(!lab.getVisitado(x+1, y))) {
													sol[pos] = auxSol;
													pos++;
													x++;
													umbral =umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if (auxSol == h) {
													if(lab.getH(x,y)>lab.getH(x-1,y)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x- 1,y))&&(!lab.getVisitado(x-1, y))) {
														sol[pos] = auxSol;
														pos++;
														x--;
														umbral =umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout<< "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												} else {
													if(lab.getH(x,y)>lab.getH(x,y-1)){
													if ((lab.getUmbral()>=umbral+ lab.getValor(x,y-1))&&(!lab.getVisitado(x, y-1))) {
														sol[pos] = auxSol;
														pos++;
														y--;
														umbral =umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout<< "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												}
											}
										}else{
											if(lab.getH(x - 1,y)== lab.getH(x, y - 1)){
												c = 'N';
												h = 'O';
												auxSol =hallarDirecionAleatoria2opciones(c, h);
												if (auxSol == c) {
													if(lab.getH(x,y)>lab.getH(x-1,y)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
														sol[pos] = auxSol;
														pos++;
														x--;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												} else {
													if(lab.getH(x,y)>lab.getH(x,y-1)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
														sol[pos] = auxSol;
														pos++;
														y--;
														umbral = umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout << "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												}

											}else{
												if(lab.getH(x - 1,y)== lab.getH(x+1, y)){
													c = 'N';
													h = 'S';
													auxSol =hallarDirecionAleatoria2opciones(c, h);
													if (auxSol == c) {
														if(lab.getH(x,y)>lab.getH(x-1,y)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
															sol[pos] = auxSol;
															pos++;
															x--;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													} else {
														if(lab.getH(x,y)>lab.getH(x+1,y)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x+1, y))&&(!lab.getVisitado(x+1, y))) {
															sol[pos] = auxSol;
															pos++;
															x++;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													}

												}else{
													c = 'S';
													h = 'O';
													auxSol =hallarDirecionAleatoria2opciones(c, h);
													if (auxSol == c) {
														if(lab.getH(x,y)>lab.getH(x+1,y)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
															sol[pos] = auxSol;
															pos++;
															x++;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													} else {
														if(lab.getH(x,y)>lab.getH(x,y-1)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
															sol[pos] = auxSol;
															pos++;
															y--;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													}

												}
											}
										}
										}
									}
								}
							} else {
								if (sol[pos - 1] == 'S') {
									if (((lab.getH(x, y - 1) < lab.getH(x+1,y))&& (lab.getH(x, y - 1)< lab.getH(x, y + 1)))&&(!lab.getVisitado(x, y-1))) {
										if(lab.getH(x,y)>lab.getH(x,y-1)){
										if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
											y--;
											sol[pos] = 'O';
											pos++;
											umbral = umbral+ lab.getValor(x, y);
											lab.putVisitado(x, y);
										} else {
											encontrado = true;
											cout << "Umbral sobrepasado"<< endl;
										}
										}else{
											encontrado=true;
											cout<<"Padre mejor que el mejor hijo"<<endl;
										}
									} else {
										if (((lab.getH(x, y - 1)> lab.getH(x+1,y))&& (lab.getH(x, y + 1)> lab.getH(x+1,y)))&&(!lab.getVisitado(x+1, y))) {
											if(lab.getH(x,y)>lab.getH(x+1,y)){
											if (lab.getUmbral()>= umbral+ lab.getValor(x + 1, y)) {
												x++;
												sol[pos] = 'S';
												pos++;
												umbral = umbral+ lab.getValor(x,y);
												lab.putVisitado(x, y);
											} else {
												encontrado = true;
												cout << "Umbral sobrepasado"<< endl;
											}
											}else{
												encontrado=true;
												cout<<"Padre mejor que el mejor hijo"<<endl;
											}
										} else {
											if (((lab.getH(x, y - 1)> lab.getH(x, y + 1))&& (lab.getH(x+1,y)> lab.getH(x, y + 1)))&&(!lab.getVisitado(x, y+1))) {
												if(lab.getH(x,y)>lab.getH(x,y+1)){
												if (lab.getUmbral()>= umbral+ lab.getValor(x,y+ 1)) {
													y++;
													sol[pos] = 'E';
													pos++;
													umbral =umbral+ lab.getValor(x,y);
													lab.putVisitado(x, y);
												} else {
													encontrado = true;
													cout << "Umbral sobrepasado"<< endl;
												}
												}else{
													encontrado=true;
													cout<<"Padre mejor que el mejor hijo"<<endl;
												}
											} else {
												if(lab.getH(x,y+1)== lab.getH(x, y - 1)&&lab.getH(x, y - 1)==lab.getH(x+1, y )){
												c = 'O';
												h = 'S';
												v = 'E';
												auxSol =hallarDirecionAleatoria3opciones(c, h, v);
												if (auxSol == c) {
													if(lab.getH(x,y)>lab.getH(x,y-1)){
													if ((lab.getUmbral()>= umbral+ lab.getValor(x,y- 1))&&(!lab.getVisitado(x, y-1))) {
														sol[pos] = auxSol;
														pos++;
														y--;
														umbral =umbral+ lab.getValor(x,y);
														lab.putVisitado(x, y);
													} else {
														encontrado = true;
														cout<< "Umbral sobrepasado"<< endl;
													}
													}else{
														encontrado=true;
														cout<<"Padre mejor que el mejor hijo"<<endl;
													}
												} else {
													if (auxSol == h) {
														if(lab.getH(x,y)>lab.getH(x+1,y)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x+ 1,y))&&(!lab.getVisitado(x+1, y))) {
															x++;
															sol[pos] = auxSol;
															pos++;
															umbral =umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout<< "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													} else {
														if(lab.getH(x,y)>lab.getH(x,y+1)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x,y+ 1))&&(!lab.getVisitado(x, y+1))) {
															y++;
															sol[pos] = auxSol;
															pos++;
															umbral =umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout<< "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													}
												}
											}else{
												if(lab.getH(x ,y+1)== lab.getH(x+1, y)){
													c = 'S';
													h = 'E';
													auxSol =hallarDirecionAleatoria2opciones(c, h);
													if (auxSol == c) {
														if(lab.getH(x,y)>lab.getH(x+1,y)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
															sol[pos] = auxSol;
															pos++;
															x++;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													} else {
														if(lab.getH(x,y)>lab.getH(x,y+1)){
														if ((lab.getUmbral()>= umbral+ lab.getValor(x, y + 1))&&(!lab.getVisitado(x, y+1))) {
															sol[pos] = auxSol;
															pos++;
															y++;
															umbral = umbral+ lab.getValor(x,y);
															lab.putVisitado(x, y);
														} else {
															encontrado = true;
															cout << "Umbral sobrepasado"<< endl;
														}
														}else{
															encontrado=true;
															cout<<"Padre mejor que el mejor hijo"<<endl;
														}
													}

												}else{
													if(lab.getH(x ,y-1)== lab.getH(x+1, y)){
														c = 'S';
														h = 'O';
														auxSol =hallarDirecionAleatoria2opciones(c, h);
														if (auxSol == c) {
															if(lab.getH(x,y)>lab.getH(x+1,y)){
															if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
																sol[pos] = auxSol;
																pos++;
																x++;
																umbral = umbral+ lab.getValor(x,y);
																lab.putVisitado(x, y);
															} else {
																encontrado = true;
																cout << "Umbral sobrepasado"<< endl;
															}
															}else{
																encontrado=true;
																cout<<"Padre mejor que el mejor hijo"<<endl;
															}
														} else {
															if(lab.getH(x,y)>lab.getH(x,y-1)){
															if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
																sol[pos] = auxSol;
																pos++;
																y--;
																umbral = umbral+ lab.getValor(x,y);
																lab.putVisitado(x, y);
															} else {
																encontrado = true;
																cout << "Umbral sobrepasado"<< endl;
															}
															}else{
																encontrado=true;
																cout<<"Padre mejor que el mejor hijo"<<endl;
															}
														}

													}else{
														c = 'E';
														h = 'O';
														auxSol =hallarDirecionAleatoria2opciones(c, h);
														if (auxSol == c) {
															if(lab.getH(x,y)>lab.getH(x,y+1)){
															if ((lab.getUmbral()>= umbral+ lab.getValor(x , y+1))&&(!lab.getVisitado(x, y-1))) {
																sol[pos] = auxSol;
																pos++;
																y++;
																umbral = umbral+ lab.getValor(x,y);
																lab.putVisitado(x, y);
															} else {
																encontrado = true;
																cout << "Umbral sobrepasado"<< endl;
															}
															}else{
																encontrado=true;
																cout<<"Padre mejor que el mejor hijo"<<endl;
															}
														} else {
															if(lab.getH(x,y)>lab.getH(x,y-1)){
															if ((lab.getUmbral()>= umbral+ lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
																sol[pos] = auxSol;
																pos++;
																y--;
																umbral = umbral+ lab.getValor(x,y);
																lab.putVisitado(x, y);
															} else {
																encontrado = true;
																cout << "Umbral sobrepasado"<< endl;
															}
															}else{
																encontrado=true;
																cout<<"Padre mejor que el mejor hijo"<<endl;
															}
														}

													}
												}
											}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if(y==9&&x!=9){
						if (sol[pos - 1] == 'S') {
						if ((lab.getH(x+1,y) < lab.getH(x, y - 1))&&(!lab.getVisitado(x+1, y))) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
								x++;
								sol[pos] = 'S';
								pos++;
								umbral = umbral+ lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x+1,y)> lab.getH(x, y -1))&&(!lab.getVisitado(x, y-1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x , y-1)) {
									y--;
									sol[pos] = 'O';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado"<< endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'S';
								h = 'O';
								auxSol =hallarDirecionAleatoria2opciones(c, h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
										sol[pos] = auxSol;
										pos++;
										x++;
										umbral = umbral+ lab.getValor(x,y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x, y -1))&&(!lab.getVisitado(x, y-1))) {
										sol[pos] = auxSol;
										pos++;
										y--;
										umbral = umbral+ lab.getValor(x,y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								}
							}
						}
					}else{
						if (sol[pos - 1] == 'E') {
						if ((lab.getH(x+1,y) < lab.getH(x-1, y))&&(!lab.getVisitado(x+1, y))) {
							if(lab.getH(x,y)>lab.getH(x+1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x + 1,y)) {
								x++;
								sol[pos] = 'S';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x+1,y) > lab.getH(x-1, y ))&&(!lab.getVisitado(x-1, y))) {
								if(lab.getH(x,y)>lab.getH(x-1,y)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x-1,y)) {
									x--;
									sol[pos] = 'N';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {

								c = 'S';
								h = 'N';
								auxSol = hallarDirecionAleatoria2opciones(c,h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x+1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x + 1, y))&&(!lab.getVisitado(x+1, y))) {
										sol[pos] = auxSol;
										pos++;
										x++;
										umbral = umbral	+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x-1,y))&&(!lab.getVisitado(x-1, y))) {
										sol[pos] = auxSol;
										pos++;
										x--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}

								}

							}

						}

					}else{
						if (sol[pos - 1] == 'N') {
						if ((lab.getH(x-1,y) < lab.getH(x, y - 1))&&(!lab.getVisitado(x-1, y))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x - 1,y)) {
								x--;
								sol[pos] = 'N';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x-1,y) > lab.getH(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
								if(lab.getH(x,y)>lab.getH(x,y-1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
									y--;
									sol[pos] = 'O';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'N';
								h = 'O';
								auxSol = hallarDirecionAleatoria2opciones(c,h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
										sol[pos] = auxSol;
										pos++;
										x--;
										umbral = umbral	+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y - 1))&&(!lab.getVisitado(x, y-1))) {
										sol[pos] = auxSol;
										pos++;
										y--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}

								}

							}

						}

					}

					}

					}


				}else{
					if(x==9&&y!=9){
						if (sol[pos - 1] == 'O') {
						if ((lab.getH(x-1,y) < lab.getH(x, y - 1))&&(!lab.getVisitado(x-1, y))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x - 1,y)) {
								x--;
								sol[pos] = 'N';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x-1,y) > lab.getH(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
								if(lab.getH(x,y)>lab.getH(x,y-1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
									y--;
									sol[pos] = 'O';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'N';
								h = 'O';
								auxSol = hallarDirecionAleatoria2opciones(c,h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
										sol[pos] = auxSol;
										pos++;
										x--;
										umbral = umbral	+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y - 1))&&(!lab.getVisitado(x, y-1))) {
										sol[pos] = auxSol;
										pos++;
										y--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}

								}

							}

						}

					}else{
						if (sol[pos - 1] == 'E') {
						if ((lab.getH(x-1,y) < lab.getH(x, y + 1))&&(!lab.getVisitado(x-1, y))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x - 1,y)) {
								x--;
								sol[pos] = 'N';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x-1,y) > lab.getH(x, y -+1))&&(!lab.getVisitado(x, y+1))) {
								if(lab.getH(x,y)>lab.getH(x,y+1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y + 1)) {
									y++;
									sol[pos] = 'E';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {
								c = 'N';
								h = 'E';
								auxSol = hallarDirecionAleatoria2opciones(c,h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x-1,y)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
										sol[pos] = auxSol;
										pos++;
										x--;
										umbral = umbral	+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y + 1))&&(!lab.getVisitado(x, y+1))) {
										sol[pos] = auxSol;
										pos++;
										y++;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}

								}

							}

						}

					}else{
						if (sol[pos - 1] == 'N') {
						if ((lab.getH(x,y+1) < lab.getH(x, y - 1))&&(!lab.getVisitado(x, y+1))) {
							if(lab.getH(x,y)>lab.getH(x-1,y)){
							if (lab.getUmbral()>= umbral+ lab.getValor(x ,y+1)) {
								y++;
								sol[pos] = 'E';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado" << endl;
							}
							}else{
								encontrado=true;
								cout<<"Padre mejor que el mejor hijo"<<endl;
							}
						} else {
							if ((lab.getH(x,y-1) > lab.getH(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
								if(lab.getH(x,y)>lab.getH(x,y-1)){
								if (lab.getUmbral()>= umbral+ lab.getValor(x,y - 1)) {
									y--;
									sol[pos] = 'O';
									pos++;
									umbral = umbral+ lab.getValor(x, y);
									lab.putVisitado(x, y);
								} else {
									encontrado = true;
									cout << "Umbral sobrepasado" << endl;
								}
								}else{
									encontrado=true;
									cout<<"Padre mejor que el mejor hijo"<<endl;
								}
							} else {

								c = 'E';
								h = 'O';
								auxSol = hallarDirecionAleatoria2opciones(c,h);
								if (auxSol == c) {
									if(lab.getH(x,y)>lab.getH(x,y+1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x, y))&&(!lab.getVisitado(x, y+1))) {
										sol[pos] = auxSol;
										pos++;
										y++;
										umbral = umbral	+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}
								} else {
									if(lab.getH(x,y)>lab.getH(x,y-1)){
									if ((lab.getUmbral()>= umbral+ lab.getValor(x,y - 1))&&(!lab.getVisitado(x, y-1))) {
										sol[pos] = auxSol;
										pos++;
										y--;
										umbral = umbral+ lab.getValor(x, y);
										lab.putVisitado(x, y);
									} else {
										encontrado = true;
										cout << "Umbral sobrepasado"<< endl;
									}
									}else{
										encontrado=true;
										cout<<"Padre mejor que el mejor hijo"<<endl;
									}

								}

							}

						}

					}

					}

					}

				}else{

					if (sol[pos - 1] == 'S'){
						if(lab.getH(x,y)>lab.getH(x,y-1)){
							if ((lab.getUmbral()>= umbral + lab.getValor(x, y - 1))&&(!lab.getVisitado(x, y-1))) {
								y--;
								sol[pos] = 'O';
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado o casilla visitada anteriormente" << endl;
							}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					} else {
						if(lab.getH(x,y)>lab.getH(x-1,y)){
							if ((lab.getUmbral()>= umbral + lab.getValor(x - 1, y))&&(!lab.getVisitado(x-1, y))) {
								sol[pos] = 'N';
								x--;
								pos++;
								umbral = umbral + lab.getValor(x, y);
								lab.putVisitado(x, y);
							} else {
								encontrado = true;
								cout << "Umbral sobrepasado o casilla visitada anteriormente" << endl;
							}
						}else{
							encontrado=true;
							cout<<"Padre mejor que el mejor hijo"<<endl;
						}
					}
				}

				}

				}
			}
		}
		if (lab.getValor(x, y) == 0) {
			encontrado = true;
			cout << "Salida del laberinto encontrada:" << endl;

			for (int z = 0; z < pos; z++) {
				cout << sol[z];
			}
			cout<<endl;
			cout<<"Nodos visitados:"<<endl;
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					if(lab.getVisitado(i, j)){
						cout<<"("<<i<<","<<j<<")";
					}
				}
			}
		}
		if(lab.getValor(x, y)!= 0 && encontrado){
			cout<<"Salida no encontrada..."<<endl<<"Nodos visitados:"<<endl;
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					if(lab.getVisitado(i, j)){
						cout<<"("<<i<<","<<j<<")";
					}
				}
			}
		}
	}
	t_end = Time::getTime();
}


int decidirDireccion(int limit){
	srand(time(NULL));
	int direccion;
	direccion=rand()%limit;
	return direccion;
}

void escaladaSimple(Laberinto &lab,double &t_start, double &t_end){
	char sol[100];
	t_start = Time::getTime();
	t_end = Time::getTime();
	int cont;
	int x, y,umbral;
	int direccion;
	bool nodos[10][10];
	for(int i=0;i<10;i++){
		for(int j;j<10;j++){
			nodos[i][j]=false;
		}
	}

	x = 0;
	y = 0;
	cont = 0;
	umbral = 0;
	int terminar = 0;//si es igual a 0 el módulo continua, si es 1 termina sin solución y si es 2 termina con solución encontrada

	if(lab.getH(x,y+1)<lab.getH(x,y)){
		sol[cont]='S';
		cont++;
		y++;
		umbral+=lab.getValor(x,y);
		nodos[x][y]=true;
	}
	else if(lab.getH(x+1,y)<lab.getH(x,y)){
		sol[cont]='E';
		cont++;
		x++;
		umbral+=lab.getValor(x,y);
		nodos[x][y]=true;
	}else {
		terminar=1;
		cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
	}


	while (terminar==0 && umbral<lab.getUmbral()) {
		if(sol[cont-1]=='S'){
			if(x==0 && y!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==9 && y!=0){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==9 && x!=0 && x!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==0 && y==9){
				if(lab.getH(x+1,y)<lab.getH(x,y)){
					sol[cont]='E';
					cont++;
					x++;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
					   terminar=2;
				    }
			     }else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
			}
			if(x==9 && y==9){
				if(lab.getH(x-1,y)<lab.getH(x,y)){
					sol[cont]='O';
					cont++;
					x--;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
			    }else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
			}else{
				direccion=decidirDireccion(3);
				if(direccion==0){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
				if(direccion==1){
					if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
		}
		else if(sol[cont-1]=='O'){
			if(x==0 && y!=0 && y!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==0 && x!=0){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else {
					if(lab.getH(x,y+1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==9 && x!=0){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==0 && y==0){
				if(lab.getH(x,y-1)<lab.getH(x,y)){
					sol[cont]='S';
					cont++;
					y++;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}
			if(x==0 && y==9){
				if(lab.getH(x,y-1)<lab.getH(x,y)){
					sol[cont]='N';
					cont++;
					y--;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}else{
				direccion=decidirDireccion(3);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
				if(direccion==1){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
		}
		else if(sol[cont-1]=='N'){
			if(x==0 && y!=0){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==9 && y!=0){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else terminar =1;
				}else{
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==0 && x!=0 && x!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==0 && y==0){
				if(lab.getH(x+1,y)<lab.getH(x,y)){
					sol[cont]='E';
					cont++;
					x++;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}
			if(x==9 && y==0){
				if(lab.getH(x-1,y)<lab.getH(x,y)){
					sol[cont]='O';
					cont++;
					x--;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
				    if(lab.getH(x,y)==0){
					   terminar=2;
				    }
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}else{
				direccion=decidirDireccion(3);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
					    if(lab.getH(x,y)==0){
						   terminar=2;
					    }
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
				if(direccion==1){
					if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
				else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x-1,y)<lab.getH(x,y)){
						sol[cont]='O';
						cont++;
						x--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
		}
		else if(sol[cont-1]=='E'){
			if(x==9 && y!=0 && y!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==0 && x!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(y==9 && x!=9){
				direccion=decidirDireccion(2);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
			if(x==9 && y==0){
				if(lab.getH(x,y-1)<lab.getH(x,y)){
					sol[cont]='S';
					cont++;
					y++;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}
			if(x==9 && y==9){
				if(lab.getH(x,y-1)<lab.getH(x,y)){
					sol[cont]='N';
					cont++;
					y--;
					umbral+=lab.getValor(x,y);
					nodos[x][y]=true;
					if(lab.getH(x,y)==0){
						terminar=2;
					}
				}else {
					terminar=1;
					cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
				}
			}else{
				direccion=decidirDireccion(3);
				if(direccion==0){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
				if(direccion==1){
					if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}else{
					if(lab.getH(x+1,y)<lab.getH(x,y)){
						sol[cont]='E';
						cont++;
						x++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='N';
						cont++;
						y--;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}
					else if(lab.getH(x,y-1)<lab.getH(x,y)){
						sol[cont]='S';
						cont++;
						y++;
						umbral+=lab.getValor(x,y);
						nodos[x][y]=true;
						if(lab.getH(x,y)==0){
							terminar=2;
						}
					}else {
						terminar=1;
						cout<<"ningun hijo es mejor en movimiento: "<<cont<<endl;
					}
				}
			}
		}
	}
	if(terminar==2){
		cout<<"Solución:"<<endl;
		for(int k=0;k<cont;k++){
			cout<<sol[k];
		}
		cout<<endl;
		cout<<"posiciones del laberinto:"<<endl;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(nodos[i][j]==true){
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
		cout<<endl;
		t_end = Time::getTime();
	}
	if (terminar==1){
		cout<<"No se pudo encontrar la solución"<<endl;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(nodos[i][j]==true){
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
		t_end = Time::getTime();
	}
}

void pruebasGeneracionYPrueba(Laberinto lab, string laberinto){
	bool encontrado=false;
	double t_start, t_end;
	int pos=0, gasto=0;
	lab.GenerarTablero(laberinto);
	lab.putH();
	cout<< "Para "<< laberinto <<" la solucion de generacion y prueba es:"<<endl;
	generacionYPrueba(lab, gasto, pos, encontrado, t_start, t_end);
	cout <<""<<endl;
	cout << "Generacion y prueba ha tardado: " << t_end - t_start << "  " << endl;
}

void pruebasMaximaPendiente(Laberinto lab, string laberinto){
	double t_start, t_end;
	lab.GenerarTablero(laberinto);
	lab.putH();
	cout<< "Para "<< laberinto <<" la solucion de maxima pendiente es: "<<endl;
	MaximaPendiente(lab, t_start, t_end);
	cout <<""<<endl;
	cout << "Maxima pendiente ha tardado: " << t_end - t_start << "  " << endl;
}

void pruebasescaladaSimple(Laberinto lab, string laberinto){
	double t_start, t_end;
	lab.GenerarTablero(laberinto);
	lab.putH();
	cout<< "Para "<< laberinto <<" la solucion de escalada simple es: "<<endl;
	escaladaSimple(lab, t_start, t_end);
	cout <<""<<endl;
	cout << "escalada simple ha tardado: " << t_end - t_start << "  " << endl;
}

int main() {
	Laberinto lab;
	string laberinto= "laberinto1.txt";
	int algoritmo=1;
	bool encontrado=false;
	double t_start, t_end;
	int pos=0, gasto=0;
	while(algoritmo!=0){
		cout<< "Elige el algoritmo que quieres ejecutar:"<<endl;
		cout <<"1- generacion y prueba"<<endl;
		cout <<"2- escalada simple"<<endl;
		cout <<"3- escalada maxima pendiente"<<endl;
		cout <<"4- bateria de pruebas"<<endl;
		cout <<"0- terminar el programa"<<endl;
		cin>> algoritmo;
		if(algoritmo==1){
			cout<< "¿Que laberinto quieres resolver?"<<endl;
			cin>> laberinto;
			lab.GenerarTablero(laberinto);
			lab.putH();
			cout<< "Para "<< laberinto <<" la solucion de generacion y prueba es:"<<endl;
			generacionYPrueba(lab, gasto, pos, encontrado, t_start, t_end);
			cout <<""<<endl;
			cout << "Generacion y prueba ha tardado: " << t_end - t_start << "  " << endl;
		}
		else{
			if(algoritmo==2){
				cout<< "¿Que laberinto quieres resolver?"<<endl;
				cin>> laberinto;
				lab.GenerarTablero(laberinto);
				lab.putH();
				cout<< "Para "<< laberinto <<" la solucion de escalada simple es:"<<endl;
				escaladaSimple(lab, t_start, t_end);
				cout <<""<<endl;
				cout << "Escalada simple ha tardado: " << t_end - t_start << "  " << endl;
			}
			else{
				if(algoritmo==3){
					cout<< "¿Que laberinto quieres resolver?"<<endl;
					cin>> laberinto;
					lab.GenerarTablero(laberinto);
					lab.putH();
					cout<< "Para "<< laberinto <<" la solucion de maxima pendiente es:"<<endl;
					MaximaPendiente(lab,t_start, t_end);
					cout <<""<<endl;
					cout << "Maxima pendiente ha tardado: " << t_end - t_start << "  " << endl;

				}
				else{
					if(algoritmo==4){
						cout<<"Inicio pruebas de Generacion y Prueba"<<endl;

						laberinto= "laberinto1.txt";
						pruebasGeneracionYPrueba(lab, laberinto);
						laberinto= "laberinto2.txt";
						pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto3.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto4.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto5.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto6.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto7.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto8.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto9.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto10.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto11.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto12.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto13.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);
						 laberinto= "laberinto14.txt";
						 pruebasGeneracionYPrueba(lab, laberinto);

						cout<<"Fin pruebas Generacion y prueba"<<endl<<"Inicio pruebas de Maxima Pendiente"<<endl;

						 laberinto= "laberinto1.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto2.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto3.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto4.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto5.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto6.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto7.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto8.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto9.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto10.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto11.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto12.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto13.txt";
						 pruebasMaximaPendiente(lab, laberinto);
						 laberinto= "laberinto14.txt";
						 pruebasMaximaPendiente(lab, laberinto);

						 cout<<"Fin pruebas Maxima pendiente"<<endl<<"Inicio prebas escalada simple"<<endl;

						 laberinto= "laberinto1.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto2.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto3.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto4.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto5.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto6.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto7.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto8.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto9.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto10.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto11.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto12.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto13.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 laberinto= "laberinto14.txt";
						 pruebasescaladaSimple(lab, laberinto);
						 cout<<"Fin pruebas escaladaSimple"<<endl;

					}
				}
			}
		}
	}
	return 0;
}



