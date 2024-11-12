#include <iostream>
#include "bst.h"
#include "registro.h"

int main() {
    BST arbol;
    arbol.cargarDatos("datos.csv");

    int opcion;
    std::string pais, anio;

    while (true) {
        std::cout << "Selecciona una opción:\n";
        std::cout << "1. Mostrar todos los datos de todos los años de un país\n";
        std::cout << "2. Mostrar todos los datos de un país de un año en específico\n";
        std::cout << "3. Calcular la media de le_f de un país en específico\n";
        std::cout << "4. Calcular la media de mmr de un país en específico\n";
        std::cout << "5. Calcular la media de gpi de un país en específico\n";
        std::cout << "6. Calcular la media de feminicidios de un país en específico\n";
        std::cout << "7. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.mostrarTodosLosDatos(pais);
        } 
        else if (opcion == 2) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            std::cout << "Introduce el año: ";
            std::cin >> anio;
            arbol.mostrarDatosDeUnAnio(pais, anio);
        } 
        else if (opcion == 3) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaLeF(pais);
        } 
        else if (opcion == 4) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaMmr(pais);
        } 
        else if (opcion == 5) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaGpi(pais);
        } 
        else if (opcion == 6) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaFemicidios(pais);
        } 
        else if (opcion == 7) {
            break;
        } 
        else {
            std::cout << "Opción no válida.\n";
        }
    }

    return 0;
}
