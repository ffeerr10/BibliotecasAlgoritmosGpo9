#include <stdio.h>
#include "ManejoDeArchivos/ManejoArch.h"

int main(){
	FILE *fp = abrirArchParaEscritura("archivo.txt"); 

	escribirLinea(fp,"Poyo");

	cerrarArch(fp); 
	return 0;
}