/*
 * Tupla.cpp
 *
 *  Created on: 23/05/2019
 *      Author: juanferna.perez
 */



#include"Tupla.h"
#include<iostream>

Tupla::Tupla(){
	this->id = -1;
	this->nombre = "";
	this->apellido = "";
}

Tupla::Tupla(int id, string nombre, string apellido){
	this->id = id;
	this->nombre = nombre;
	this->apellido = apellido;
}

int Tupla::getID(){
	return this->id;
}

string Tupla::getNombre(){
	return this->nombre;
}

string Tupla::getApellido(){
	return this->apellido;
}
