#include "flag.h"

Flags FLAG_crea () {
	Flags f;
	f.pri = (Nodo*)malloc(sizeof(Nodo));
	if (f.pri == NULL) {
		printf ("Error en crear la llista de les banderes.\n");
	}
	else {
		f.ant = f.pri;
		f.pri->sig = NULL;
	}
	return f;
}

void FLAG_inserir (Flags *f, Elemento e) {
	Nodo *aux;
	aux = (Nodo*)malloc(sizeof(Nodo));
	if (aux == NULL) {
		printf ("Error en crear una bandera.\n");
	}
	else {
		aux->e.fila = e.fila;
		aux->e.col = e.col;
		aux->sig = f->ant->sig;
		f->ant->sig = aux;
		f->ant = aux;
	}
}

void FLAG_borrar (Flags *f) {
    Nodo *aux;
    if (f->ant->sig != NULL) {
        aux = f->ant->sig;
        f->ant->sig = aux->sig;
        free (aux);
    }
}

Elemento FLAG_consultar (Flags f) {
    Elemento e;
    if (f->ant->sig == NULL) {
        e.col = -1;
        e.fila = -1;
    }
    else {
        e.col = f->ant->e.col;
        e.fila = f->ant->e.fila;
    }
    return e;
}

int FLAG_vacia (Flags f) {
    return f.pri->sig == NULL;
}

void FLAG_irInicio (Flags *f) {
    f->ant = f->pri;
}

void FLAG_avanzar (Flags *f) {
    if (f->ant->sig == NULL) {
        printf ("Error en anvanzar en la lista.\n");
    }
    else {
        f->ant = f->ant->sig;
    }
}

int FLAG_final (Flags f) {
    return f.ant->sig == NULL;
}

void FLAG_destruye (Flags *f) {
    FLAG_irInicio(f);
    while (!FLAG_vacia(*f)) {
        FLAG_borrar(f);
    }
    free (f->pri);
    f->pri = NULL;
    f->ant = NULL;
}