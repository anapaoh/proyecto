#ifndef BUSCARDATOS_H
#define BUSCARDATOS_H

#include <string>
#include <vector>
#include "registro.h"

void cargarDatos(const std::string& archivo, BST& bst);
void mergeSort(std::vector<Registro>& registros, int izquierda, int derecha);
void merge(std::vector<Registro>& registros, int izquierda, int mitad, int derecha);

#endif
