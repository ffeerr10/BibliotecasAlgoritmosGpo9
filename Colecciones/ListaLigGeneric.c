#include "ListaLigGeneric.h"

/*
typedef struct nodoGenerico {
   void *valor;
   struct nodoGenerico *sig;
} Nodo;

typedef struct listaLigadaGenerica {
   Nodo *inicio;
   unsigned int unidad;
} ListaLigada;
*/

ListaLigada* listaL_crear(unsigned int unidad){
	ListaLigada *lista = malloc(sizeof(ListaLigada));
	lista->inicio = NULL;
	lista->unidad = unidad;
	return lista;
}

void listaL_agregar(ListaLigada *lista, void *dato){
	Nodo *nodoActual = lista->inicio;
	if(lista->inicio==NULL){
		nodoActual = malloc(sizeof(Nodo));
		nodoActual->valor = malloc(lista->unidad);
		memcpy(nodoActual->valor,dato,lista->unidad);
		nodoActual->sig = NULL;
		lista->inicio = nodoActual;
	}
	else{
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		Nodo *nuevoNodo = malloc(sizeof(Nodo));
		nuevoNodo->valor = malloc(lista->unidad);
		memcpy(nuevoNodo->valor,dato,lista->unidad);
		nuevoNodo->sig = NULL;
		nodoActual->sig = nuevoNodo;
	}
}

void listaL_push(ListaLigada *lista, void *dato){
	listaL_ingresar(lista,dato,0);
}

void listaL_ingresar(ListaLigada *lista, void *dato, unsigned int indice){
	Nodo *nodoActual = lista->inicio;
	if(lista->inicio==NULL || indice == 0){
		nodoActual = malloc(sizeof(Nodo));
		nodoActual->valor = malloc(lista->unidad);
		memcpy(nodoActual->valor,dato,lista->unidad);
		nodoActual->sig = lista->inicio;
		lista->inicio = nodoActual;
	}
	else{
		Nodo *anterior = lista->inicio;
		unsigned int i = 0;
		while(i<indice && nodoActual != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		Nodo *nuevoNodo = malloc(sizeof(Nodo));
		nuevoNodo->valor = malloc(lista->unidad);
		memcpy(nuevoNodo->valor,dato,lista->unidad);
		nuevoNodo->sig = nodoActual;
		anterior->sig = nuevoNodo;
	}
}

void* listaL_contiene(ListaLigada *lista, void *dato){
	Nodo *nodoActual = lista->inicio;
	while(nodoActual != NULL){
		if(0 == memcmp(nodoActual->valor,dato,lista->unidad)){
			return nodoActual->valor;
		}
		nodoActual = nodoActual->sig;
	}
	return NULL;
}

unsigned int listaL_size(ListaLigada *lista){
	Nodo *nodoActual = lista->inicio;
	int i = 0;
	while(nodoActual != NULL){
		nodoActual = nodoActual->sig;
		i++;
	}
	return i;
}

void* listaL_obtener(ListaLigada *lista, unsigned int indice){
	Nodo *nodoActual = lista->inicio;
	int i = 0;
	if(lista->inicio==NULL){
		return NULL;
	}
	while(i<indice && nodoActual->sig != NULL){
		nodoActual = nodoActual->sig;
		i++;
	}
	return nodoActual->valor;
}

void* listaL_pop(ListaLigada *lista, void *dato){
	if(lista->inicio==NULL){
		return NULL;
	}
	else{
		Nodo *nodoSiguiente = lista->inicio->sig;
		memcpy(dato,lista->inicio->valor,lista->unidad);
		free(lista->inicio->valor);
		free(lista->inicio);
		lista->inicio = nodoSiguiente;
		return dato;
	}
}

void listaL_remover(ListaLigada *lista, unsigned int indice){
	Nodo *nodoActual = lista->inicio;
	if(lista->inicio==NULL){
		return;
	}
	else if(indice == 0){
		nodoActual = lista->inicio->sig;
		free(lista->inicio->valor);
		free(lista->inicio);
		lista->inicio = nodoActual;
		return;
	}
	else{
		Nodo *anterior = lista->inicio;
		int i = 0;
		while(i<indice && nodoActual->sig != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		anterior->sig = nodoActual->sig;
		free(nodoActual->valor);
		free(nodoActual);
		if(i==0){
			lista->inicio=NULL;
			return;
		}
	}
}

void listaL_limpiar(ListaLigada *lista){
	if(lista->inicio==NULL){
		return;
	}
	Nodo *nodoActual = lista->inicio;
	Nodo *nodoSig = nodoActual->sig;
	while(nodoSig != NULL){
		free(nodoActual->valor);
		free(nodoActual);
		nodoActual = nodoSig;
		nodoSig = nodoActual->sig;
	}
	free(nodoActual->valor);
	free(nodoActual);
}

void listaL_borrar(ListaLigada *lista){
	listaL_limpiar(lista);
	free(lista);
}