#include <iostream>
#include <string>

int main() {
  std::string palabra;
  std::cin >> palabra;

  for (int i = 0; i < palabra.length(); ++i) {
    char CESAR = palabra[i] + 5;
    std::cout << CESAR;
  }
 
  std::cout << std::endl;
  return 0;
}
