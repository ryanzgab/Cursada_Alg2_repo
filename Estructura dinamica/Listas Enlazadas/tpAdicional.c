#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCAR 20

typedef char tString [MAXCAR];

/*Estructura de la lista*/
typedef struct 
{
    tString nombreApellido;
    tString domicilio;
    int tipoVianda;
    int cantViandas;
}tVianda;

/*Estructura del Nodo*/
typedef struct nodoVianda 
{
    tVianda vianda;
    struct nodoVianda* sig;
}tListaViandas;

/*Funciones de Lista*/
void incializarListas();

void ingresarPedido();
void insertarPrimerDato(tVianda);
void insertarSegundoDato(tVianda);
void eliminarDato();

void insertarDatoPos(int, tVianda);
void elimiarDatoPos(int);

void menu();

tListaViandas* viandas;
int opciones;
bool repite=true;

int main()
{
    incializarListas();
    menu();
    return 0;
}

void ingresarPedido()
{
    tVianda vianda;
    printf("ingrese nombre y Apellido:");
    fflush(stdin);
    scanf("%[^\n]s", &vianda.nombreApellido);
    
    printf("ingresar domicilio: ");
    fflush(stdin);
    scanf("%[^\n]s", &vianda.domicilio);
    
    printf("ingrese tipo de vianda(1-Light, 2-Sin Sal, 3-Comun): ");
    scanf("%d",&vianda.tipoVianda);
    printf("ingrese cantidad de vianda:");
    scanf("%d", &vianda.cantViandas);

    insertarPrimerDato(vianda);

    menu();
}

void incializarListas()
{
    viandas= NULL;
    printf("\n**************************************************\n");
	printf("            Lista de productos inicializada");
	printf("\n**************************************************\n");
}

void insertarPrimerDato(tVianda pVianda)
{
    tListaViandas* nuevopedido;
    nuevopedido=(tVianda*)malloc(sizeof(tVianda));
    nuevopedido->vianda=pVianda;
    nuevopedido->sig=NULL;

    viandas=nuevopedido;
    printf("\n\tProducto Cargado");
}

void insertarSegundoDato(tVianda pVianda)
{
    tListaViandas* nuevopedido;
    nuevopedido=(tListaViandas*)malloc(sizeof(tListaViandas));
    nuevopedido->vianda= pVianda;
    nuevopedido->sig=viandas;
    printf("\n\tProducto Cargado");
}

void eliminarDato()
{
    tListaViandas * pedidoSuprimir = viandas;
    viandas = viandas->sig;

    printf("\n**************************************************\n");
	printf("                   Pedido Quitado");
    printf("                   %s", pedidoSuprimir->vianda.nombreApellido);
	printf("\n**************************************************\n");
    free (pedidoSuprimir);
    pedidoSuprimir=NULL;

}

void menu()
{
    do {		//Usar "Do" para repetir el menu.
	
	
	
	
	printf("\t----PEDIDOS YA----\n\n");
	
	
	printf("\tElija la Tarea que desea realizar\n");
	
	
	printf("\t\t1.Ingresar Pedidos\n");
	printf("\t\t2.Ingresar Pedido (Pos. Determinada)\n");
	printf("\t\t3.Eliminar Pedido\n");
	printf("\t\t4.\n");
	printf("\t\t5.\n");
	printf("\t\t0.\n");
	printf("\nOpcion:");
	scanf("%d", &opciones);
	
	//Selector
	switch(opciones){
		case 1:
            ingresarPedido(); 
			break;
		case 2:
			
			break;
		
		case 3:
			eliminarDato();
			break;
	
		case 4:
			
			break;
			
		case 5:
			
			break;

        case 0:
			repite= false;
			break;
	}
	
	} while(repite);
	
}