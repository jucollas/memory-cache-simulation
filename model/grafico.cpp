#include <iostream>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // Datos de ejemplo
    std::vector<int> datos = {1, 2, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7};

    // Crear histograma de frecuencia
    plt::hist(datos, 7); // El segundo parámetro es el número de contenedores

    // Etiquetas y título
    plt::xlabel("Valores");
    plt::ylabel("Frecuencia");
    plt::title("Histograma de Frecuencia");

    // Mostrar gráfico
    plt::show();

    return 0;
}
