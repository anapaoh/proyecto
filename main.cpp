#include <iostream>
#include <vector>
#include "FuncionesDatos.h"
#include "BST.h"

int main() {
    std::string nombreArchivo = "LAC_gender_life_death_indices_20230703.csv"; /
    std::vector<Pais> paises = cargarDatos(nombreArchivo);

    if (paises.empty()) {
        std::cerr << "No se cargaron datos del archivo." << std::endl;
        return 1; 
    }

    BST arbol;

    for (const auto& pais : paises) {
        arbol.insertar(pais.le_f); 
    }

    double tasaABuscar = 5.0; 
    std::cout << "Buscar tasa de feminicidios " << tasaABuscar << ": " 
              << (arbol.buscar(tasaABuscar) ? "Encontrado" : "No encontrado") << std::endl;

    std::string paisABuscar = "Argentina"; // Cambia a un país de tu interés
    double mediaLeF = calcularMedia(paises, paisABuscar, "le_f");
    if (mediaLeF != -1) {
        std::cout << "La media de le_f para " << paisABuscar << " es: " << mediaLeF << std::endl;
    } else {
        std::cout << "No se encontraron datos para " << paisABuscar << std::endl;
    }

    return 0; 
}
