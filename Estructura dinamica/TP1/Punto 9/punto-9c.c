#include <stdio.h>
#include <stdlib.h>

typedef int * tpEntero;
typedef char * tpCaracter;
tpEntero p1, p2;
tpCaracter q1, q2, q3;

int main()
{
    q1 = malloc(sizeof(char));
    q2 = malloc(sizeof(char));
    q3 = malloc(sizeof(char));
    *q1 = 'Y';
    *q2 = (*q1) - 1;
    *q3 = (*q1) + 1;
    printf("*q1 igual a %c, *q2 igual a %c, q3 igual a %c\n", *q1, *q2,*q3);
    return 0;
}

/*COPILADO*/
/**q1 igual a Y, *q2 igual a X, q3 igual a Z*/