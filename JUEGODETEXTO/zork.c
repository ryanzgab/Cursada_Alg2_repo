#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mundo.h"
#include "objetos.h"

/*El uso de constantes como parametros es para establecer solo lectura*/
void buclePrincipal(Habitacion*, Objeto*);
void describirLugar(Habitacion*, const Objeto*, int);
int leerDireccion(const char*); /*No se puede utilizar el tString para modificar la linea de comando*/
bool hayLuz(const Habitacion*, const Objeto*, int);

Habitacion CASA[NUM_HAB];
Objeto OBJETOS[NUM_OBJ];

int main()
{
    inicializarHabitaciones(CASA);
    inicializarObjetos(OBJETOS);
    buclePrincipal(CASA, OBJETOS);
    return 0;
}

void inicializarHabitaciones(Habitacion* pCASA)
{
    pCASA[CUARTO_INVITADOS] = (Habitacion){
        .nombre = "Cuarto de invitados",
        .descripcion = "Estas en un cuarto maloliente",
        .salidas = {SALIDA(CUARTO_PASILLO), NO_SALIDA, NO_SALIDA, NO_SALIDA},
        .luz = true
    };
    pCASA[CUARTO_PASILLO] = (Habitacion){
        .nombre = "Pasillo",
        .descripcion = "Un largo pasillo se ve unas dos puertas abarrotadas",
        .salidas = {SALIDA(CUARTO_BANO), SALIDA(CUARTO_INVITADOS), BLOQUEADA(CUARTO_ABARROTADO), SALIDA(CUARTO_COCINA)},
        .luz = true
    };
    pCASA[CUARTO_COCINA] = (Habitacion){
        .nombre = "Cocina",
        .descripcion = "Una Cocina con un horrible olor a sobaco",
        .salidas = {NO_SALIDA, SALIDA(CUARTO_LIVING), SALIDA(CUARTO_PASILLO), NO_SALIDA},
        .luz = true
    };
    pCASA[CUARTO_LIVING] = (Habitacion){
        .nombre = "Living",
        .descripcion = "Un living con un sillo lleno de forros usados",
        .salidas = {SALIDA(CUARTO_LIVING), NO_SALIDA, NO_SALIDA, NO_SALIDA},
        .luz = false
    };
    pCASA[CUARTO_BANO] = (Habitacion){
        .nombre = "Ba\xA4o",
        .descripcion = "Si creiste que podia oler peor, preparate para el olor a culo que se siente aca",
        .salidas = {NO_SALIDA, SALIDA(CUARTO_PASILLO), NO_SALIDA, NO_SALIDA},
        .luz = true
    };

}
void mostrarNombre(const Habitacion* pHab)
{
    printf("\n%s\n", pHab->nombre);
}

void mostrarHabitacion(const Habitacion* pHab)
{
    printf("\n%s\n%s\n", pHab->nombre, pHab->descripcion);
}

void inicializarObjetos(Objeto* pOBJ)
{
    pOBJ[LAMPARA] = (Objeto){
        "lampara",
        "una lampara de aceite",
        CUARTO_COCINA
    };
}

void mostrarObjetos(const Objeto* pOBJ, int idHab)
{
    int i;
    for (i = 0; i < NUM_OBJ; i++)
    {
        if (pOBJ[i].ubicacion == idHab)
        {
            printf("Aqui hay %s.\n", pOBJ[i].descripcion);
        }
    }
}

bool hayLuz(const Habitacion* pCASA, const Objeto* pOBJ, int id)
{
    if (pCASA[id].luz)
    {
        return true;
    }
    return pOBJ[LAMPARA].ubicacion == EN_INVENTARIO
        || pOBJ[LAMPARA].ubicacion == id;
}

void describirLugar(Habitacion* pCASA, const Objeto* pOBJ, int id)
{
    Habitacion* pHab = &pCASA[id];

    if (!hayLuz(pCASA, pOBJ, id))
    {
        printf("\nEsta muy oscuro. No ves nada.\n");
        return;
    }

    if (pHab->visitada)
    {
        mostrarNombre(pHab);
    }
    else
    {
        mostrarHabitacion(pHab);
    }

    mostrarObjetos(pOBJ, id);
    pHab->visitada = true;
}

int leerDireccion(const char* texto)
{
    if (strcmp(texto, "norte") == 0 || strcmp(texto, "n") == 0) return NORTE;
    if (strcmp(texto, "sur")   == 0 || strcmp(texto, "s") == 0) return SUR;
    if (strcmp(texto, "este")  == 0 || strcmp(texto, "e") == 0) return ESTE;
    if (strcmp(texto, "oeste") == 0 || strcmp(texto, "o") == 0) return OESTE;
    return -1;
}

void buclePrincipal(Habitacion* pCASA, Objeto* pOBJ)
{
    int actual = CUARTO_INVITADOS;
    char linea[MAX_CAR];
 
    describirLugar(pCASA, pOBJ, actual);
 
    while (1)
    {
        printf("\n> ");
        if (fgets(linea, sizeof linea, stdin) == NULL) break;
        linea[strcspn(linea, "\n")] = '\0';
 
        if (strcmp(linea, "salir") == 0) break;
 
        int dir = leerDireccion(linea);
        if (dir < 0)
        {
            printf("No entiendo eso.\n");
            continue;
        }
 
        Salida s = pCASA[actual].salidas[dir];
        if (s.destino == SIN_SALIDA)
        {
            printf("No puedes ir por ahi.\n");
        }
        else if (s.bloqueada)
        {
            printf("La salida esta bloqueada.\n");
        }
        else
        {
            actual = s.destino;
            describirLugar(pCASA, pOBJ, actual);
        }
    }
}