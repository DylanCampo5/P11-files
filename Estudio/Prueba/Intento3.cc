#include <iostream> 
#include <fstream>
#include <string>

int main() {
  //Pa leer el Intento3.txt pero todas sus líneas creo
  std::fstream input_file{"Intento3,2.txt", std::ios_base::in};
  
  //Variable que usaré y leerá
  int num1;
  double num2, num3;
  std::string palabra;
  std::string line, file_name;

  //Leerá la info
  while (input_file >> num1 >> num2 >> palabra >> num3) {
    std::cout << palabra << " =>   " << num1 << " + " << num2 << " = " << num3;
    std::cout << std::endl;
  }
 //Cierra todo
  input_file.close();
  return 0;
}
