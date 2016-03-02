#include "stdio.h" 
#include "ManejoArch.h" 

FILE* abrirArchParaEscritura(char *nombreArch){
	return fopen(nombreArch,"w");
}

void escribirLinea(FILE *apArch, char *linea){
	int i=0;
	while(linea[i]!='\0'){
		fputc(linea[i], apArch);
		i++;
	}
	fputc('\n', apArch);
}

void cerrarArch(FILE *apArch){
	fclose(apArch);
} 