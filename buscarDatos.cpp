#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "registro.h"
#include "bst.h"
#include "buscarDatos.h"

void cargarDatos(const std::string& archivo, BST& bst) {    
    std::ifstream archivoCSV(archivo);
    std::string linea;
    std::vector<Registro> registros;

    if (!archivoCSV) {
        std::cerr << "Error al abrir el archivo. Verifica la ruta y que el archivo exista en el directorio especificado.\n";
        return;
    }

    while (std::getline(archivoCSV, linea)) {
        std::stringstream ss(linea);
        std::string dato;
        Registro registro;

        std::getline(ss, dato, ',');
        registro.blanco = dato;

        std::getline(ss, registro.iso3, ',');
        std::getline(ss, registro.year, ',');
        std::getline(ss, registro.le_f, ',');
        std::getline(ss, registro.country_sp, ',');
        std::getline(ss, registro.fem_pop, ',');
        std::getline(ss, registro.mmr, ',');
        std::getline(ss, registro.gpi, ',');
        std::getline(ss, registro.femicides_number, ',');

        // Agregar el registro al vector
        registros.push_back(registro);
    }

    archivoCSV.close();

    // Ordenar los registros usando merge sort
    mergeSort(registros, 0, registros.size() - 1);

    // Insertar los registros ordenados en el BST
    for (const auto& reg : registros) {
        bst.insertar(reg);
    }
}

void merge(std::vector<Registro>& registros, int izquierda, int mitad, int derecha) {
    int n1 = mitad - izquierda + 1;
    int n2 = derecha - mitad;

    std::vector<Registro> L(n1);
    std::vector<Registro> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = registros[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = registros[mitad + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (L[i].year <= R[j].year) {
            registros[k] = L[i];
            i++;
        } else {
            registros[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        registros[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        registros[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Registro>& registros, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int mitad = izquierda + (derecha - izquierda) / 2;
        mergeSort(registros, izquierda, mitad);
        mergeSort(registros, mitad + 1, derecha);
        merge(registros, izquierda, mitad, derecha);
    }
}
