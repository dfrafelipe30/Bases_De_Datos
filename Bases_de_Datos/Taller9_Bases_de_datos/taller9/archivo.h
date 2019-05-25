#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include "pagina.cpp"

class Archivo{
private:
  int capacidadMaximaPagina;
  std::string idArchivo;
  std::string *tipos; //Arreglo de tipos (tipos de los parametros de tablas)
  std::string *nombres; //Arreglo de nombres (nombres de los parametros)
  std::string *variable; //Arreglo del tipo se la variable (si es variable o no)

  struct archivoPaginas {
    archivoPaginas *der;
    archivoPaginas *izq;
    Pagina pg;
    std::string id_archivo;
  };

  archivoPaginas *link;
  archivoPaginas *inicio;

public:

  Archivo(std::string id_archivo,std::string *tipos,std::string *nombres, std::string *variable);

  void insertarPagina(tuplaEstudiante est);
  void eliminarPagina(tuplaEstudiante est);

  int getCapacidadMaximaPagina();
  std::string getID();
  std::string * getTipos();
  std::string * getParametros();

  bool confirmarTipos(tuplaEstudiante est);

};

#endif /*ARCHIVO_H*/
