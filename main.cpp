#include <iostream>
#include "bst.h"
#include "registro.h"

int main() {
    BST arbol;
    arbol.cargarDatos("LAC_gender_life_death_indices_20230703 (1) (2).csv");  // Carga los datos desde el archivo CSV al árbol binario de búsqueda (BST)

    int opcion;
    std::string pais, anio;

    // Bucle principal para el menú de opciones
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

        // Ejecuta la función correspondiente a la opción seleccionada
        if (opcion == 1) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.mostrarTodosLosDatos(pais);  // Muestra datos de todos los años del país dado
        } 
        else if (opcion == 2) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            std::cout << "Introduce el año: ";
            std::cin >> anio;
            arbol.mostrarDatosDeUnAnio(pais, anio);  // Muestra datos de un año específico del país dado
        } 
        else if (opcion == 3) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaLeF(pais);  // Calcula la media de esperanza de vida femenina para el país dado
        } 
        else if (opcion == 4) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaMmr(pais);  // Calcula la media de mortalidad materna para el país dado
        } 
        else if (opcion == 5) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaGpi(pais);  // Calcula la media del índice de paz global para el país dado
        } 
        else if (opcion == 6) {
            std::cout << "Introduce el nombre del país: ";
            std::cin >> pais;
            arbol.calcularMediaFemicidios(pais);  // Calcula la media de feminicidios para el país dado
        } 
        else if (opcion == 7) {
            break;  // Sale del bucle y termina el programa
        } 
        else {
            std::cout << "Opción no válida.\n";  // Mensaje de error para opciones no válidas
        }
    }

    return 0;
}
