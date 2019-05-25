#ifndef TUPLA_H
#define TUPLA_H

#include <string>

class tuplaEstudiante{
private:
  int tamano = 3000;


  std::string nombre;
  std::string apellido;
  std::string cedula;
  std::string carrera;

public:
  tuplaEstudiante();
  tuplaEstudiante(std::string nombre, std::string apellido, std::string cedula, std::string carrera);

  std::string getNombre();
  std::string getApellido();
  std::string getCedula();
  std::string getCarrera();

  bool operator ==(tuplaEstudiante est);

  int getSize();

  std::string toString();

};

#endif /*TUPLA_H*/
