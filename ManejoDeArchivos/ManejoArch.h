#ifndef MANEJOARCH_H_
#define MANEJOARCH_H_


FILE* abrirArchParaEscritura(char *nombreArch); 

void escribirLinea(FILE *apArch, char *linea);

void cerrarArch(FILE *apArch);  

#endif // MANEJOARCH_H_