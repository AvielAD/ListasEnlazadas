#include "stdio.h"
#include "stdlib.h"
#include "listas.h"

int main(void){
    //Iniciar lista ligada con memoria dinamica
    TipoLista lista;
    lista = listaNueva();
    lista = insertarHead(lista, 3);
    lista = insertarHead(lista, 4);
    lista = insertarHead(lista, 5);
    lista = insertarHead(lista, 6);
    lista = insertarHead(lista, 7);
    lista = insertarCola(lista, 7);
    muestraLista(lista);

    printf("Tamaño de la lista: %d\n",longitudLista(lista));




    return 0;
}