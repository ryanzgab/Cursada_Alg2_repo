#include <stdio.h>
#include <stdlib.h>
#include <bool.h>
#include <string.h>

#define MAXCARD 50

typedef char tString[MAXCARD];

typdef struct 
{
    float hora;
    tString urlSitio; 
}tSitio;

typedef struct nodo
{
    tSitio * Sitio;

}