#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#define MAX 100
class cListaAviones
{
	cAvion** ListaAviones;
	int ca; //cantidad actual

public:
	cListaAviones(unsigned int L = MAX);
	~cListaAviones();
	bool Agregar(cAvion* Avion);
	void operator+(cAvion* newAvion);
	cAvion* Quitar(int pos);
	bool Eliminar(int pos);
	cAvion* operator[](int posic_i); //=buscar???
	int Buscar(int ID);
	void Listar(); //imprime la lista en pantalla
	int PasajerosTotal();
	cAvion** getLista() { return ListaAviones; }; //puntero simple o doble?
	friend class cAeropuerto; // para que pueda acceder a la lista de aviones y sus atributos
};

