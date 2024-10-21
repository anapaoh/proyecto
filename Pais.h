#ifndef PAIS_H
#define PAIS_H

#include <string>

struct Pais {
    std::string iso3;
    int year;
    double le_f; // Esperanza de vida femenina
    std::string country_sp; // Nombre del país
    int fem_pop; // Población femenina
    double mmr; // Tasa de mortalidad materna
    double gpi; // Índice de paz global
    int feminicidios_number; // Número de feminicidios
};

#endif
