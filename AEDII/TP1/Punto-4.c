/* //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* //     ###    ######## ########  #### ####               ########  ##     ## ##    ## ######## ######## ########   #######   ######   // */
/* //    ## ##   ##       ##     ##  ##   ##                ##     ## ##     ## ###   ##    ##    ##       ##     ## ##     ## ##    ##  // */
/* //   ##   ##  ##       ##     ##  ##   ##                ##     ## ##     ## ####  ##    ##    ##       ##     ## ##     ## ##        // */
/* //  ##     ## ######   ##     ##  ##   ##     #######    ########  ##     ## ## ## ##    ##    ######   ########  ##     ##  ######   // */
/* //  ######### ##       ##     ##  ##   ##                ##        ##     ## ##  ####    ##    ##       ##   ##   ##     ##       ##  // */
/* //  ##     ## ##       ##     ##  ##   ##                ##        ##     ## ##   ###    ##    ##       ##    ##  ##     ## ##    ##  // */
/* //  ##     ## ######## ########  #### ####               ##         #######  ##    ##    ##    ######## ##     ##  #######   ######   // */
/* //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

/*
- NOM. PROGRAMA: Punto-3.c
- NOM. ALUMNO: Medina Juan Gabriel
- DESCRIPCION: No es un programa, es un analisis de un codigo.
- REVISION: [NINGUNA]
*/

#include <stdio.h>
#include <stdlib.h>

typedef float Real;
typedef Real* ApReal;

/*
    a) - ¿Qué tipo de dato es ApTemperatura? ¿Y qué tipo de dato contiene?
    R: es de tipo "Real" y contiene un dato de tipo Float.

    b) - ¿Qué contiene ApTemperatura justo después de declararse?
    R: Contiene solamente su propia direccion de memoria.
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
                R: Su propia direccion de memoria.
            II. ¿Qué valor contiene *ApTemperatura?
                R: Ahora ademas de su direccion de memoria contiene el dato de tipo float 5.5
            III. ¿Qué valor contiene temperatura? 
                R: Contiene unicamente el dato de tipo float 3.3
            IV. ¿punteroTemperatura apunta al mismo lugar que &temperatura?
                R: No porque ambos tienen direcciones de memoria diferentes.
*/

}