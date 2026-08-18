/*
################################## 
#             AEDII              # 
# Trabajo Practico #1 - Punteros # 
################################## 

- #NOM. PROGRAMA: Punto-5.c
- #NOM. ALUMNO: Juan Gabriel Medina
- #DESCRIPCION: Analisis de Codigo
- #REVISION: [Ninguna]

*/

#include <stdio.h>
#include <stdlib.h>

typedef int cosa;
typedef cosa* ApCosa;

int main()
{
    cosa c,cc;
    ApCosa apC, apCC;

    apC=NULL;
    apCC=(int*)malloc(sizeof(int));

    return 0;
}

/*

¿Qué contienen las siguientes variables?  
a) apC  R: Solo contiene NULL
b) apCC  R: Contiene la direccion de memoria de la memoria previamente reservada por el malloc
c) c   R: Aun no se le asignado ningun dato de tipo entero
d) cc  R: Aun no se le asignado ningun dato de tipo entero
e) *apC R: No se puede acceder porq no tiene ninguna referencia, esta en NULL.
f) *apCC R: Accede al dato de la direccion de memoria reservada en malloc.

*/