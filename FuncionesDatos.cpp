#include "FuncionesDatos.h"
#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <iostream>

std::vector<Pais> cargarDatos(const std::string& archivo) {
    std::vector<Pais> datos;
    std::ifstream file(archivo);
    std::string line;

    if (!file) {
        std::cerr << "Error al abrir el archivo: " << archivo << std::endl;
        return datos; 
    }

    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Pais pais;
        std::string campo;

        try {
            std::getline(iss, pais.iso3, ',');
            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("Año vacío");
            pais.year = std::stoi(campo);

            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("LEF vacío");
            pais.le_f = std::stod(campo);

            std::getline(iss, pais.country_sp, ',');
            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("Población femenina vacía");
            pais.fem_pop = std::stoi(campo);

            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("MMR vacío");
            pais.mmr = std::stod(campo);

            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("GPI vacío");
            pais.gpi = std::stod(campo);

            std::getline(iss, campo, ',');
            if (campo.empty()) throw std::invalid_argument("Feminicidios vacío");
            pais.feminicidios_number = std::stoi(campo);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error al convertir los datos en la línea: " << line << " - " << e.what() << std::endl;
            continue; 
        } catch (const std::out_of_range& e) {
            std::cerr << "Número fuera de rango en la línea: " << line << " - " << e.what() << std::endl;
            continue; 
        }

        datos.push_back(pais);
    }
    return datos;
}

std::vector<Pais> buscarPorPaisYAnio(const std::vector<Pais>& datos, const std::string& pais, int anio) {
    std::vector<Pais> resultados;
    for (const auto& d : datos) {
        if (d.country_sp == pais && d.year == anio) {
            resultados.push_back(d);
        }
    }
    return resultados;
}

double calcularMedia(const std::vector<Pais>& datos, const std::string& pais, const std::string& campo) {
    std::vector<double> valores;
    for (const auto& d : datos) {
        if (d.country_sp == pais) {
            if (campo == "le_f") valores.push_back(d.le_f);
            else if (campo == "mmr") valores.push_back(d.mmr);
            else if (campo == "gpi") valores.push_back(d.gpi);
            else if (campo == "feminicidios_number") valores.push_back(d.feminicidios_number);
        }
    }
    if (valores.empty()) return -1; 
    return std::accumulate(valores.begin(), valores.end(), 0.0) / valores.size();
}

std::vector<Pais> buscarPorRango(const std::vector<Pais>& datos, const std::string& pais, int anioInicial, int anioFinal) {
    std::vector<Pais> resultados;
    for (const auto& d : datos) {
        if (d.country_sp == pais && d.year >= anioInicial && d.year <= anioFinal) {
            resultados.push_back(d);
        }
    }
    return resultados;
}

bool compararPorCampo(const Pais& a, const Pais& b, const std::string& campo) {
    if (campo == "le_f") return a.le_f < b.le_f;
    if (campo == "mmr") return a.mmr < b.mmr;
    if (campo == "gpi") return a.gpi < b.gpi;
    return false; 
}

void quicksort(std::vector<Pais>& datos, const std::string& campo) {
    if (datos.size() <= 1) return;
    Pais pivot = datos[datos.size() / 2];
    std::vector<Pais> menores, iguales, mayores;

    for (const auto& d : datos) {
        if (compararPorCampo(d, pivot, campo)) menores.push_back(d);
        else if (d.le_f == pivot.le_f) iguales.push_back(d);
        else mayores.push_back(d);
    }
    quicksort(menores, campo);
    quicksort(mayores, campo);

    datos.clear();
    datos.insert(datos.end(), menores.begin(), menores.end());
    datos.insert(datos.end(), iguales.begin(), iguales.end());
    datos.insert(datos.end(), mayores.begin(), mayores.end());
}