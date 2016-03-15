#ifndef LISTALIGGENERIC_H_
#define LISTALIGGENERIC_H_

/*
*	Lista Ligada Generica
*
*	- Esta lista tiene la característica de poder almacenar cualquier tipo de dato por medio del uso de apuntadores
*/

#include <stdio.h>
#include <stdlib.h>

/*Estructura Nodo
	Guarda un nodo para una lista ligada generica.
		valor - Apuntador al valor almacenado
		sig   - Apuntador al siguiente nodo de la lista
*/
typedef struct nodoGenerico {
   void *valor;
   struct nodoGenerico *sig;
} Nodo;

typedef struct listaLigadaGenerica {
   Nodo *inicio;
   Nodo *final;
} ListaLigada;


Nodo* listaL_ingresar(NodoInt **inicio, int dato);

Nodo* listaL_ingresarEn(NodoInt **inicio, int dato, unsigned int indice);

void* listaL_obtener(NodoInt **inicio, unsigned int indice);

Nodo* listaL_remover(NodoInt **inicio, unsigned int indice);

Nodo* listaL_borrar(NodoInt **inicio);


#endif // LISTALIGGENERIC_H_