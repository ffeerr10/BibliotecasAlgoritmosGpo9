#ifndef ARREGLODIN_H_
#define ARREGLODIN_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct arrDinInt {
   int *arreglo;
   int tamanio;
} ArregloDinamico;

ArregloDinamico arrDinInt_nuevo();

void arrDinInt_ingresar(ArregloDinamico* arrDin, int valor);

void arrDinInt_imprimir(ArregloDinamico* arrDin);

/*int* arrDinInt_modificar(int * arreglo, int tamanio, int posicion);

int arrDinInt_remover(int * arreglo, int tamanio, int posicion);*/

void arrDinInt_cerrar(ArregloDinamico* arrDin);


#endif // ARREGLODIN_H_