/*
 * ArbolB+.h
 *
 *  Created on: 23/05/2019
 *      Author: juanferna.perez
 */

#ifndef ARBOLB_H_
#define ARBOLB_H_

#include"Tupla.h"


template <typename TipoLlave>
class ArbolB {
public:
	/*
	* Tipo: Nodo de Árbol de Búsqueda Binaria
	* ----------
	* Estructura para almacenar cada nodo del árbol.
	*/

	struct NodoB {
		bool esHoja; 		/* True si es hoja */
		NodoB* next;		/* Siguiente nodo (si es hoja) */
		Tupla** tuplas; 	/* Apuntadores a tuplas (si es hoja) */
		NodoB** hijos;  	/* Apuntadores a hijos (si no es hoja) */
		TipoLlave* llaves; 	/* Llaves */
		int numLlaves;		/* Numero de llaves */
	};

	ArbolB(int n);

	void insertarTupla(TipoLlave llave, Tupla* tupla);

	void insertarEnHoja(NodoB* &L, TipoLlave llave, Tupla* tupla);

	NodoB* encontrarHoja(TipoLlave llave);

	void insertarEnPadre(NodoB* &L, TipoLlave Kp, NodoB* &Lp);

	NodoB* encontrarPadre(NodoB* N);

	void eliminar(TipoLlave llave,Tupla *tupla);

	void eliminar_de_arbol(NodoB* N,TipoLlave k,Tupla* tupla);

	void eliminarTupla(TipoLlave k,NodoB N);

	Tupla* encontrarTupla(TipoLlave k);

	void imprimir();

	void imprimirArbol(NodoB * nodo);

	bool compararNodos(NodoB* A, NodoB* B);

	void imprimirEntre(TipoLlave n1, TipoLlave n2);

private:
	/* Atributos */
	NodoB *raiz; 	/* Apuntador al nodo raíz del árbol */
	int n; 			/* orden del arbol*/
};



#endif /* ARBOLB_H_ */

#include "ArbolB+.cpp"





