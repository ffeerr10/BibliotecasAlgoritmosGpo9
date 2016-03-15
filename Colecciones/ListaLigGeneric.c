#include "ListaLigGeneric.h"

Nodo* listaL_ingresar(NodoInt *inicio, int dato){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL){
		nodoActual = malloc(sizeof(NodoInt));
		nodoActual->valor = dato;
		nodoActual->sig = NULL;
		inicio = nodoActual;
	}
	else{
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		NodoInt *nuevoNodo = malloc(sizeof(NodoInt));
		nuevoNodo->valor = dato;
		nuevoNodo->sig = NULL;
		nodoActual->sig = nuevoNodo;
	}
	return inicio;
}


Nodo* listaL_ingresarEn(NodoInt *inicio, int dato, unsigned int indice){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL || indice == 0){
		nodoActual = malloc(sizeof(NodoInt));
		nodoActual->valor = dato;
		nodoActual->sig = inicio;
		inicio = nodoActual;
	}
	else{
		NodoInt *anterior = inicio;
		int i = 0;
		while(i<indice && nodoActual != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		NodoInt *nuevoNodo = malloc(sizeof(NodoInt));
		nuevoNodo->valor = dato;
		nuevoNodo->sig = nodoActual;
		anterior->sig = nuevoNodo;
	}
	return inicio;
}

int listaInt_obtener(NodoInt *inicio, unsigned int indice){
	NodoInt *nodoActual = inicio;
	int i = 0;
	if(inicio==NULL){
		return 0;
	}
	while(i<indice && nodoActual->sig != NULL){
		nodoActual = nodoActual->sig;
		i++;
	}
	return nodoActual->valor;
}

void listaInt_imprimir(NodoInt *inicio){
	NodoInt *nodoActual = inicio;
	int i =0;
	while(nodoActual != NULL){
		printf("%d:\t%d\n",i++,nodoActual->valor);
		nodoActual = nodoActual->sig;
	}
	printf("---------------\n");
}

Nodo* listaInt_remover(NodoInt *inicio, unsigned int indice){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL){
		return NULL;
	}
	else if(indice == 0){
		nodoActual = inicio->sig;
		free(inicio);
		return nodoActual;
	}
	else{
		NodoInt *anterior = inicio;
		int i = 0;
		while(i<indice && nodoActual->sig != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		anterior->sig = nodoActual->sig;
		free(nodoActual);
		if(i==0){
			return NULL;
		}
	}
	return inicio;
}

NodoInt* listaInt_borrar(NodoInt *inicio){
	if(inicio==NULL){
		return NULL;
	}
	NodoInt *nodoActual = inicio;
	NodoInt *nodoSig = inicio->sig;
	while(nodoSig != NULL){
		free(nodoActual);
		nodoActual = nodoSig;
		nodoSig = nodoActual->sig;
	}
	free(nodoActual);
	return NULL;
}