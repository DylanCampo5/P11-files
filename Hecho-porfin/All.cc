#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

bool contienePalabra(const std::string& frase, const std::string& palabra) {
    // Verifica si la palabra está presente en la frase
    return frase.find(palabra) != std::string::npos;
}

int main() {
  
  std::ifstream Archivo("100Soledades.txt");

//-----------------------------------------------------------------

    // Lee el contenido del archivo
    std::vector<std::string> frases;
    std::string linea;
    while (std::getline(Archivo, linea)) {
        frases.push_back(linea);
    }

    // Palabra que deseas buscar
    std::string palabraABuscar = "Úrsula";
    
    Archivo.close();
    std::ofstream Nuevo("NuevaSoledad.txt");

    // Encuentra y escribe las frases que contienen la palabra en el nuevo archivo
    for (const std::string& frase : frases) {
        if (contienePalabra(frase, palabraABuscar)) {
            Nuevo << frase << '\n';
        }
    }
 
//----------------------------------------------------------------

    // Cierra el archivo de salida
    Nuevo.close();

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    std::cout << "Archivo de frases creado exitosamente." << std::endl;

//----------------------------------------------------------------

  std::ifstream Archivo2("NuevaSoledad.txt");
  
  std::stringstream buffer2;
  buffer2 << Archivo2.rdbuf();
  std::string contenido2 = buffer2.str();

//----------------------------------------------------------------

  std::string Word = "Úrsula";
  std::string NewWord = "María";
  size_t pos = contenido2.find(Word);
  
  while (pos != std::string::npos) { 
    contenido2.replace(pos, Word.length(), NewWord);
    pos = contenido2.find(Word, pos + NewWord.length());
  }

//-----------------------------------------------------------------
  
  Archivo2.close();
  
  std::ofstream Nuevo2("NuevaSoledad.txt");
  Nuevo2 << contenido2;

  Nuevo2.close();

  std::cout << "Proceso hecho de puta madre, muy bien" << std::endl;

  return 0;
}

