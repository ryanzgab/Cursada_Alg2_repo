#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCAR 25

typedef char tString[MAXCAR];
/*Declaracion de lista*/ 
typedef struct
{
    int codPaquete, codPostal;
    tString destinatario, direccion;
    bool fragil;
}tpaquete;

typedef struct tnodoPaquete
{
    tpaquete* paquete;
    struct nodo* sig;
}tListaPaquete;

/*Parametro de Cola*/
typedef struct
{
   tnodoPaquete* principio;
   tnodoPaquete* final;
}tPaquetes;
