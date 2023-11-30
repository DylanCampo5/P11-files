#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

bool esPalabraMayor(const std::string& palabra) {
    // Verifica si la palabra tiene más de 5 caracteres (incluyendo comas y puntos)
    return palabra.size() > 5;
}

bool esPalabraEntrePZ(const std::string& palabra) {
    // Verifica si la palabra comienza con una letra entre P y Z (mayúsculas o minúsculas)
    if (!palabra.empty()) {
        char primeraLetra = std::toupper(palabra[0]);
        return (primeraLetra >= 'P' && primeraLetra <= 'Z');
    }
    return false;
}

int main() {
    // Abre el archivo en modo lectura
    std::ifstream archivoEntrada("100Soledades.txt");

    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Vectores para almacenar palabras mayores de 5 caracteres y palabras entre P y Z
    std::vector<std::string> palabrasMayores;
    std::vector<std::string> palabrasPZ;

    std::string palabra;

    // Lee el contenido del archivo palabra por palabra
    while (archivoEntrada >> palabra) {
        if (esPalabraMayor(palabra)) {
            palabrasMayores.push_back(palabra);
        }

        if (esPalabraEntrePZ(palabra)) {
            palabrasPZ.push_back(palabra);
        }
    }

    // Cierra el archivo de entrada
    archivoEntrada.close();

    // Abre el archivo de salida para palabras mayores
    std::ofstream archivoSalidaMayores("palabras_mayores.txt");

    if (!archivoSalidaMayores) {
        std::cerr << "No se pudo abrir el archivo de salida para palabras mayores." << std::endl;
        return 1;
    }

    // Escribe las palabras mayores en el archivo de salida
    for (const auto& palabraMayor : palabrasMayores) {
        archivoSalidaMayores << palabraMayor << ' ';
    }

    // Cierra el archivo de salida para palabras mayores
    archivoSalidaMayores.close();

    std::cout << "Archivo de palabras mayores creado exitosamente." << std::endl;

    // Abre el archivo de salida para palabras entre P y Z
    std::ofstream archivoSalidaPZ("palabras_PZ.txt");

    if (!archivoSalidaPZ) {
        std::cerr << "No se pudo abrir el archivo de salida para palabras entre P y Z." << std::endl;
        return 1;
    }

    // Escribe las palabras entre P y Z en el archivo de salida
    for (const auto& palabraPZ : palabrasPZ) {
        archivoSalidaPZ << palabraPZ << ' ';
    }

    // Cierra el archivo de salida para palabras entre P y Z
    archivoSalidaPZ.close();

    std::cout << "Archivo de palabras entre P y Z creado exitosamente." << std::endl;

    return 0;
}

