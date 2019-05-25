#include <iostream>
#include <string>
#include "pagina.cpp"
using namespace std;

int main(){
  tuplaEstudiante est1 = tuplaEstudiante("Felipe","Guzman","1","MACC");
  tuplaEstudiante est2 = tuplaEstudiante("Juan","Perez","2","MACC");
  tuplaEstudiante est3 = tuplaEstudiante("Camilo","Diaz","3","MACC");
  tuplaEstudiante est4 = tuplaEstudiante("Daniel","Mejia","4","MACC");
  tuplaEstudiante est5 = tuplaEstudiante("Mateo","Rodrigez","5","MACC");
  Pagina pg1 = Pagina();

  pg1.insertarTupla(est1);
  pg1.insertarTupla(est2);
  pg1.insertarTupla(est3);
  pg1.insertarTupla(est4);
  pg1.insertarTupla(est5);
  pg1.toString();
  cout<<"####################################"<<endl;
  pg1.eliminarTupla(est3);
  pg1.toString();
}
