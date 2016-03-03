#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Colecciones/ArregloDin.h"


int main(){
	ArregloDinamico arrDin;

	arrDin = arrDinInt_nuevo();

	arrDinInt_cargar(&arrDin,"arrDinInt.bin");

	arrDinInt_imprimir(&arrDin);

	/*arrDinInt_ingresar(&arrDin,25);
	arrDinInt_ingresar(&arrDin,87);


	
	int N = 10;
	srand(time(NULL));
	for (int i = 0; i < N; ++i){
		int aleatorio =rand() % 1000;

		arrDinInt_ingresar(&arrDin,aleatorio);
	}	
	
	

	arrDinInt_imprimir(&arrDin);

	arrDinInt_remover(&arrDin,5);

	arrDinInt_imprimir(&arrDin);

	arrDinInt_volcar(&arrDin,"arrDinInt.bin");*/

	arrDinInt_borrar(&arrDin);

	return 0;
}