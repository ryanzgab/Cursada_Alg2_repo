#include <stdio.h>
#include <string.h>

void cargarDatosRepetitivo();
void cargarDatosRecursivo();
void cargarDatosRecursivo_v2(char);

int main() {
	 // cargarDatosRepetitivo();
	  cargarDatosRecursivo();
	//cargarDatosRecursivo_v2(1);
	return 0;
}

//con esctructura repetitiva
void cargarDatosRepetitivo() {	
	char opc = '1';	
	while (opc != '0') {
		printf("Ingresar dato: "); 
		fflush(stdin);
		scanf("%c", &opc); 
		printf("\n");
	}
}

//con recursividad
void cargarDatosRecursivo() {
	char opc;
	printf("Ingresar dato - r: "); 
	fflush(stdin);
	scanf("%c", &opc); 
	printf("\n");
	
	if(opc != '0'){
		cargarDatosRecursivo();
	}
}

void cargarDatosRecursivo_v2(char pOpcion) {		
	printf("Ingresar dato - r2: "); 
	fflush(stdin);
	scanf("%c", &pOpcion); 
	printf("\n");
	
	if(pOpcion != '0'){
		cargarDatosRecursivo_v2(pOpcion);
	}
}


