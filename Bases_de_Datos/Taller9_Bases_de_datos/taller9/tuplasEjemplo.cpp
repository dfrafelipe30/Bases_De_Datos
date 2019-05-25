#include <iostream>
#include <string>
#include "tuplas.cpp"
using namespace std;

int main(){
  tuplaEstudiante est1 = tuplaEstudiante("Felipe","Guzman","1007231499","MACC");
  cout<<est1.getNombre()<<endl;
  cout<<est1.getApellido()<<endl;
  cout<<est1.getCedula()<<endl;
  cout<<est1.getCarrera()<<endl;

  cout<<est1.getSize()<<endl,
  cout<<est1.toString()<<endl;
}
