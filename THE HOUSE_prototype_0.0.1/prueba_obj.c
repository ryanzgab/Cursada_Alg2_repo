#include <stdio.h>
#include "mundo.h"
#include "objetos.h"

int main(void)
{
    Objeto objetos[NUM_OBJ];
    inicializarObjetos(objetos);

    printf("En el cuarto de invitados:\n");
    mostrarObjetos(objetos, CUARTO_PRINCIPAL);

    printf("En el pasillo:\n");
    mostrarObjetos(objetos, CUARTO_SECUNDARIO);

    objetos[LAMPARA].ubicacion = EN_INVENTARIO;
    printf("Despues de tomarla, en el pasillo:\n");
    mostrarObjetos(objetos, CUARTO_SECUNDARIO);
    return 0;
}