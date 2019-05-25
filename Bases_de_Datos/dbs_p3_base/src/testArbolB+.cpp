/*
 * testArbolB+.cpp
 *
 *  Created on: 23/05/2019
 *      Author: juanferna.perez
 */

#include"ArbolB+.h"
#include<iostream>
using namespace std;

int main(){
	int n = 4;
	ArbolB<int> arbol = ArbolB<int>(n);

	Tupla* tup1 = new Tupla(88, "J1", "P1");
	arbol.insertarTupla(tup1->getID(), tup1);

	Tupla* tup2 = new Tupla(77, "J2", "P2");
	arbol.insertarTupla(tup2->getID(), tup2);

	Tupla* tup3 = new Tupla(66, "J3", "P3");
	arbol.insertarTupla(tup3->getID(), tup3);

	Tupla* tup4 = new Tupla(33, "J4", "P4");
	arbol.insertarTupla(tup4->getID(), tup4);

	Tupla* tup5 = new Tupla(55, "J5", "P5");
	arbol.insertarTupla(tup5->getID(), tup5);
	Tupla* tup6 = new Tupla(44, "J6", "P6");
	arbol.insertarTupla(tup6->getID(), tup6);

	Tupla* tup7 = new Tupla(56, "J7", "P7");
	arbol.insertarTupla(tup7->getID(), tup7);

	Tupla* tup8 = new Tupla(57, "J8", "P8");
	arbol.insertarTupla(tup8->getID(), tup8);
	arbol.imprimir();


	int n1 = 10, n2 = 100;
	cout << "Registros entre " << n1 << " y " << n2 << ":"<< endl;
	arbol.imprimirEntre(n1, n2);

	n1 = 30, n2 = 55;
	cout << "Registros entre " << n1 << " y " << n2 << ":"<< endl;
	arbol.imprimirEntre(n1, n2);

	n1 = 44, n2 = 77;
	cout << "Registros entre " << n1 << " y " << n2 << ":"<< endl;
	arbol.imprimirEntre(n1, n2);

}


