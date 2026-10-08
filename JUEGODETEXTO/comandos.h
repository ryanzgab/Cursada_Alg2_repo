#include <stdio.h>

enum Direcciones {NORTE, SUR, ESTE, OESTE, NUM_DIR}; /*0-NORTE, 1-SUR, 2-ESTE, 3-OESTE*/

int leerDireccion(const char*); /*lee las id de direccion con el texto*/

int leerDireccion(const char* texto)
{
    if (strcmp(texto, "norte") == 0 || strcmp(texto, "n") == 0) return NORTE;
    if (strcmp(texto, "sur")   == 0 || strcmp(texto, "s") == 0) return SUR;
    if (strcmp(texto, "este")  == 0 || strcmp(texto, "e") == 0) return ESTE;
    if (strcmp(texto, "oeste") == 0 || strcmp(texto, "o") == 0) return OESTE;
    return -1;
}
