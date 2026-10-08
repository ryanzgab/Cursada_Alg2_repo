#include <stdio.h>
#include "mundo.h"

static const int  OPUESTA[NUM_DIR]     = {SUR, NORTE, OESTE, ESTE};
static const char LETRA_DIR[NUM_DIR]   = {'N', 'S', 'E', 'O'};
static const char* NOMBRE_DIR[NUM_DIR] = {"norte", "sur", "este", "oeste"};

#define CONECTAR(m, a, dir, b)       conectarDoble((m), (tArco){(a), (dir), (b), false})
#define CONECTAR_BLOQ(m, a, dir, b)  conectarDoble((m), (tArco){(a), (dir), (b), true})

/* ============================================================
   DEFINICION DEL MUNDO: aqui se editan habitaciones y conexiones
   ============================================================ */
bool inicializarHabitaciones(tMapa* pMapa)
{
    bool ok = true;
    int id;

    inicializarMapa(pMapa);

    /* Habitaciones: id, nombre, descripcion, luz propia */
    ok &= agregarHabitacion(pMapa, CUARTO_PRINCIPAL,  "Cuarto de invitados", "Estas en un cuarto maloliente", true);
    ok &= agregarHabitacion(pMapa, CUARTO_SECUNDARIO, "Pasillo", "Un largo pasillo se ve unas dos puertas abarrotadas", true);
    ok &= agregarHabitacion(pMapa, CUARTO_TERCIARIO,  "Cocina", "Una Cocina con un horrible olor a sobaco", true);
    ok &= agregarHabitacion(pMapa, SALA,              "Sala de estar", "Un sillon viejo y una alfombra raida ocupan la sala", true);
    ok &= agregarHabitacion(pMapa, SOTANO,            "Sotano", "Un sotano humedo que huele a tierra", false);
    ok &= agregarHabitacion(pMapa, PATIO,             "Patio", "Un patio con el pasto crecido y una pared de ladrillos", true);

    /* Conexiones: cada una registra la ida y la vuelta */
    ok &= CONECTAR(pMapa, CUARTO_PRINCIPAL, NORTE, CUARTO_SECUNDARIO);
    ok &= CONECTAR_BLOQ(pMapa, CUARTO_SECUNDARIO, ESTE, CUARTO_TERCIARIO);
    ok &= CONECTAR(pMapa, CUARTO_SECUNDARIO, OESTE, SALA);
    ok &= CONECTAR(pMapa, SALA, SUR, SOTANO);
    ok &= CONECTAR(pMapa, CUARTO_TERCIARIO, ESTE, PATIO);

    /* Control: todas las habitaciones del enum tienen que estar definidas */
    for (id = 0; id < NUM_HAB; id++)
    {
        if (!pMapa->vertices[id])
        {
            printf("Error: la habitacion %d esta en el enum pero no se definio\n", id);
            ok = false;
        }
    }
    return ok;
}

/* ============================================================
   OPERACIONES DEL GRAFO
   ============================================================ */
void inicializarMapa(tMapa* pMapa)
{
    int x, y;
    for (x = 0; x < NUM_HAB; x++)
    {
        pMapa->vertices[x] = false;
        pMapa->habitaciones[x] = (Habitacion){NULL, NULL, false, false};
        for (y = 0; y < NUM_HAB; y++)
        {
            pMapa->arcos[x][y] = SIN_ARCO;
            pMapa->bloqueos[x][y] = false;
        }
    }
}

bool existeHabitacion(const tMapa* pMapa, tVertice pVertice)
{
    return pVertice >= 0 && pVertice < NUM_HAB && pMapa->vertices[pVertice];
}

bool agregarHabitacion(tMapa* pMapa, tVertice pVertice, tString pNombre, tString pDescripcion, bool pLuz)
{
    if (pVertice < 0 || pVertice >= NUM_HAB)
    {
        printf("Valor no valido para la habitacion %d (entre 0 y %d)\n", pVertice, NUM_HAB - 1);
        return false;
    }
    if (pMapa->vertices[pVertice])
    {
        printf("La habitacion %d ya existe (%s)\n", pVertice, pMapa->habitaciones[pVertice].nombre);
        return false;
    }
    pMapa->vertices[pVertice] = true;
    pMapa->habitaciones[pVertice] = (Habitacion){pNombre, pDescripcion, false, pLuz};
    return true;
}

/* Valida un arco sin modificar nada. Imprime el motivo si no se puede agregar. */
static bool arcoValido(const tMapa* pMapa, tArco pArco)
{
    int j;
    if (!existeHabitacion(pMapa, pArco.origen))
    {
        printf("No se pudo agregar la salida, la habitacion de origen [%d] no existe\n", pArco.origen);
        return false;
    }
    if (!existeHabitacion(pMapa, pArco.destino))
    {
        printf("No se pudo agregar la salida, la habitacion de destino [%d] no existe\n", pArco.destino);
        return false;
    }
    if (pArco.direccion < 0 || pArco.direccion >= NUM_DIR)
    {
        printf("No se pudo agregar la salida, direccion invalida\n");
        return false;
    }
    if (pArco.origen == pArco.destino)
    {
        printf("No se pudo agregar la salida, no puede volver a la misma habitacion (%d)\n", pArco.origen);
        return false;
    }
    if (pMapa->arcos[pArco.origen][pArco.destino] != SIN_ARCO)
    {
        printf("No se pudo agregar la salida, ya hay una de %d a %d (la matriz admite una por par)\n",
               pArco.origen, pArco.destino);
        return false;
    }
    for (j = 0; j < NUM_HAB; j++)
    {
        if (pMapa->arcos[pArco.origen][j] == pArco.direccion)
        {
            printf("No se pudo agregar la salida, la habitacion %d ya tiene una al %s\n",
                   pArco.origen, NOMBRE_DIR[pArco.direccion]);
            return false;
        }
    }
    return true;
}

static void escribirArco(tMapa* pMapa, tArco pArco)
{
    pMapa->arcos[pArco.origen][pArco.destino] = pArco.direccion;
    pMapa->bloqueos[pArco.origen][pArco.destino] = pArco.bloqueada;
}

bool agregarArco(tMapa* pMapa, tArco pArco)
{
    if (!arcoValido(pMapa, pArco))
    {
        return false;
    }
    escribirArco(pMapa, pArco);
    return true;
}

bool conectarDoble(tMapa* pMapa, tArco pArco)
{
    tArco vuelta;

    if (pArco.direccion < 0 || pArco.direccion >= NUM_DIR)
    {
        printf("No se pudo agregar la salida, direccion invalida\n");
        return false;
    }
    vuelta.origen = pArco.destino;
    vuelta.direccion = OPUESTA[pArco.direccion];
    vuelta.destino = pArco.origen;
    vuelta.bloqueada = pArco.bloqueada;

    if (!arcoValido(pMapa, pArco) || !arcoValido(pMapa, vuelta))
    {
        return false;
    }
    escribirArco(pMapa, pArco);
    escribirArco(pMapa, vuelta);
    return true;
}

/* ============================================================
   CONSULTAS
   ============================================================ */
int destinoEn(const tMapa* pMapa, tVertice pOrigen, int pDireccion)
{
    int j;
    if (!existeHabitacion(pMapa, pOrigen))
    {
        return SIN_SALIDA;
    }
    for (j = 0; j < NUM_HAB; j++)
    {
        if (pMapa->arcos[pOrigen][j] == pDireccion)
        {
            return j;
        }
    }
    return SIN_SALIDA;
}

bool salidaBloqueada(const tMapa* pMapa, tVertice pOrigen, tVertice pDestino)
{
    return existeHabitacion(pMapa, pOrigen) && existeHabitacion(pMapa, pDestino)
        && pMapa->bloqueos[pOrigen][pDestino];
}

int calcularGradoSalida(const tMapa* pMapa, tVertice pVertice)
{
    int y, grado = 0;
    if (!existeHabitacion(pMapa, pVertice))
    {
        return -1;
    }
    for (y = 0; y < NUM_HAB; y++)
    {
        if (pMapa->arcos[pVertice][y] != SIN_ARCO)
        {
            grado++;
        }
    }
    return grado;
}

int calcularGradoEntrada(const tMapa* pMapa, tVertice pVertice)
{
    int x, grado = 0;
    if (!existeHabitacion(pMapa, pVertice))
    {
        return -1;
    }
    for (x = 0; x < NUM_HAB; x++)
    {
        if (pMapa->arcos[x][pVertice] != SIN_ARCO)
        {
            grado++;
        }
    }
    return grado;
}

/* ============================================================
   PRESENTACION
   ============================================================ */
void mostrarHabitacion(const Habitacion* pHab)
{
    printf("\n%s\n%s\n", pHab->nombre, pHab->descripcion);
}

void mostrarNombre(const Habitacion* pHab)
{
    printf("\n%s\n", pHab->nombre);
}

void visualizarMatriz(const tMapa* pMapa)
{
    int x, y;
    printf("\n MATRIZ DE ADYACENCIA (fila = origen, columna = destino, * = bloqueada)\n    ");
    for (y = 0; y < NUM_HAB; y++)
    {
        if (existeHabitacion(pMapa, y)) printf("%3d ", y);
    }
    printf("\n");
    for (x = 0; x < NUM_HAB; x++)
    {
        if (!existeHabitacion(pMapa, x)) continue;
        printf("%2d  ", x);
        for (y = 0; y < NUM_HAB; y++)
        {
            if (!existeHabitacion(pMapa, y)) continue;
            if (pMapa->arcos[x][y] == SIN_ARCO)
                printf("  . ");
            else
                printf(" %c%c ", LETRA_DIR[pMapa->arcos[x][y]], pMapa->bloqueos[x][y] ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
    for (x = 0; x < NUM_HAB; x++)
    {
        if (existeHabitacion(pMapa, x)) printf(" %d = %s\n", x, pMapa->habitaciones[x].nombre);
    }
}
