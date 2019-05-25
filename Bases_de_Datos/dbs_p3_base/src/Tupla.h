/*
 * ArbolB+.h
 *
 *  Created on: 23/05/2019
 *      Author: juanferna.perez
 */

#ifndef TUPLA_H_
#define TUPLA_H_
#include<string>
using namespace std;

class Tupla {
public:

	Tupla();

	Tupla(int id, string nombre, string apellido);

	int getID();

	string getNombre();

	string getApellido();

private:
	/* Atributos */
	int id; 			/* id de estudiante */
	std::string nombre; 		/* nombre de estudiante */
	std::string apellido; 	/* apellido de estudiante */

};



#endif /* TUPLA_H_ */







