#include <iostream>
#include "archivo.cpp"
using namespace std;


int main(){

  tuplaEstudiante est1 = tuplaEstudiante("Felipe","Guzman","100","MACC");
  tuplaEstudiante est2 = tuplaEstudiante("EST1","APE1","1","MACC");
  tuplaEstudiante est3 = tuplaEstudiante("EST2","APE2","2","MACC");

  tuplaEstudiante est4 = tuplaEstudiante("EST3","APE3","3","MACC");
  tuplaEstudiante est5 = tuplaEstudiante("EST4","APE4","4","MACC");
  tuplaEstudiante est6 = tuplaEstudiante("EST5","APE5","5","MACC");

  tuplaEstudiante est7 = tuplaEstudiante("EST6","APE6","6","MACC");
  tuplaEstudiante est8 = tuplaEstudiante("EST7","APE7","7","MACC");
  tuplaEstudiante est9 = tuplaEstudiante("EST8","APE8","8","MACC");

  tuplaEstudiante est10 = tuplaEstudiante("EST9","APE9","9","MACC");
  tuplaEstudiante est11 = tuplaEstudiante("EST10","APE10","10","MACC");
  tuplaEstudiante est12 = tuplaEstudiante("EST11","APE11","11","MACC");

  string tipos[5] = {"string","string","int","int","string"};
  string nombres[5] = {"nombre","apellido","cedula","telefono","direccion"};
  string variable[5] = {"0","1","0","1","1"};

  Archivo ar = Archivo("arch1",tipos,nombres,variable);
  ar.insertarPagina(est1);
  ar.insertarPagina(est2);
  // ar.insertarPagina(est3);
  // ar.insertarPagina(est4);
  // ar.insertarPagina(est5);
  // ar.insertarPagina(est6);
  // ar.insertarPagina(est7);
  // ar.insertarPagina(est8);
  // ar.insertarPagina(est9);
  // ar.insertarPagina(est10);
  // ar.insertarPagina(est11);
  // ar.insertarPagina(est12);

}
