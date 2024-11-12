#include <iostream>
#include <fstream>
#include <sstream>
#include "bst.h"
#include "registro.h"

BST::BST() : raiz(nullptr) {}

void BST::insertar(const Registro& registro) {
    insertarRecursivo(raiz, registro);
}

void BST::insertarRecursivo(Nodo*& nodo, const Registro& registro) {
    if (nodo == nullptr) {
        nodo = new Nodo(registro);
    } else if (registro.year < nodo->registro.year || (registro.year == nodo->registro.year && registro.country_sp < nodo->registro.country_sp)) {
        insertarRecursivo(nodo->derecha, registro);
    } else {
        insertarRecursivo(nodo->izquierda, registro);
    }
}

void BST::mostrarTodosLosDatos(const std::string& pais) {
    mostrarRecursivo(raiz, pais);
}

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

BST::Nodo* BST::buscar(const std::string& pais, const std::string& anio) {
    return buscarRecursivo(raiz, pais, anio);
}

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

        // Leer los datos de cada línea del CSV
        std::getline(ss, dato, ',');  // Ignorar primer campo (número de fila)
        registro.blanco = dato;
        std::getline(ss, registro.iso3, ',');
        std::getline(ss, registro.year, ',');
        std::getline(ss, registro.le_f, ',');
        std::getline(ss, registro.country_sp, ',');
        std::getline(ss, registro.fem_pop, ',');
        std::getline(ss, registro.mmr, ',');
        std::getline(ss, registro.gpi, ',');
        std::getline(ss, registro.femicides_number, ',');

        // Insertar el registro en el árbol
        insertar(registro);
    }

    archivoCSV.close();
}
