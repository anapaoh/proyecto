#ifndef BST_H
#define BST_H

#include <string>
#include "registro.h"

class BST {
private:
    struct Nodo {
        Registro registro;
        Nodo* izquierda;
        Nodo* derecha;
        Nodo(const Registro& registro) : registro(registro), izquierda(nullptr), derecha(nullptr) {}
    };

    Nodo* raiz;

    void insertarRecursivo(Nodo*& nodo, const Registro& registro);
    void mostrarRecursivo(Nodo* nodo, const std::string& pais);
    Nodo* buscarRecursivo(Nodo* nodo, const std::string& pais, const std::string& anio);
    void calcularMediaRecursivo(Nodo* nodo, const std::string& pais, double& suma, int& count, std::string Registro::*campo);
    void guardarDatosRecursivo(Nodo* nodo, std::ofstream& archivoCSV);

public:
    BST();
    void insertar(const Registro& registro);
    void cargarDatos(const std::string& archivo);
    void mostrarTodosLosDatos(const std::string& pais);
    void mostrarDatosDeUnAnio(const std::string& pais, const std::string& anio);
    Nodo* buscar(const std::string& pais, const std::string& anio);
    void calcularMediaLeF(const std::string& pais);
    void calcularMediaMmr(const std::string& pais);
    void calcularMediaGpi(const std::string& pais);
    void calcularMediaFemicidios(const std::string& pais);
    void guardarDatos(const std::string& archivo);
};

#endif
