#ifndef ARREGLODIN_H_
#define ARREGLODIN_H_

#include <stdio.h>
#include <stdlib.h>

/*Estructura arrDinInt
	Controla un arreglo dinámico de enteros.
		arreglo - Apuntador al arreglo dinámico
		tamanio - Cantidad de números en la lista
*/
typedef struct arrDinInt {
   int *arreglo;
   int tamanio;
} ArregloDinamico;

/*Función arrDinInt_nuevo
	Regresa un arrDinInt en ceros listo para usar.
*/
ArregloDinamico arrDinInt_nuevo();

/*Función arrDinInt_ingresar
	Agrega un valor al final del arreglo dinámico, aumentando la memoria correspondiente.
*/
void arrDinInt_ingresar(ArregloDinamico* arrDin, int valor);

/*Función arrDinInt_imprimir
	Imprime en pantalla todos los datos del arreglo dinámico
*/
void arrDinInt_imprimir(ArregloDinamico* arrDin);

/*Función arrDinInt_remover
	Remueve un valor en una posición en especifico del arreglo, disminuyendo la memoria correspondiente.
*/
void arrDinInt_remover(ArregloDinamico* arrDin, int posicion);

/*Función arrDinInt_borrar
	Libera la memoria del areglo y lo deja en ceros
*/
void arrDinInt_borrar(ArregloDinamico* arrDin);

/*Función arrDinInt_volcar
	Guarda los bytes del arreglo en un archivo binario
*/
void arrDinInt_volcar(ArregloDinamico* arrDin, char *nombreArch);

/*Función arrDinInt_cargar
	Inicia un arreglo con los bytes de un archivo binario.
*/
int arrDinInt_cargar(ArregloDinamico* arrDin, char *nombreArch);


#endif // ARREGLODIN_H_