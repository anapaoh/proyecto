#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "registro.h"
#include "bst.h"
#include "buscarDatos.h"

// Función para cargar datos desde un archivo CSV y almacenar en un BST
void cargarDatos(const std::string& archivo, BST& bst) {    
    std::ifstream archivoCSV(archivo);  // Abrir el archivo CSV
    std::string linea;
    std::vector<Registro> registros;  // Vector para almacenar los registros leídos

    // Comprobar si el archivo se abre correctamente
    if (!archivoCSV) {
        std::cerr << "Error al abrir el archivo. Verifica la ruta y que el archivo exista en el directorio especificado.\n";
        return;
    }

    // Leer línea por línea del archivo CSV
    while (std::getline(archivoCSV, linea)) {
        std::stringstream ss(linea);  // Usar stringstream para separar los campos
        std::string dato;
        Registro registro;

        // Leer cada campo del registro
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

    archivoCSV.close();  // Cerrar el archivo CSV después de la lectura

    // Ordenar los registros usando merge sort (función implementada más abajo)
    mergeSort(registros, 0, registros.size() - 1);

    // Insertar los registros ordenados en el BST
    for (const auto& reg : registros) {
        bst.insertar(reg);
    }
}

// Función auxiliar para fusionar dos mitades del vector durante el ordenamiento
void merge(std::vector<Registro>& registros, int izquierda, int mitad, int derecha) {
    int n1 = mitad - izquierda + 1;
    int n2 = derecha - mitad;

    std::vector<Registro> L(n1);
    std::vector<Registro> R(n2);

    // Copiar los datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = registros[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = registros[mitad + 1 + j];

    int i = 0, j = 0, k = izquierda;
    
    // Fusionar los dos arreglos temporales en el vector original
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

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        registros[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        registros[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort para ordenar el vector de registros
void mergeSort(std::vector<Registro>& registros, int izquierda, int derecha) {
    // Condición base: Si hay más de un elemento
    if (izquierda < derecha) {
        int mitad = izquierda + (derecha - izquierda) / 2;  // Calcular la mitad del vector
        mergeSort(registros, izquierda, mitad);  // Ordenar la mitad izquierda
        mergeSort(registros, mitad + 1, derecha);  // Ordenar la mitad derecha
        merge(registros, izquierda, mitad, derecha);  // Fusionar ambas mitades ordenadas
    }
}
