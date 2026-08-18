/*
################################## 
#             AEDII              # 
# Trabajo Practico #1 - Punteros # 
################################## 

- #NOM. PROGRAMA: Punto-4.c
- #NOM. ALUMNO: Medina Juan Gabriel
- #DESCRIPCION: Analisis de programa y cuestionario
- #REVISION: [Ninguna]

*/

#include <stdio.h>
#include <stdlib.h>

typedef float Real;
typedef Real* ApReal;

/*
    a) - ¿Qué tipo de dato es ApTemperatura? ¿Y qué tipo de dato contiene?
    R: es de tipo "Real" y contiene dato de tipo puntero.

    b) - ¿Qué contiene ApTemperatura justo después de declararse?
    R: Nada porque no tiene ninguna variable de tipo real a la cual referenciar.
*/
int main()
{
    Real temperatura;
    ApReal ApTemperatura;

    ApTemperatura=(float*)malloc(sizeof(float));
    *ApTemperatura= 5.5;
    temperatura= 3.3;
    return 0;
    /*
    4) :
            I. ¿Qué valor contiene ApTemperatura? 
                R: Al usarse el malloc hace que reserve una direccion de memoria valida  para despues apuntar a esa
                direccion.
            II. ¿Qué valor contiene *ApTemperatura?
                R: Ahora contiene el dato de tipo float 5.5 de la direccion de memoria anteriormente reservada
            III. ¿Qué valor contiene temperatura? 
                R: Contiene unicamente el dato de tipo float 3.3
            IV. ¿ApTemperatura apunta al mismo lugar que &temperatura?
                R: No porque ambos tienen direcciones de memoria diferentes.
*/

}

/*EJEMPLO*/
/*
                 ApTemperatura
                 ┌───────────┐
                 │  0x1000   │
                 └─────┬─────┘
                       ↓
                 ┌───────────┐
                 │   -5.5    │
                 └───────────┘
                   memoria
                   dinámica


temperatura
┌───────────┐
│    3.3    │
└───────────┘
 memoria de la variable
 
 */