#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
  
  std::ifstream Archivo ("100Soledades.txt");
  
  std::stringstream buffer;
  buffer << Archivo.rdbuf();
  std::string contenido = buffer.str();

  const std::vector<char> vocales = {'a', 'e', 'i', 'o', 'u'};
	
  for (char &c : contenido) {
    if (c == vocales[0]) {
      c = vocales[1];
    }
    else if (c == vocales[1]) {
      c = vocales[2];
    }
    else if (c == vocales[2]) {
      c = vocales[3];
    }
    else if (c == vocales[3]) {
      c = vocales[4];
    }
    else if (c == vocales[4]) {
      c = vocales[0];
    }
  }
 
  Archivo.close();

  std::ofstream nuevo("NuevaSoledad.txt");
  nuevo << contenido;

  nuevo.close();

  return 0;
}
