#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
//----------------------------------------------------------------------------
  std::ifstream Archivo("Quijote.txt");
 
  std::stringstream buffer;                                                                         
  buffer << Archivo.rdbuf();                                                                        
  std::string contenido = buffer.str(); 
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
  std::cout << "En que clave lo quieres (nº)" << std::endl;
  int clave;
  std::cin >> clave;

  for (char &c : contenido) {
    char CESAR = c + clave;
    int num1 = c;
    if (c == ' ') {
      CESAR = ' ';
    }
    if (c == '.') {
      CESAR = '.';
    }
    if (c == ',') {
      CESAR = ',';
    }
    if (c == '-') {
      CESAR = '-';
    }
    if (c == ':') {
      CESAR = ':';
    }
    if (c == 10) {
      CESAR = '_';
    }

    if (96 < (num1 - clave) < 123) {
      if (num1 > 122) {     
        CESAR = (c - 26 + clave);
      }
    }
    else if (64 < (num1 - clave) < 91) {
      if (num1 > 90) {
        CESAR = (c - 26 + clave);
      }
    }
    c = CESAR;
  }
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
  Archivo.close();

  std::ofstream Salida("NuevoQuijote.txt");
  Salida << contenido;

  Salida.close();
//----------------------------------------------------------------------------

  return 0;
}


