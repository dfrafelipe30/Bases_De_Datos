/*
 * ArbolB+.cpp
 *
 *  Created on: 23/05/2019
 *      Author: juanferna.perez
 */


#ifdef ARBOLB_H_

#include<iostream>
#include<math.h>
using namespace std;

template <typename TipoLlave>
ArbolB<TipoLlave>::ArbolB(int n){
	this->raiz = nullptr;
	this->n = n;
}

template <typename TipoLlave>
void ArbolB<TipoLlave>::insertarTupla(TipoLlave llave, Tupla* tupla){
	NodoB* L; /* Nodo hoja donde insertar tupla */
	if(this->raiz==nullptr){
		raiz = new NodoB;
		raiz->esHoja=true;
		raiz->next=nullptr;
		raiz->tuplas=new Tupla*[n-1];
		raiz->llaves=new TipoLlave[n-1];
		raiz->numLlaves=0;
		L = raiz;
	}else{
		L = encontrarHoja(llave);
	}

	if(L->numLlaves<n-1){
		insertarEnHoja(L, llave, tupla);
	}else{
		NodoB* Lp = new NodoB;
		Lp->esHoja=true;
		Lp->next=nullptr;
		Lp->tuplas=new Tupla*[n-1];
		Lp->llaves=new TipoLlave[n-1];
		Lp->numLlaves=0;


		Tupla** tempTuplas = new Tupla*[L->numLlaves];
		TipoLlave* tempLlaves = new TipoLlave[L->numLlaves];

		/* posición para insertar K,P */
		int k = 0;
		while(llave>L->llaves[k])k++;

		for(int i = 0; i < k; i++){
			tempTuplas[i] = L->tuplas[i];
			tempLlaves[i] = L->llaves[i];
		}

		tempTuplas[k] = tupla;
		tempLlaves[k] = llave;

		for(int i = k+1; i <= L->numLlaves; i++){
			tempTuplas[i] = L->tuplas[i-1];
			tempLlaves[i] = L->llaves[i-1];
		}

		/* copiar y ajustar next */
		Lp->next = L->next;
		L->next = Lp;

		L->numLlaves = (int)n/2;
		for(int i = 0; i < L->numLlaves; i++){
			L->tuplas[i] = tempTuplas[i];
			L->llaves[i] = tempLlaves[i];
		}

		for(int i = L->numLlaves; i < n; i++){
			Lp->tuplas[i-L->numLlaves] = tempTuplas[i];
			Lp->llaves[i-L->numLlaves] = tempLlaves[i];
			Lp->numLlaves++;
		}

		TipoLlave Kp = Lp->llaves[0];
		insertarEnPadre(L,Kp,Lp);
	}

}

template <typename TipoLlave>
void ArbolB<TipoLlave>::insertarEnHoja(NodoB* &L, TipoLlave llave, Tupla* tupla){
	if(L->numLlaves==0){
		L->tuplas[0] = tupla;
		L->llaves[0] = llave;
	}else if(llave<L->llaves[0]){
		for(int i=L->numLlaves; i>0; i--){
			L->tuplas[i] = L->tuplas[i-1];
			L->llaves[i] = L->llaves[i-1];
		}
		L->tuplas[0] = tupla;
		L->llaves[0] = llave;
	}else{
		int k = 0;
		while(llave>L->llaves[k]&& k<L->numLlaves)k++;

		for(int i=L->numLlaves; i>k; i--){
			L->tuplas[i] = L->tuplas[i-1];
			L->llaves[i] = L->llaves[i-1];
		}
		L->tuplas[k] = tupla;
		L->llaves[k] = llave;
	}
	L->numLlaves++;
}

template <typename TipoLlave>
typename ArbolB<TipoLlave>::NodoB* ArbolB<TipoLlave>::encontrarHoja(TipoLlave llave){
	NodoB* C = raiz;
	while(!C->esHoja){
		int k=0;
		while(llave>C->llaves[k] && k<C->numLlaves)k++;
		if(k==C->numLlaves){
			C=C->hijos[C->numLlaves];
		}else if(llave==C->llaves[k]){
			C=C->hijos[k+1];
		}else{
			C=C->hijos[k];
		}
	}
	return C;
}

template <typename TipoLlave>
void ArbolB<TipoLlave>::insertarEnPadre(NodoB* &L, TipoLlave Kp, NodoB* &Lp){
	if(compararNodos(L,raiz)){
		NodoB* nuevo = new NodoB;
		nuevo->esHoja=false;
		nuevo->next=nullptr;
		nuevo->hijos=new NodoB*[n];
		nuevo->llaves=new TipoLlave[n-1];
		nuevo->numLlaves=1;
		nuevo->hijos[0] = L;
		nuevo->hijos[1] = Lp;
		nuevo->llaves[0] = Kp;
		raiz = nuevo;
	}else{
		NodoB* padre = encontrarPadre(L);

		/**/
		if(padre->numLlaves<n-1){
			int k = 0;
			while(!compararNodos(L, padre->hijos[k]))k++;
			//padre->hijos[padre->numLlaves+1] = padre->hijos[padre->numLlaves];
			for(int i = padre->numLlaves+1;i>k+1;i--){
				padre->hijos[i] = padre->hijos[i-1];
				padre->llaves[i-1] = padre->llaves[i-2];
			}
			padre->hijos[k+1] = Lp;
			padre->llaves[k] = Kp;
			padre->numLlaves++;

		}else{
			NodoB* Pp = new NodoB;
			Pp->esHoja=false;
			Pp->next=nullptr;
			Pp->tuplas=nullptr;
			Pp->llaves=new TipoLlave[n-1];
			Pp->hijos=new NodoB*[n];
			Pp->numLlaves=0;

			NodoB** tempHijos = new NodoB*[n+1];
			TipoLlave* tempLlaves = new TipoLlave[n];

			/* posición para insertar Kp, Lp */
			int k = 0;
			while(!compararNodos(L, padre->hijos[k]))k++;
			for(int i = 0; i < k; i++){
				tempHijos[i] = padre->hijos[i];
				tempLlaves[i] = padre->llaves[i];
			}

			tempHijos[k] = Lp;
			tempLlaves[k] = Kp;

			for(int i = k+1; i <= padre->numLlaves; i++){
				tempHijos[i] = padre->hijos[i-1];
				tempLlaves[i] = padre->llaves[i-1];
			}

			/* copiar y ajustar llaves e hijos */

			padre->numLlaves = (int)n/2;
			for(int i = 0; i < padre->numLlaves-1; i++){
				padre->hijos[i] = tempHijos[i];
				padre->llaves[i] = tempLlaves[i];
			}
			padre->hijos[padre->numLlaves-1] = tempHijos[padre->numLlaves-1];
			TipoLlave Kpp = padre->llaves[padre->numLlaves-1];

			Pp->numLlaves=0;
			for(int i = padre->numLlaves; i < n; i++){
				Pp->hijos[i-padre->numLlaves] = tempHijos[i];
				Pp->llaves[i-padre->numLlaves] = tempLlaves[i];
				Pp->numLlaves++;
			}
			Pp->hijos[n-padre->numLlaves] = tempHijos[n];

			insertarEnPadre(padre,Kpp,Pp);
		}


		/**/

	}
}

template <typename TipoLlave>
typename ArbolB<TipoLlave>::NodoB* ArbolB<TipoLlave>::encontrarPadre(NodoB* N){

	if (compararNodos(N,raiz)){
		return nullptr;
	}else{
		NodoB* C = raiz;
		while (!C->esHoja){
			for(int i = 0; i< C->numLlaves+1; i++){
				if(compararNodos(N, C->hijos[i]))
					return C;
			}

			int k = 0; /* nodo hijo candidato */
			while(N->llaves[0] >= C->llaves[k] )k++;
			C = C->hijos[k];
		}
	}

	return nullptr;

}


template <typename TipoLlave>
bool ArbolB<TipoLlave>::compararNodos( NodoB* A,  NodoB* B){
	if (A->numLlaves==B->numLlaves){
		int i = 0;
		while(i <A->numLlaves){
			if(A->llaves[i] != B->llaves[i])
				break;
			i++;
		}
		if(i==A->numLlaves)
			return true;
		else
			return false;
	}
	return false;

}



template <typename TipoLlave>
void ArbolB<TipoLlave>::imprimir(){
	std::cout << "- - - - - - -" << std::endl;
	imprimirArbol(raiz);
	std::cout << "- - - - - - -" << std::endl;
}

template <typename TipoLlave>
void ArbolB<TipoLlave>::imprimirArbol(ArbolB<TipoLlave>::NodoB *nodo){
	if (nodo != nullptr) {
		std::cout << "- - - - - - -" << std::endl;
		for (int i = 0; i < nodo->numLlaves; i++)
			std::cout << nodo->llaves[i] << std::endl;
		std::cout << "- - - - - - -" << std::endl;

		if(!nodo->esHoja){
			for (int i = 0; i < nodo->numLlaves+1; i++)
				imprimirArbol(nodo)(nodo->hijos[i]);
		}
	}
}

template <typename TipoLlave>
void ArbolB<TipoLlave>::eliminar(TipoLlave llave,Tupla* tupla){
	NodoB * temp = encontrarHoja(llave);
	eliminar_de_arbol(temp, llave, tupla);
}

template <typename TipoLlave>
void ArbolB<TipoLlave>::eliminarTupla(TipoLlave k,NodoB N){
	TipoLlave* newllave;
	for(int i = 0;i < N.numLlaves;i++){
		if(N.llaves[i] != k){
			newllave[i] = N.llaves[i];
		}
		else{
			i = i - 1;
		}
	}
	if(N.esHoja){

		NodoB* newtuplas;

		for(int j = 0;j < N.numLlaves + 1;j++){
			if(N.tuplas[j] != tupla){
				newtuplas[j] = N.tuplas[j];
			}
			else{
				j =  j -1;
			}
		}
		N.numLlaves = N.llaves - 1;
	}
	else{
		NodoB* newhijos;

		for(int j = 0;j < N.numLlaves + 1;j++){
			if(N.tuplas[j] != tupla){
				newhijos[j] = N.tuplas[j];
			}
			else{
				j =  j -1;
			}
		}
		N.numLlaves = N.llaves - 1;
	}
	}


}

template <typename TipoLlave>
void ArbolB<TipoLlave>::eliminar_de_arbol(NodoB * N,TipoLlave k,Tupla* tupla){


}




#endif /* ARBOLB_H_ */
