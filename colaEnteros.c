#include "colaEnteros.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void nuevaCola(tipoCola* c){
    c->ini = NULL;
    c->fin = NULL;
}

bool esNulaCola(tipoCola c){
    return(c.ini == NULL && c.fin == NULL);
}

void encolar(tipoCola* c, tipoElementoCola e){
    celdaCola* nuevo;
    nuevo = (celdaCola*)malloc(sizeof(celdaCola));
    nuevo->elem = e;
    nuevo->sig = NULL;

    if(esNulaCola(*c)){
        c->ini = nuevo;
        c->fin = nuevo;
    }
    else{
        c->fin->sig = nuevo;
        c->fin = nuevo;
    }
}

void desencolar(tipoCola* c){
    if(esNulaCola(*c))
        printf("\nERROR. Intentando desencolar en una cola vacia.");
    else{
        celdaCola* aux;
        aux = c->ini;

        if(c->ini == c->fin){
            c->ini = NULL;
            c->fin = NULL;
        }
        else
            c->ini = c->ini->sig;

        free(aux);
    }
}

tipoElementoCola frente(tipoCola c){
    if(esNulaCola(c)){
        printf("\nERROR. Intentando obtener frente de cola vacia.");
        return -1;
    }
    else
        return(c.ini->elem);
}
