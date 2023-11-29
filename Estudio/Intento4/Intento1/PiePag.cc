#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
  
  std::ifstream Archivo("100Soledades.txt");

  std::stringstream buffer;
  buffer << Archivo.rdbuf();
  std::string contenido = buffer.str();

//---------------------------------------------------------------------------

 
  std::string salto1 = "Gabriel García Márquez";
  std::string salto2 = "Cien años de soledad";
  std::string hueco = "  ";
  size_t pos = contenido.find(salto1, salto2); 

  while (pos != std::string::npos) {
    contenido.replace(pos, salto1.length(), hueco);
    pos = contenido.find(salto1, pos + hueco.length());
  }

  pos = contenido.find(salto2);
  while (pos != std::string::npos) {
    contenido.replace(pos, salto2.length(), hueco);
    pos = contenido.find(salto2, pos + hueco.length());
  }
//--------------------------------------------------------------------------

  Archivo.close();
  
  std::ofstream Nuevo("NuevasSoledades.txt");

  Nuevo << contenido;
  Nuevo.close();
  
  return 0;
}
