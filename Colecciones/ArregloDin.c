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

	for (int i = 0; i < arrDin->tamanio; ++i){
		printf("%d\n",arrDin->arreglo[i]);
	}
	printf("---------------\n");

}

void arrDinInt_remover(ArregloDinamico* arrDin, int posicion){

	if(arrDin->tamanio > 1){
		for (int i = posicion; i < arrDin->tamanio - 1 ; ++i)
		{
			arrDin->arreglo[i] = arrDin->arreglo[i+1];	
		}
	}

	arrDin->arreglo = realloc(arrDin->arreglo, (arrDin->tamanio-1)*sizeof(int) );
	arrDin->tamanio--;

}

void arrDinInt_borrar(ArregloDinamico* arrDin){

	free(arrDin->arreglo);
	arrDin->arreglo = NULL;
	arrDin->tamanio = 0;

}


void arrDinInt_volcar(ArregloDinamico* arrDin, char *nombreArch){
	FILE *f;
	f = fopen(nombreArch, "wb");
	if(f == 0) {
		printf("Archivo %s no se pudo abrir\n", nombreArch);
		return ;
	}

	fwrite(arrDin->arreglo,sizeof(int),arrDin->tamanio,f);

	fclose(f);
}


int arrDinInt_cargar(ArregloDinamico* arrDin, char *nombreArch){

	FILE *f;
	f = fopen(nombreArch, "rb");
	if(f == 0) {
		printf("Archivo %s no se pudo abrir\n", nombreArch);
		return 0;
	}

	arrDinInt_borrar(arrDin);

	fseek(f, 0, SEEK_END);
	int bytes = ftell(f);
	int N = bytes/sizeof(int);
	rewind(f);

	arrDin->arreglo = (int*)malloc(bytes);

	int leidos = fread(arrDin->arreglo,sizeof(int),N,f);

	arrDin->tamanio = leidos;

	fclose(f);
	return leidos; 
}