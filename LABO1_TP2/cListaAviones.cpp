#include "cListaAviones.h"

cListaAviones::cListaAviones(unsigned int L)
{
	ca = 0;
	//inicializamos todos los punteros de la lista a null
	ListaAviones = new cAvion * [MAX];
	for (int i = 0; i < L; i++)
	{
		ListaAviones[i] = NULL; 
	}

}

cListaAviones::~cListaAviones() //HACER:
{
		if (ListaAviones != NULL) {

			for (int i = 0; i < ca; i++)
			{
				if (ListaAviones[i] != NULL)
					ListaAviones[i] = NULL;
			}

		}

}

bool cListaAviones::Agregar(cAvion* Avion)
{
	if (Avion != NULL)
	{
		ListaAviones[ca] = Avion;
		ca++;
		return true;
	}
	return false;
}

bool cListaAviones::operator+(cAvion* newAvion)
{
	if (this->ListaAviones[ca] != NULL) {
		return false;
		//throw new exception;
	}
	this->ListaAviones[ca] = newAvion;
}

cAvion* cListaAviones::Quitar(int pos)
{
	if (pos >= ca || ListaAviones[pos] == NULL) //no existe tal pos o el puntero a esa posici�n esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	

		ca--; //disminuimos la cantidad actual
		cAvion* aux = ListaAviones[pos]; //igualamos el aux al puntero en la posici�n para despues devolverlo
		for (int i = pos; i < ca; i++) 
		{
			ListaAviones[i] = ListaAviones[i + 1];
		}
		ListaAviones[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	
}

bool cListaAviones::Eliminar(int pos)
{
	cAvion* aux = Quitar(pos);
	if (aux == NULL)
	{
		cout << "No se puede eliminar";
		return false;
	}
	else if (aux != NULL)
	{
		aux = NULL;
		cout << "Se elimino con exito";
		return true;
	}
}

cAvion* cListaAviones::operator[](int posic_i) //HACER
{
	return nullptr;
}

int cListaAviones::Buscar(int ID) 
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaAviones[i]->getID() == ID)
		{
			return i;
			break;
		}
	}
	return -1;
}

void cListaAviones::Listar() //HACER
{
	for (int i = 0; i < ca; i++)
	{
		ListaAviones[i]->toString();
	}
}

int cListaAviones::PasajerosTotal()
{
	float pesoTotal = 0;
	for (int i = 0; i < ca; i++)
	{
		pesoTotal = pesoTotal + ListaAviones[i]->getCantPasajeros();
	}
	return pesoTotal;
}
