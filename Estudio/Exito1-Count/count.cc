#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

int main() {

//Abre el archivo que quiero en modo lectura  
  std::ifstream archivoEntrada("hola.txt");

  std::stringstream buffer;
  buffer << archivoEntrada.rdbuf();
  std::string contenido = buffer.str();

//Por si me equivoco en alguna wea, esto me avisa (creo)
  if (! archivoEntrada) {
    std::cerr << "No se pudo abrir el archivo" << std::endl;
    return 1;
  }
  
//---------------------------------------------------
//Esta parte son las modificaciones que queramos hacer
  std::string palabra = "the";
  int suma{0};
  
  size_t pos = contenido.find(palabra);
  while (pos != std::string::npos) {
    suma++;
    pos = contenido.find(palabra, pos + palabra.length());
  }
  std::cout << suma << std::endl;
//---------------------------------------------------

  return 0;
}
