#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Función para cifrar una cadena usando el código César
std::string cifrarCesar(const std::string& texto, int clave) {
    std::string resultado = texto;

    for (char& caracter : resultado) {
        if (isalpha(caracter)) {
            char base = isupper(caracter) ? 'A' : 'a';
            caracter = (caracter - base + clave) % 26 + base;
        }
    }

    return resultado;
}

int main() {
//----------------------------------------------------------------------------------------------
    // Abre el archivo en modo lectura
    std::ifstream archivoEntrada("CieloYTierra.txt");

    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Lee el contenido del archivo
    std::stringstream buffer;
    buffer << archivoEntrada.rdbuf();
    std::string contenido = buffer.str();
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
    // Elige la clave para el cifrado César
    int clave;
    std::cout << "Ingrese la clave para el cifrado César: ";
    std::cin >> clave;

    // Cifra el contenido del archivo
    std::string contenidoCifrado = cifrarCesar(contenido, clave);
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
    // Cierra el archivo de entrada
    archivoEntrada.close();

    // Abre el archivo de salida en modo escritura
    std::ofstream archivoSalida("ArchivoCifrado.txt");

    if (!archivoSalida) {
        std::cerr << "No se pudo abrir el archivo de salida." << std::endl;
        return 1;
    }

    // Escribe el contenido cifrado en el nuevo archivo
    archivoSalida << contenidoCifrado;

    // Cierra el archivo de salida
    archivoSalida.close();

    std::cout << "Nuevo archivo cifrado creado exitosamente." << std::endl;
//----------------------------------------------------------------------------------------------
    return 0;
}

