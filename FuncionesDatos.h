#ifndef FUNCIONESDATOS_H
#define FUNCIONESDATOS_H

#include <vector>
#include <string> // Asegúrate de incluir <string>
#include "Pais.h"

std::vector<Pais> cargarDatos(const std::string& archivo);
std::vector<Pais> buscarPorPaisYAnio(const std::vector<Pais>& datos, const std::string& pais, int anio);
double calcularMedia(const std::vector<Pais>& datos, const std::string& pais, const std::string& campo);
std::vector<Pais> buscarPorRango(const std::vector<Pais>& datos, const std::string& pais, int anioInicial, int anioFinal);
void quicksort(std::vector<Pais>& datos, const std::string& campo);

#endif
