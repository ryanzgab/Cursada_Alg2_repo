/*
7. Suponiendo que:
    typedef float acertijo;
    typedef acertijo * apAcertijo;
    apAcertijo a1, a2;

a).  a1 = 1.1; -R: No es posible
b). a1 = *1.1; -R: No es Posible
c). a1 = malloc(sizeof(float)); -R: Si es Posible
d). a1 = NULL; -R: Si es Posible
e). *a1 = 1.1; -R: Si es Posible
f). *a1 = malloc(sizeof(int)); -R: No es Posible
g). a2 = a1; -R: Es Posible
h). a2 = *1.1; -R: No es Posible
i). a2 = *a1; -R: Es Posible
*/