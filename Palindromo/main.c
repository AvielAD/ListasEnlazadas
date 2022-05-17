#include "pila.h"
#include "cola.h"

int main(){

    TipoPila pila;
    TipoCola cola;
    pila = pilaNueva();
    cola = colaNueva();
    char palabra[100];

    scanf("%s", palabra);

    printf("cadena leida: %s\n", palabra);

    int i=0;
    //agregar caracteres a las estructuras pila y cola 
    while(palabra[i]!='\0'){

        pila= insertarPush(pila, palabra[i]);
        cola= insertarEncolar(cola, palabra[i]);

        i++;
    }
    //Comparar cada elemento removido de las estructuras
    //y determinar si cumple las condiciones para ser palindromo
    char pop;
    char desencolar;
    int palindromo=0;

    while(!colaVacia(cola) && !pilaVacia(pila)){
        pila=borrarPop(pila, &pop);
        cola=borrarDesencolar(cola,&desencolar);
        if(pop!=desencolar){
            palindromo=-1;
        }
    }
    if(palindromo==0){
        printf("la palabra: %s es un palindromo\n", palabra);
    }
    else{
        printf("la palabra: %s no es un palindromo\n", palabra);

    }

}