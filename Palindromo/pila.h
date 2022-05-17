#include "stdio.h"
#include "stdlib.h"

struct NodoPila {
    char letra;
    struct NodoPila * sig;
};

typedef struct NodoPila * TipoPila;

//Lista vacia nueva

TipoPila pilaNueva(void){
    return NULL;
}
//verificar lista vacia

int pilaVacia(TipoPila pila){
    return pila == NULL;
}
//Longitud de una lista
int longitudPila(TipoPila pila){
    struct NodoPila *aux;
    int contador=0;

    for(aux= pila; aux!=NULL; aux=aux->sig){
        contador++;
    }
    
    return contador;
}

//Impresion en pantalla de la lista

void muestraPila(TipoPila pila){
    struct NodoPila *aux;
    for(aux=pila; aux != NULL; aux= aux->sig){
        printf("%c ", aux->letra);
    }
    printf("\n");
}

//Adicion de Nodo (Cabeza)

TipoPila insertarPush(TipoPila pila, int valor){
    struct NodoPila *nuevo =  (struct NodoPila *)malloc(sizeof(struct NodoPila));

    nuevo->letra=valor;
    nuevo->sig=pila;
    pila=nuevo;
    return pila;
}

//Borrado de lista (Cabeza)

TipoPila borrarPop(TipoPila pila, char *pop){
    struct NodoPila * aux;
    if(pila!=NULL){
        *pop=pila->letra;
        aux=pila->sig;
        free(pila);
        pila=aux;
    }
    return pila;
}