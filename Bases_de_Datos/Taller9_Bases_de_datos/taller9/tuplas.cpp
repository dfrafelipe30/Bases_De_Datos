#include<string>
#include "tupla.h"

tuplaEstudiante::tuplaEstudiante(){
  this->nombre = "";
  this->apellido = "";
  this->cedula = "";
  this->carrera = "";
}

tuplaEstudiante::tuplaEstudiante(std::string nombre, std::string apellido, std::string cedula, std::string carrera){
  this->nombre = nombre;
  this->apellido = apellido;
  this->cedula = cedula;
  this->carrera = carrera;
}

std::string tuplaEstudiante::getNombre(){
  return nombre;
}

std::string tuplaEstudiante::getApellido(){
  return apellido;
}

std::string tuplaEstudiante::getCedula(){
  return cedula;
}

std::string tuplaEstudiante::getCarrera(){
  return carrera;
}

int tuplaEstudiante::getSize(){
  return tamano;
}

std::string tuplaEstudiante::toString(){
  return "Estudiante: "+nombre+" "+apellido;
}

bool tuplaEstudiante::operator==(tuplaEstudiante est){
  if(nombre==est.getNombre() && apellido==est.getApellido() && cedula==est.getCedula() && carrera==est.getCarrera()){
    return true;
  }else{
    return false;
  }
}
