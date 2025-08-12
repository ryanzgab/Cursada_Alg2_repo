
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAD 25

/* 	El centro de distribuci�n similar al de Mercado Libre, requiere un programa que permita 
	llevar un registro actualizado de los paquetes que ser�n almacenados en los camiones de transporte. 
	Para ello, se almacena en una cola la siguiente informaci�n de los paquetes: 
		c�digo �nico de paquete, destinatario, direcci�n, c�digo postal, es fr�gil(true/false).*/

/* Declaraci�n de tipos de datos personalizados */

/* 	Codificar en lenguaje C, las estructuras de datos necesarias 
	para la declaraci�n del tipo tPaquetes adecuado.*/		
typedef char tString[MAX_CAD];

typedef struct {
	int codigo;
	tString destinatario;
	tString direccion;
	int codpostal;
	bool fragil;
}tPaquete;

typedef struct nodo{
	tPaquete paquete;
	struct nodo* siguiente;
}tNodoPaquete;

typedef struct{
	tNodoPaquete* principio;
	tNodoPaquete* final;
}tPaquetes;

/* Declaraci�n de prototipos de funciones */
bool colaVacia(tPaquetes);
void inicializarCola();
void agregarP(tPaquete);
void eliminarPaquete();
void depositarEnCamion(tPaquetes);
void visualizarPaquetes(tPaquetes, bool);
tPaquete InsertarDatos();
void menu();
/* Declaraci�n de variables globales */
tPaquetes paquetes;


int main(){
	 inicializarCola();
	 menu();
	 return 0;
}
bool colaVacia(tPaquetes ppaquetes) {
	return ppaquetes.principio == NULL && ppaquetes.final == NULL;
}

void inicializarCola(){
	paquetes.principio = NULL;
	paquetes.final = NULL;
	printf("Cola de paquetes activa ...\n");
}

void agregarP(tPaquete pDatos) {
	/* Crear un nodo y asignar memoria */
	tNodoPaquete * nuevoPaquete = (tNodoPaquete *) malloc(sizeof(tNodoPaquete));
	
    nuevoPaquete->paquete= pDatos;
	nuevoPaquete->siguiente = NULL; 
	
	if(colaVacia(paquetes)) {
		/* se inserta el primer elemento */
		paquetes.principio = nuevoPaquete;
		paquetes.final = nuevoPaquete;
	}else{
		/* ya hay elementos, se inserta uno nuevo por el final */
		paquetes.final->siguiente =nuevoPaquete;
		paquetes.final = nuevoPaquete;
	}
	printf("Paquete cargado!\n");
}
void eliminarPaquete(){

	if(colaVacia(paquetes)) {
	         	printf("\nNo hay paquetes en la cola\n");	
   	}
	else{
	 	tNodoPaquete * Suprimir = paquetes.principio;
		
	if(paquetes.principio == paquetes.final){
		  	inicializarCola();
	}else{
	paquetes.principio = Suprimir->siguiente; 
	}	

    free(Suprimir);
     Suprimir = NULL;
	}
	         
}

/* Implementaci�n de funciones */

/* 	Una funci�n que permita indicar que un paquete se almacen� en el cami�n,
	para ello, se debe obtener el pr�ximo paquete, indicar con una leyenda 
	que se insertar� en el cami�n y quitarlo de la cola de paquetes. */
void depositarEnCamion(tPaquetes pPaquetes) {
	if(colaVacia(pPaquetes)){
		printf("No hay paquetes pendientes de depositar\n");
	}else{
		tNodoPaquete * proximo = paquetes.principio;
		paquetes.principio = paquetes.principio->siguiente;
		
		printf("El paquete que se depositara en el camion es: %d-%s | %s CP: %d",
				proximo->paquete.codigo, 
				proximo->paquete.destinatario,			
				proximo->paquete.direccion,
				proximo->paquete.codpostal);
			
		eliminarPaquete();
	}
}


/* 	Una funci�n que permita visualizar el detalle de paquetes seg�n un valor booleano que se recibe como par�metro 
	que cuando llega true significa que se desea obtener informaci�n de paquetes marcados como fr�giles, 
	y como no fr�giles en caso contrario. */
void visualizarPaquetes(tPaquetes pPaquetes, bool pEsFragil) {
	bool fragil = pEsFragil;
	printf("*** Paquetes marcados como '%s' ***\n", pEsFragil == true ? "fragiles" : "no fragiles");
	
	if(colaVacia(pPaquetes)){
		printf("No hay paquetes para visualizar\n");
	}else{
		printf("\nCod. unico | Destinatario | Direccion | CP\n");
		int cantidadPaquetesFiltrado = 0;
		tNodoPaquete * listaPaquetes = pPaquetes.principio;
		while(listaPaquetes != NULL) {
			/*	Filtrar por los paquetes que coinciden 
				con el par�metro relacionado a si es fr�gil o no */		
			if(listaPaquetes->paquete.fragil == pEsFragil) {
				cantidadPaquetesFiltrado++;
				printf("%d | %s | %s | %d\n", 
					listaPaquetes->paquete.codigo,
					listaPaquetes->paquete.destinatario,
					listaPaquetes->paquete.direccion,
					listaPaquetes->paquete.codpostal);
			}			
					
			listaPaquetes = listaPaquetes->siguiente;
		}
		printf("Total de paquetes marcados como '%s': %d\n", 
				pEsFragil == true ? "fragiles" : "no fragiles", 
				cantidadPaquetesFiltrado);
	}
}	

tPaquete InsertarDatos(){
	tPaquete paquete;
	
	int codigo;
    tString destinatario;
    tString direccion;
    int codpostal;
	bool fragil;
	
		printf("\t CODIGO  \n");
	    fflush(stdin);
	    scanf("%d", &paquete.codigo);
	    printf("\t destinatario \n");
	    fflush(stdin);
	    scanf("%s", &paquete.destinatario);
	    printf("\t direccion \n");
	    fflush(stdin);
	    scanf("%s", &paquete.direccion);
	    printf("\t CODIGO POSTAL \n");
	    fflush(stdin);
	    scanf("%d", &paquete.codpostal);
	    printf("ingrese '1' si el paquete es fragil o 0 si no\n");
	    fflush(stdin);
	    scanf("%d", &paquete.fragil);
        return paquete;
}
    
     
void menu(){

   	bool pEsFragil;
   	
	int op;
	printf("\t1 - para ingresar Datos del paquete\n");
	printf("\t2-depositar en camion y quitar de la cola\n");
	printf("\t3 - Visualizar los paquetes \n");
	fflush(stdin);
	scanf("%d", &op);
	switch(op){
    case 1:{

	    tPaquete paquete = InsertarDatos();
	    agregarP(paquete);
	    menu();
		break;
		}
	case 2:{
		    depositarEnCamion(paquetes);
			menu();
			break;
		}
	
	case 3:{
	     	printf(" 1 para fragiles, 0 para no fragiles");
		    fflush(stdin);
	     	scanf("%d", &pEsFragil);
	        visualizarPaquetes(paquetes, pEsFragil);
		    menu();
		    break;
		}
	}

}
	
