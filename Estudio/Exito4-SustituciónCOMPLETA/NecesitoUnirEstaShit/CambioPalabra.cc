#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
  
  std::ifstream Archivo("100Soledades.txt");

  std::stringstream buffer;
  buffer << Archivo.rdbuf();
  std::string contenido = buffer.str();

//-----------------------------------------------------------------

  std::string Word = "Úrsula";
  std::string NewWord = "María";
  size_t pos = contenido.find(Word);
  
  while (pos != std::string::npos) { 
    contenido.replace(pos, Word.length(), NewWord);
    pos = contenido.find(Word, pos + NewWord.length());
  }

//-----------------------------------------------------------------
  Archivo.close();

  std::ofstream Nuevo("NuevaSoledad.txt");
    
  Nuevo << contenido;
  Nuevo.close();
  
  std::cout << "Proceso hecho de puta madre, muy bien" << std::endl;

  return 0;
}
