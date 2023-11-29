#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

bool contienePalabra(const std::string& frase, const std::string& palabra) {
    // Verifica si la palabra está presente en la frase
    return frase.find(palabra) != std::string::npos;
}

int main() {
//--------------------------------------------------------------------------------

    // Abre el archivo en modo lectura
    std::ifstream archivoEntrada("100Soledades.txt");

    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Abre el archivo de salida en modo escritura
    std::ofstream archivoSalida("frases_con_Úrsula.txt");

    if (!archivoSalida) {
        std::cerr << "No se pudo abrir el archivo de salida." << std::endl;
        return 1;
    }

//-------------------------------------------------------------------------------

    // Lee el contenido del archivo
    std::vector<std::string> frases;
    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        frases.push_back(linea);
    }

    // Palabra que deseas buscar
    std::string palabraABuscar = "Úrsula";

    // Encuentra y escribe las frases que contienen la palabra en el nuevo archivo
    for (const std::string& frase : frases) {
        if (contienePalabra(frase, palabraABuscar)) {
            archivoSalida << frase << '\n';
        }
    }

//--------------------------------------------------------------------------------

    // Cierra el archivo de entrada
    archivoEntrada.close();

    // Cierra el archivo de salida
    archivoSalida.close();

    std::cout << "Archivo de frases creado exitosamente." << std::endl;

//--------------------------------------------------------------------------------

    return 0;
}

