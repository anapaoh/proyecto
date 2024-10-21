#include "BST.h"

void BST::insertar(double tasa) {
    if (raiz == nullptr) {
        raiz = new Nodo(tasa);
    } else {
        insertarRecursivo(raiz, tasa);
    }
}

void BST::insertarRecursivo(Nodo* nodo, double tasa) {
    if (tasa < nodo->tasa) {
        if (nodo->izquierda == nullptr) {
            nodo->izquierda = new Nodo(tasa);
        } else {
            insertarRecursivo(nodo->izquierda, tasa);
        }
    } else {
        if (nodo->derecha == nullptr) {
            nodo->derecha = new Nodo(tasa);
        } else {
            insertarRecursivo(nodo->derecha, tasa);
        }
    }
}

bool BST::buscar(double tasa) {
    return buscarRecursivo(raiz, tasa) != nullptr;
}

Nodo* BST::buscarRecursivo(Nodo* nodo, double tasa) {
    if (nodo == nullptr || nodo->tasa == tasa) {
        return nodo; 
    }
    return tasa < nodo->tasa ? buscarRecursivo(nodo->izquierda, tasa) : buscarRecursivo(nodo->derecha, tasa);
}
