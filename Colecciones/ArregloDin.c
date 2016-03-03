#include "ArregloDin.h"

ArregloDinamico arrDinInt_nuevo(){
	ArregloDinamico arrDin;
	arrDin.arreglo = NULL;
	arrDin.tamanio = 0;
	return arrDin;
}

void arrDinInt_ingresar(ArregloDinamico* arrDin, int valor){
	arrDin->arreglo = realloc(arrDin->arreglo, (arrDin->tamanio+1)*sizeof(int) );
	arrDin->arreglo[arrDin->tamanio] = valor;
	arrDin->tamanio++;
}

void arrDinInt_imprimir(ArregloDinamico* arrDin){
	for (int i = 0; i < arrDin->tamanio; ++i)
	{
		printf("%d\n",arrDin->arreglo[i]);
	}
}

/*int* arrDinInt_modificar(int * arreglo, int tamanio, int posicion){
	return arreglo;
}

int arrDinInt_remover(int * arreglo, int tamanio, int posicion){
	return tamanio;
}*/

void arrDinInt_cerrar(ArregloDinamico* arrDin){
	free(arrDin->arreglo);
}