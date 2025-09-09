/*1. Un nuevo navegador de internet requiere que se agregue un módulo para guardar el historial de
sitios web visitados por el usuario. Para ello se almacena en una pila la siguiente información de los
sitios web: fecha y hora(string), url del sitio, y código de tipo de clasificación del sitio (1-
Empresariales 2-Gubernamentales 3-Redes Sociales). Los sitios se insertan en la pila, según el orden
en el cual fueron visitados. Se requiere:
a) Codificar en lenguaje C, las estructuras de datos necesarias para la declaración del tipo
tPilaSitiosWeb adecuado.
b) Una función que permita visualizar el detalle de sitios web que fueron visitados según el tipo
de clasificación que se recibe como parámetro. Además, se pide calcular el porcentaje de visitas
a sitios web que coincidan con ese tipo de clasificación respecto del total sitios visitados.
c) Escribir una función que permita borrar todo el historial del navegador. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 100

typedef char tString[MAX]; 

tString opciones[]={"[#] Buscar", "[#] Historial","[#] Historial por Tipo" , "[#] Borrar Historial", "[#] Salir"};
int opcion=0;
int max_opciones = 4; // Ajusta según la cantidad de opciones
int i;

tString tipoSitio[]={"EMPRESARIALES","GUBERNAMENTALES","REDES SOCIALES"};

time_t t;
struct tm *tiempo;


typedef struct{
   int hora, min, tipoWeb;
   tString urlSitio;
}tInfoSitioWeb;

typedef struct nodo{
    tInfoSitioWeb SitioWeb;
    struct nodo* siguiente; 
}tPilaSitiosWeb;

void menu(tPilaSitiosWeb**);
void horaActual();

void inicializarPila(tPilaSitiosWeb**);
bool pilaVacia(tPilaSitiosWeb*);
void apilarPila(tPilaSitiosWeb**, tInfoSitioWeb*);
void visualizarSitiosWeb(tPilaSitiosWeb*);
void visualizarPorClaf(tPilaSitiosWeb*,int);
void analizarTipoSitio(tInfoSitioWeb*);
float calcularPorcentajeSitio(int, int, int);

void eliminarPila(tPilaSitiosWeb**);

int main()
{
    tPilaSitiosWeb* PilasSitiosWeb;
    inicializarPila(&PilasSitiosWeb);
    menu(&PilasSitiosWeb);
    return 0;
}

void menu(tPilaSitiosWeb** pPilaSitioWeb)
{
    while (1) {
        system("cls"); // Limpia la pantalla

        // Imprimir las opciones del menú, destacando la opción actual
    	printf("***************************************\n\n");
	    printf("*          INTERNET EXPLORER          *\n\n"); 
        printf("***************************************\n\n");
        horaActual();    
        printf("Opciones:\n");
        for (i = 0; i <= max_opciones; i++) 
        {
            if (i == opcion) {
                printf("> ");
            } else {
                printf("  ");
            }
            printf("%s\n", opciones[i]);
        }
        char tecla = getch();
        switch (tecla) {
            case 72: // Flecha arriba
                if (opcion > 0) {
                    opcion--;
                }
                break;
            case 80: // Flecha abajo
                if (opcion < max_opciones) {
                    opcion++;
                }
                break;
            case 13: // Enter
                // Ejecutar la acción correspondiente a la opción seleccionada
                switch (opcion) {
                    case 0:
                        //Prueba de nuevo sistema
                        system("cls");
                        tInfoSitioWeb sitioWeb;
                        fflush(stdin);
                        printf("Ingrese url del sitio web: ");
                        scanf("%[^\n]", sitioWeb.urlSitio);

                        sitioWeb.hora = tiempo->tm_hour;
                        sitioWeb.min = tiempo->tm_min;
                        analizarTipoSitio(&sitioWeb);
                        apilarPila(pPilaSitioWeb, &sitioWeb);
                        
                        break;
                    case 1:
                        visualizarSitiosWeb(*pPilaSitioWeb);
                        break;
                    case 2:
                        visualizarPorClaf(*pPilaSitioWeb, 0);
                        visualizarPorClaf(*pPilaSitioWeb, 1);
                        visualizarPorClaf(*pPilaSitioWeb, 2);
                        break;
                    case 3:
                        eliminarPila(pPilaSitioWeb);
                        break;
                    case 4:
                    exit(0);
                    break;
                }
                break;
        }

    }
}

void horaActual()
{
    t = time(NULL);
    tiempo = localtime(&t);

    printf("Hora actual: %02d:%02d\n\n",tiempo->tm_hour,tiempo->tm_min);
}

void inicializarPila(tPilaSitiosWeb** pPilaSitio)
{
    *pPilaSitio = NULL;
    printf("Programa Preparado.\n");
    system("pause");
}

bool pilaVacia(tPilaSitiosWeb* pPila)
{
    return pPila == NULL;
}

void apilarPila(tPilaSitiosWeb** pPilaSitio, tInfoSitioWeb* pSitio)
{
    tPilaSitiosWeb * nuevoNodo;
    nuevoNodo = (tPilaSitiosWeb*)malloc(sizeof(tPilaSitiosWeb));

    nuevoNodo->SitioWeb = *pSitio;
    nuevoNodo->siguiente = *pPilaSitio;

    *pPilaSitio = nuevoNodo;

}

void eliminarPila(tPilaSitiosWeb** pPila)
{
    tPilaSitiosWeb* aux;
 
    while (*pPila != NULL) {
	    aux = *pPila;
	   *pPila = (*pPila)->siguiente;
	    free(aux);
	}
   printf("\nHistorial borrado.\n");
   system("pause");
}

void visualizarSitiosWeb(tPilaSitiosWeb* pPilaSitioWeb)
{
    system("cls");
    tPilaSitiosWeb* pAux = pPilaSitioWeb;
    printf("========== SITIOS VISITADOS ==========\n");
    
    if(pilaVacia(pPilaSitioWeb))
    {
        printf("No has Visitado ningun Sitio.\n");
        system("pause");
    }
    while(pAux != NULL)
    {
        printf("[%02d:%02d] - %s\n",pAux->SitioWeb.hora, pAux->SitioWeb.min, pAux->SitioWeb.urlSitio);
        pAux = pAux->siguiente;
    }
    system("pause");
}


void visualizarPorClaf(tPilaSitiosWeb* pPilaSitioWeb, int pTipo)
{

    tPilaSitiosWeb* pAux = pPilaSitioWeb;
    int total = 0, contadorTipo = 0;

    printf("========== SITIOS %s VISITADOS ==========\n", tipoSitio[pTipo]);
    while (pAux != NULL)
    {
        total++;
        if(pAux->SitioWeb.tipoWeb == pTipo)
        {
            contadorTipo++;
            printf("[%02d:%02d] - %s\n",pAux->SitioWeb.hora, pAux->SitioWeb.min, pAux->SitioWeb.urlSitio);
        }
        pAux = pAux->siguiente;
    }
    system("pause");
}

void analizarTipoSitio(tInfoSitioWeb *pInfoSitioWeb)
{
    if (strcmp(pInfoSitioWeb->urlSitio, "www.instagram.com") == 0 ||
        strcmp(pInfoSitioWeb->urlSitio, "www.facebook.com") == 0 ||
        strcmp(pInfoSitioWeb->urlSitio, "www.ticktok.com") == 0 ||
        strcmp(pInfoSitioWeb->urlSitio, "www.x.com") == 0)
    {
        pInfoSitioWeb->tipoWeb = 2;
    }
    else if (strcmp(pInfoSitioWeb->urlSitio, "www.poderjudicial.com") == 0)
    {
        pInfoSitioWeb->tipoWeb = 1;
    }
    else if (strcmp(pInfoSitioWeb->urlSitio, "www.microsoft.com") == 0 ||
             strcmp(pInfoSitioWeb->urlSitio, "www.phytonesclave.com") == 0)
    {
        pInfoSitioWeb->tipoWeb = 0;
    }
}