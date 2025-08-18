/*5. Después de ejecutarse el siguiente código:*/
#include <stdlib.h>
#include <stdio.h>


typedef int cosa;
typedef cosa *apuntadorACosa;
cosa c, cc; //sus valores SON 0 GUASAAAAAAAAAAAAAAAA
apuntadorACosa apuntC, apuntCC;

int main() 
{

    apuntC = NULL;
    apuntCC = malloc(sizeof(int));

    printf("a). %p\n", apuntC);
    printf("b). %p\n", apuntCC);
    printf("c). %d\n", c);
    printf("d). %d\n", cc);
    printf("e). %d\n", *apuntC); /*"Causa Fallos Al Copilar"*/
    printf("f). %d\n", *apuntCC); /*"Causa Fallos Al Copilar"*/
    return 0;
}
