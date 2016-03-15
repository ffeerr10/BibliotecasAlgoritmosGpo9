#ifndef LISTALIGGENERIC_H_
#define LISTALIGGENERIC_H_

/*
*	Lista Ligada Generica
*
*	- Esta lista tiene la característica de poder almacenar cualquier tipo de dato por medio del uso de apuntadores
*/

//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   unsigned int unidad;
} ListaLigada;


ListaLigada* listaL_crear(unsigned int unidad);

void listaL_agregar(ListaLigada *lista, void *dato);

void listaL_push(ListaLigada *lista, void *dato);

void listaL_ingresar(ListaLigada *lista, void *dato, unsigned int indice);

unsigned int listaL_size(ListaLigada *lista);

void* listaL_obtener(ListaLigada *lista, unsigned int indice);

void* listaL_contiene(ListaLigada *lista, void *dato);

void* listaL_pop(ListaLigada *lista, void *dato);

void listaL_remover(ListaLigada *lista, unsigned int indice);

void listaL_limpiar(ListaLigada *lista);

void listaL_borrar(ListaLigada *lista);


#endif // LISTALIGGENERIC_H_