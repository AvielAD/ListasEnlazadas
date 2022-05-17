#include "stdio.h"
#include "stdlib.h"

struct Nodo {
    int numEntero;
    struct Nodo * sig;
};

typedef struct Nodo * TipoLista;

//Lista vacia nueva
extern TipoLista listaNueva(void);

TipoLista listaNueva(void){
    return NULL;
}
//verificar lista vacia
extern int listaVacia(TipoLista lista);

int listaVacia(TipoLista lista){
    return lista == NULL;
}
//Longitud de una lista
extern int longitudLista(TipoLista lista);
int longitudLista(TipoLista lista){
    struct Nodo *aux;
    int contador=0;

    for(aux= lista; aux!=NULL; aux=aux->sig){
        contador++;
    }
    
    return contador;
}

//Impresion en pantalla de la lista
extern void muestraLista(TipoLista lista);

void muestraLista(TipoLista lista){
    struct Nodo *aux;
    for(aux=lista; aux != NULL; aux= aux->sig){
        printf("%d ", aux->numEntero);
    }
    printf("\n");
}

//Adicion de Nodo (Cabeza)
extern TipoLista insertarHead(TipoLista lista, int valor);

TipoLista insertarHead(TipoLista lista, int valor){
    struct Nodo * nuevo = malloc(sizeof(struct Nodo));

    nuevo->numEntero=valor;
    nuevo->sig=lista;
    lista=nuevo;
    return lista;
}
//Adicion de Nodo (Cola)
extern TipoLista insertarCola(TipoLista lista, int valor);

TipoLista insertarCola(TipoLista lista, int valor){
    struct Nodo *aux, *nuevo;
    if(lista==NULL){
        lista==NULL;
        lista=malloc(sizeof(struct Nodo));
        lista->numEntero =valor;
        lista->sig=NULL;
    }
    else{
        for(aux=lista; aux->sig!=NULL; aux=aux->sig);
        nuevo=malloc(sizeof( struct Nodo));
        nuevo->numEntero=valor;
        nuevo->sig=NULL;
        aux->sig=nuevo;
    }
    return lista;
}

//Borrado de lista (Cabeza)
extern TipoLista borrarListaHead(TipoLista lista);

TipoLista borrarListaHead(TipoLista lista){
    struct Nodo * aux;
    if(lista!=NULL){
        aux=lista->sig;
        free(lista);
        lista=aux;
    }
    return lista;
}
//Borrado de lista(Cola)
extern TipoLista borrarListaCola(TipoLista lista);

TipoLista borrarListaCola(TipoLista lista){
    struct Nodo *aux, *atras;

    if(lista != NULL){
        for(atras=NULL, aux=lista; aux->sig!=NULL; atras=aux, aux->sig);
        free(aux);
        if(atras==NULL){
            lista=NULL;
        }
        else{
            atras->sig=NULL;
        }
        return lista;
    }
}

//Busqueda de un elemento
extern int estaEnLista(TipoLista lista, int valor);

int estaEnLista(TipoLista lista, int valor){
    struct Nodo *aux;

    for(aux=lista; aux!=NULL; aux=aux->sig){
        if(aux->numEntero==valor){
            return 1;
        }
        return 0;
    }
}

//Borrado primer ocurrencia elemento

extern TipoLista borrarPrimerOcurrencia(TipoLista lista, int valor);

TipoLista borrarPrimerOcurrencia(TipoLista lista, int valor){
    struct Nodo * aux, *atras;
    for(atras=NULL, aux=lista; aux!=NULL; atras=aux, aux=aux->sig){
        if(atras==NULL){
            lista=aux->sig;
        }else{
            atras->sig=aux->sig;
            free(aux);
            return lista;
        }
    }
    return lista;
}

//Borrado Elemento recurrente en lista

extern TipoLista borrarValorRecurrente(TipoLista  lista, int valor);

TipoLista borrarValorRecurrente(TipoLista lista, int valor){
    struct Nodo * aux, *atras;

    atras=NULL;
    aux=lista;
    while(aux!=NULL){
        if(aux->numEntero==valor){
            if(atras==NULL){
                lista=aux->sig;
            }
            else{
                atras->sig=aux->sig;
            }
            
            free(aux);

            if(atras==NULL){
                aux=lista;
            }
            else{
                aux=atras->sig;
            }

        }
        else{
            atras=aux;
            aux=aux->sig;
        }
    }
    return lista;
}