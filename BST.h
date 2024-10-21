#ifndef BST_H
#define BST_H

#include "Pais.h"

struct Nodo {
    double tasa;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(double t) : tasa(t), izquierda(nullptr), derecha(nullptr) {}
};

class BST {
public:
    Nodo* raiz;

    BST() : raiz(nullptr) {}
    void insertar(double tasa);
    bool buscar(double tasa);

private:
    void insertarRecursivo(Nodo* nodo, double tasa);
    Nodo* buscarRecursivo(Nodo* nodo, double tasa);
};

#endif
