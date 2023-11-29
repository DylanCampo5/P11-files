#include <iostream>
#include <string>

int main() {
  std::cout << "Frase a cifrar" << std::endl;
  std::string palabra;
  std::getline(std::cin, palabra);

  std::cout << "En que clave lo quieres (nº)" << std::endl;
  int clave;
  std::cin >> clave;

  for (int i = 0; i < palabra.length(); ++i) {
    char CESAR = palabra[i] + clave;
    int num1 = CESAR;
    if (palabra[i] == ' ') {
      CESAR = ' ';
    }
    if (palabra[i] == '.') {
      CESAR = '.';
    }
    if (palabra[i] == ',') {
      CESAR = ',';
    }

    if (96 < (num1 - clave) < 123) {
      if (num1 > 122) {     
        CESAR = (palabra[i] - 26 + clave);
      }
    }
    else if (64 < (num1 - clave) < 91) {
      if (num1 > 90) {
        CESAR = (palabra[i] - 26 + clave);
      }
    }
    std::cout << CESAR;
  }
  std::cout << std::endl;
  return 0;
}

