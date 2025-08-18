#include <stdio.h>
#include <stdlib.h>

typedef int * tpEntero;
typedef char * tpCaracter;
tpEntero p1, p2;
tpCaracter q1, q2, q3;

int main()
{
    p2 = malloc(sizeof(int));
    *p2 = 2;
    *p2 = pow(*p2,2);
    p1 = malloc(sizeof(int));
    *p1 = fmod(*p2,3);
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);

    return 0;
}

/*COPILADO*/
/**p1 igual a 1, *p2 igual a 4*/