/*
6. Suponiendo que:
char * eso;

a). No porque la varible puntero es de tipo Char(Caracter).
b). Tampoco es posible por el hecho de que la variable "eso" no lleva "*" y se asigna espacio al tipo de dato que no es.
c). La forma correcta seria:

    char * eso;
    eso=(char*)malloc(sizeof(char));

Ya que se determina el espacio espesificado para su tipo de dato con el malloc y no lleva asterisco al principio.
*/