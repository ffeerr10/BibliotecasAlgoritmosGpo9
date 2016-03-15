#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Colecciones/ListaLigGeneric.h"


int main(){
	ListaLigada* listaEntero = listaL_crear(sizeof(int));

	int val = 5;
	listaL_ingresar(listaEntero,&val,0);
	val = 4;
	listaL_push(listaEntero,&val);
	val = 3;
	listaL_agregar(listaEntero,&val);
	val = 2;
	listaL_agregar(listaEntero,&val);

	int *ap;
	ap = listaL_pop(listaEntero,&val);
	printf("%d\n",val);
	ap = listaL_obtener(listaEntero,0);
	printf("%d\n",*ap);
	ap = listaL_obtener(listaEntero,1);
	printf("%d\n",*ap);
	ap = listaL_obtener(listaEntero,2);
	printf("%d\n",*ap);
	ap = listaL_obtener(listaEntero,3);
	printf("%d\n",*ap);


	listaL_borrar(listaEntero);
	return 0;
}