#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include "tuplas.cpp"

class Pagina{
private:

  int tamano = 4096;
  int tamanoActual;

  struct tuplas{
    tuplas *izq;
    tuplas *der;
    tuplaEstudiante est;
  };

  tuplas *link;
  tuplas *inicio;

public:

  Pagina();
  //~Pagina();

  void insertarTupla(tuplaEstudiante te);
  void eliminarTupla(tuplaEstudiante te);

  int getSize();

  void toString();
};

#endif /*PAGINA_H*/
