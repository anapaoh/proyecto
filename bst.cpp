#include <iostream>
#include <fstream>
#include <sstream>
#include "bst.h"
#include "registro.h"

// Constructor: inicializa el árbol con una raíz nula.
BST::BST() : raiz(nullptr) {}

// Inserta un nuevo registro en el árbol.
void BST::insertar(const Registro& registro) {
    insertarRecursivo(raiz, registro);
}

// Inserción recursiva en el árbol binario de búsqueda.
// Complejidad:
// - Mejor caso: O(log n), si el árbol está balanceado.
// - Peor caso: O(n), si el árbol está completamente desbalanceado (se comporta como una lista enlazada).
// - Caso promedio: O(log n), asumiendo que el árbol permanece relativamente balanceado.
void BST::insertarRecursivo(Nodo*& nodo, const Registro& registro) {
    if (nodo == nullptr) {
        nodo = new Nodo(registro);  // Inserción en una hoja vacía.
    } else if (registro.year < nodo->registro.year || 
               (registro.year == nodo->registro.year && registro.country_sp < nodo->registro.country_sp)) {
        insertarRecursivo(nodo->derecha, registro);  // Inserta en el subárbol derecho.
    } else {
        insertarRecursivo(nodo->izquierda, registro);  // Inserta en el subárbol izquierdo.
    }
}

// Muestra todos los datos de un país.
void BST::mostrarTodosLosDatos(const std::string& pais) {
    mostrarRecursivo(raiz, pais);
}

// Muestra recursivamente los datos de un país. Complejidad:
// - Mejor caso: O(1), si el país se encuentra en la raíz.
// - Peor caso: O(n), si se recorren todos los nodos en un árbol completamente desbalanceado.
// - Caso promedio: O(log n), en un árbol balanceado, donde se buscan los datos en subárboles.
void BST::mostrarRecursivo(Nodo* nodo, const std::string& pais) {
    if (nodo != nullptr) {
        if (nodo->registro.country_sp == pais) {
            std::cout << "Abreviatura: " << nodo->registro.iso3
                      << ", Nombre: " << nodo->registro.country_sp
                      << ", Año: " << nodo->registro.year
                      << ", Esperanza de vida femenina: " << nodo->registro.le_f
                      << ", Población femenina: " << nodo->registro.fem_pop
                      << ", Mortalidad materna: " << nodo->registro.mmr
                      << ", Índice de paz global: " << nodo->registro.gpi
                      << ", Feminicidios: " << nodo->registro.femicides_number << "\n";
        }
        mostrarRecursivo(nodo->izquierda, pais);
        mostrarRecursivo(nodo->derecha, pais);
    }
}

// Muestra los datos de un país en un año específico.
void BST::mostrarDatosDeUnAnio(const std::string& pais, const std::string& anio) {
    Nodo* resultado = buscar(pais, anio);
    if (resultado != nullptr) {
        std::cout << "Abreviatura: " << resultado->registro.iso3
                  << ", Nombre: " << resultado->registro.country_sp
                  << ", Año: " << resultado->registro.year
                  << ", Esperanza de vida femenina: " << resultado->registro.le_f
                  << ", Población femenina: " << resultado->registro.fem_pop
                  << ", Mortalidad materna: " << resultado->registro.mmr
                  << ", Índice de paz global: " << resultado->registro.gpi
                  << ", Feminicidios: " << resultado->registro.femicides_number << "\n";
    } else {
        std::cout << "No se encontraron datos para el país: " << pais << " en el año: " << anio << "\n";
    }
}

// Busca un nodo específico según país y año.
// Complejidad:
// - Mejor caso: O(1), si el nodo buscado es la raíz.
// - Peor caso: O(n), si el árbol está desbalanceado.
// - Caso promedio: O(log n), en un árbol balanceado.
BST::Nodo* BST::buscar(const std::string& pais, const std::string& anio) {
    return buscarRecursivo(raiz, pais, anio);
}

// Función recursiva de búsqueda de un nodo.
// Misma complejidad que `buscar`.
BST::Nodo* BST::buscarRecursivo(Nodo* nodo, const std::string& pais, const std::string& anio) {
    if (nodo == nullptr) {
        return nullptr;
    }
    if (nodo->registro.country_sp == pais && nodo->registro.year == anio) {
        return nodo;
    }
    if (anio < nodo->registro.year || (anio == nodo->registro.year && pais < nodo->registro.country_sp)) {
        return buscarRecursivo(nodo->derecha, pais, anio);
    } else {
        return buscarRecursivo(nodo->izquierda, pais, anio);
    }
}

// Calcula la media de un campo específico de registros de un país.
void BST::calcularMediaLeF(const std::string& pais) {
    double suma = 0;
    int count = 0;
    calcularMediaRecursivo(raiz, pais, suma, count, &Registro::le_f);
    if (count > 0) {
        std::cout << "La media de la esperanza de vida femenina de " << pais << " es: " << suma / count << "\n";
    } else {
        std::cout << "No se encontraron datos para el país: " << pais << "\n";
    }
}

// Calcula la media de otro campo de un país.
void BST::calcularMediaMmr(const std::string& pais) {
    double suma = 0;
    int count = 0;
    calcularMediaRecursivo(raiz, pais, suma, count, &Registro::mmr);
    if (count > 0) {
        std::cout << "La media de la mortalidad materna de " << pais << " es: " << suma / count << "\n";
    } else {
        std::cout << "No se encontraron datos para el país: " << pais << "\n";
    }
}

// Función para calcular la media del índice de paz global de un país.
void BST::calcularMediaGpi(const std::string& pais) {
    double suma = 0;
    int count = 0;
    calcularMediaRecursivo(raiz, pais, suma, count, &Registro::gpi);
    if (count > 0) {
        std::cout << "La media del índice de paz global de " << pais << " es: " << suma / count << "\n";
    } else {
        std::cout << "No se encontraron datos para el país: " << pais << "\n";
    }
}

// Calcula la media de feminicidios de un país.
void BST::calcularMediaFemicidios(const std::string& pais) {
    double suma = 0;
    int count = 0;
    calcularMediaRecursivo(raiz, pais, suma, count, &Registro::femicides_number);
    if (count > 0) {
        std::cout << "La media de feminicidios de " << pais << " es: " << suma / count << "\n";
    } else {
        std::cout << "No se encontraron datos para el país: " << pais << "\n";
    }
}

// Recorrido recursivo para calcular la media de un campo específico.
// Complejidad:
// - Mejor caso: O(1), si el país está en la raíz.
// - Peor caso: O(n), si el árbol está desbalanceado.
// - Caso promedio: O(log n) en un árbol balanceado.
void BST::calcularMediaRecursivo(Nodo* nodo, const std::string& pais, double& suma, int& count, std::string Registro::*campo) {
    if (nodo != nullptr) {
        if (nodo->registro.country_sp == pais) {
            try {
                suma += std::stod(nodo->registro.*campo);
                count++;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Dato inválido para conversión a número: " << nodo->registro.*campo << "\n";
            }
        }
        calcularMediaRecursivo(nodo->izquierda, pais, suma, count, campo);
        calcularMediaRecursivo(nodo->derecha, pais, suma, count, campo);
    }
}

// Carga datos desde un archivo CSV al árbol.
// Complejidad: O(n log n), donde n es la cantidad de registros en el archivo, asumiendo que el árbol se mantiene balanceado.
void BST::cargarDatos(const std::string& archivo) {
    std::ifstream archivoCSV(archivo);
    std::string linea;

    if (!archivoCSV) {
        std::cerr << "Error al abrir el archivo. Verifica la ruta y que el archivo exista en el directorio especificado.\n";
        return;
    }

    while (std::getline(archivoCSV, linea)) {
        std::stringstream ss(linea);
        std::string dato;
        Registro registro;

        // Leer los datos de cada línea del CSV.
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

        // Insertar el registro en el árbol.
        insertar(registro);
    }

    archivoCSV.close();
}
