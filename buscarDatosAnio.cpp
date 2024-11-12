#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "registro.h"  
#include "buscarDatosAnio.h"  


void buscarDatosAnio(const std::string& archivo, const std::string& pais, const std::string& anio) {
    std::ifstream archivoCSV(archivo);
    std::string linea;

    if (!archivoCSV) {
        std::cerr << "Error al abrir el archivo. Verifica la ruta y que el archivo exista en el directorio especificado.\n";
        return;
    }

    bool encontrado = false;
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

        // Comparar si el país y el año coinciden
        if (registro.country_sp == pais && registro.year == anio) {
            std::cout << "Abreviatura: " << registro.iso3
                      << ", Nombre: " << registro.country_sp
                      << ", Año: " << registro.year
                      << ", Esperanza de vida femenina: " << registro.le_f
                      << ", Población femenina: " << registro.fem_pop
                      << ", Mortalidad materna: " << registro.mmr
                      << ", Índice de paz global: " << registro.gpi
                      << ", Feminicidios: " << registro.femicides_number << "\n";
            encontrado = true;
            break;
        }
    }

    archivoCSV.close();

    if (!encontrado) {
        std::cout << "No se encontraron datos para el país: " << pais << " en el año: " << anio << "\n";
    }
}
