/*
1. Una aplicación de redes sociales que permite a los usuarios compartir contenido multimedia y conectarse 
con amigos maneja el registro de sus usuarios y sus preferencias. Para el registro de los datos de cada 
usuario, se utiliza una lista enlazada en la que se almacenan los siguientes datos: nombre de usuario, 
correo electrónico, número de seguidores, tipo de contenido favorito (1-Fotos, 2-Videos, 3-Textos, 4
Stories), y cantidad de publicaciones realizadas (un usuario puede realizar múltiples publicaciones). Se pide 
crear un programa que manipule una lista enlazada e incluya: 
     (0,50 puntos) Codificar en lenguaje C las estructuras de datos necesarias para la declaración del tipo 
    tListaUsuarios adecuado. 
     (1,50 puntos) Una función para eliminar usuarios de la lista, permitiendo que se quiten de cualquier 
    posición. 
     (1,50 puntos) Una función para mostrar cuántos usuarios prefieren un determinado tipo de contenido 
    según la selección del usuario (el tipo de contenido se debe recibir como parámetro). Tener en cuenta 
    el formato del ejemplo a continuación, que para el caso de Fotos sería.
     (1,50 puntos): Una función para listar los correos electrónicos de los usuarios que tienen más de 
    100.000 seguidores. Si no hay ningún usuario con más de esta cantidad de seguidores, emitir un 
    mensaje que indique: “No existen usuarios que superen los 100.000 seguidores”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef char tString[MAX];
tString tipoContenido[]={"Fotos","Videos","Textos","Stories"};

typedef struct 
{
    tString nombre, correoE;
    int cantSeguidores, cantPublicaciones, tipoCont;
}tUsuario;

typedef struct nodo
{
    tUsuario usuario;
    struct nodo* siguiente;
}tListaUsuarios;

void inicializarLista(tListaUsuarios**);
bool listaVacia(tListaUsuarios*);

void insertarUsuario(tListaUsuarios**, tUsuario);

int ingresarPosicion();
void eliminarUsuarioEnPos(tListaUsuarios**);

float calcularPorcentaje(int, int, int);

void listarUsuarios(tListaUsuarios*, int);

int main(){
  tListaUsuarios* usuarios;
  inicializarLista(&usuarios);
 return 0;   
}

void inicializarLista(tListaUsuarios** pListaUsuarios){
   *pListaUsuarios = NULL;
}

bool listaVacia(tListaUsuarios* pListaUsuarios){
   return(pListaUsuarios == NULL);
}

void insertarUsuario(tListaUsuarios** pListaUsuarios, tUsuario pUsuario){
     tListaUsuarios* nuevoUsuario;
     nuevoUsuario = (tListaUsuarios*) malloc (sizeof(tListaUsuarios));
     nuevoUsuario->usuario = pUsuario;
     nuevoUsuario->siguiente = NULL;
     *pListaUsuarios = nuevoUsuario;
}

int ingresarPosicion(){
    int posicion;
    printf("\nIngrese una posici%cn mayor que cero: ", 162);
    scanf("&d", &posicion);

    if(posicion<=0){
        printf("\n---------- POSICI%cN INV%cLIDA ----------\n", 224, 181);
        ingresarPosicion();
    }else{
        return posicion;
    }
}

void eliminarUsuarioEnPos(tListaUsuarios** pListaUsuarios){
      if(listaVacia(*pListaUsuarios)){
        printf("\n-----------------------------------------------------");
		printf("\n------ Lista vac%ca, no hay juegos por eliminar ------", 161);
		printf("\n-----------------------------------------------------\n");
      }else{
        int posicion = ingresarPosicion();
        tListaUsuarios* aux = *pListaUsuarios; 
        int i;
        for(i=1; i<posicion-1; i++){
           aux = aux->siguiente;
        }
        tListaUsuarios* usuarioSuprimir = usuarioSuprimir->siguiente;
        aux->siguiente = usuarioSuprimir->siguiente;
        
       free(usuarioSuprimir);
       usuarioSuprimir = NULL;
      }
}

float calcularPorcentaje(int pContadorTipo, int pTotal, int pTipo){
    float porcentaje = 0;

    if(pTotal>0){
        porcentaje = (pContadorTipo * 100.0) / pTotal;
       printf("Porcentaje de usuarios %s prefieren un determinado tipo de contenido según la selección del usuario %.2f%%", tipoContenido[pTipo], porcentaje);
    }else{
       printf("No hay usuarios para calcular");
    }
    return porcentaje;
}

void listarUsuarios(tListaUsuarios* pListaUsuarios, int cantSeguidores){
       if(!listaVacia(pListaUsuarios)){
          if(cantSeguidores > 100000){
               tListaUsuarios* aux = pListaUsuarios;
               bool encontrado = false;

           printf("\n------------------------------------------------------------------------------------------");
           printf("\n  Lista los correos electrónicos de los usuarios que tienen más de 100.000 seguidores: %d", cantSeguidores);
           printf("\n------------------------------------------------------------------------------------------\n");
          
           while(aux!=NULL){
              if(aux->usuario, cantSeguidores){
                printf("\n-----------------------------------------------------\n");
                encontrado = true;
                printf("%s", aux->usuario.correoE);
              }
              aux= aux->siguiente;
           }
            
          }else{
            printf("No existen usuarios que superen los 100.000 seguidores");
          }
       }
}