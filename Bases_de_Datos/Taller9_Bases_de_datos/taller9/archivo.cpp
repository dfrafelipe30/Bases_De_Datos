#include <string>
#include "archivo.h"

Archivo::Archivo(std::string id_archivo,std::string *tipos,std::string *nombres, std::string *variable){
  capacidadMaximaPagina = 500;
  idArchivo = id_archivo;
  this->tipos = tipos; //Arreglo tipo parametros
  this->nombres = nombres; //Arreglo nombres de parametros
  this->variable = variable; //Arreglo de variabilidad

  link = inicio = new archivoPaginas;
}

void Archivo::insertarPagina(tuplaEstudiante pg){
	archivoPaginas *temp = inicio;
  std::cout<<"Trabajando"<<std::endl;
	while(temp != NULL){
		if(temp->pg.getSize()> pg.getSize()){
			temp->pg.insertarTupla(pg);
      break;
		}else{
			if (temp->der == NULL){
				Pagina pag = Pagina();
				pag.insertarTupla(pg);
				archivoPaginas *pagina = new archivoPaginas;
				pagina->der = NULL;
				pagina->izq = temp;
				pagina->pg = pag;
				pagina->id_archivo = idArchivo;
				temp->der = pagina;
				break;
			}
			else{
				temp = temp->der;
			}
		}
	}

}

void Archivo::eliminarPagina(tuplaEstudiante pg){
	archivoPaginas *temp = inicio;
	while(temp != NULL){
		temp->pg.eliminarTupla(pg);
	}
}


int Archivo::getCapacidadMaximaPagina(){
  return capacidadMaximaPagina;
}

std::string Archivo::getID(){
  return idArchivo;
}

std::string * Archivo::getTipos(){
  return tipos;
}

std::string * Archivo::getParametros(){
  return nombres;
}
