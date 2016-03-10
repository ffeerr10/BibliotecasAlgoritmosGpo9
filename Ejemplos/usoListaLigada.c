#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Colecciones/ListaLigInt.h"


int main(){
	NodoInt *lista = NULL;

	lista = listaInt_ingresar(lista,5);
	lista = listaInt_ingresar(lista,6);
	lista = listaInt_ingresar(lista,7);
	lista = listaInt_ingresar(lista,8);
	lista = listaInt_ingresar(lista,4);

	printf("Valor:%d\n",listaInt_obtener(lista,3));
	lista = listaInt_ingresarEn(lista,55,4);
	
	listaInt_imprimir(lista);

	lista = listaInt_remover(lista,0);

	listaInt_imprimir(lista);

	lista = listaInt_remover(lista,2);
	

	listaInt_imprimir(lista);
	
	lista = listaInt_borrar(lista);

	listaInt_imprimir(lista);

	lista = listaInt_ingresarEn(lista,1,0);
	lista = listaInt_ingresarEn(lista,2,0);
	lista = listaInt_ingresarEn(lista,3,0);

	listaInt_imprimir(lista);

	lista = listaInt_borrar(lista);
	return 0;
}