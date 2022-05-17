#include "stdio.h"
#include "stdlib.h"

struct NodoCola {
    char letra;
    struct NodoCola * sig;
};

typedef struct NodoCola * TipoCola;

//Lista vacia nueva

TipoCola colaNueva(void){
    return NULL;
}
//verificar lista vacia

int colaVacia(TipoCola cola){
    return cola == NULL;
}
//Longitud de una lista
int longitudCola(TipoCola cola){
    struct NodoCola *aux;
    int contador=0;

    for(aux= cola; aux!=NULL; aux=aux->sig){
        contador++;
    }
    
    return contador;
}

//Impresion en pantalla de la lista

void muestraCola(TipoCola cola){
    struct NodoCola *aux;
    for(aux=cola; aux != NULL; aux= aux->sig){
        printf("%c ", aux->letra);
    }
    printf("\n");
}

//Adicion de Nodo (Cabeza)

TipoCola insertarEncolar(TipoCola cola, char valor){
    struct NodoCola *nuevo =  (struct NodoCola *)malloc(sizeof(struct NodoCola));

    nuevo->letra=valor;
    nuevo->sig=cola;
    cola=nuevo;
    return cola;
}

//Borrado de lista(Cola)

TipoCola borrarDesencolar(TipoCola cola, char *desencolar){
    struct NodoCola *aux, *atras;
    if(cola != NULL){
        for(atras=NULL, aux=cola; aux->sig!=NULL; atras=aux, aux=aux->sig);
        *desencolar=aux->letra;
        free(aux);
        if(atras==NULL){
            cola=NULL;
        }
        else{
            atras->sig=NULL;
        }
    }
    return cola;
}
