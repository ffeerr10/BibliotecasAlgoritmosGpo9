#include "../Colecciones/ArregloDin.h"

int main(){
	ArregloDinamico arrDin;

	arrDin = arrDinInt_nuevo();

	arrDinInt_ingresar(&arrDin,25);
	arrDinInt_ingresar(&arrDin,87);

	arrDinInt_imprimir(&arrDin);

	arrDinInt_cerrar(&arrDin);

	return 0;
}