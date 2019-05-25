#include <string>
#include <iostream>
#include "pagina.h"
using namespace std;

Pagina::Pagina(){
  tamanoActual = tamano;
  inicio = link = new tuplas;
  inicio = NULL;
}

void Pagina::insertarTupla(tuplaEstudiante te){
  if(inicio == NULL){
    tuplas *temp = new tuplas;
    temp->izq = temp->der=NULL;
    temp->est = te;
    inicio = temp;
    link = inicio;
    tamanoActual-=te.getSize();
  }else if(tamanoActual-te.getSize()>=0){
    tuplas *temp = new tuplas;
    link->der = temp;
    temp->izq = link;
    temp->der = NULL;
    link = temp;
    link->est = te;
    tamanoActual-=te.getSize();
  }
}

void Pagina::eliminarTupla(tuplaEstudiante te){
  tuplas *temp = inicio;
  while(temp!=NULL){
    if(temp->est.getCedula() == te.getCedula()){
      temp->izq->der = temp->der;
      temp->der->izq = temp->izq;
      tamanoActual+=te.getSize();
      delete temp;
      break;
    }else{
      temp = temp->der;
    }
  }
}

int Pagina::getSize(){
  return tamanoActual;
}


void Pagina::toString(){
  tuplas *temp = inicio;
  while(temp!=NULL){
    std::cout<<"Direccion: "<<&temp<<" "<<(temp->est).toString()<<std::endl;
    temp = temp->der;
  }
}
