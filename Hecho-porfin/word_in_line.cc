#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
  std::string inputFileName = "gabriel_garcia_marquez_cien_annos_soledad.txt";
  std::string outputFileName = "Líneas-Arcadio.txt";
  std::string targetWord = "Arcadio";

  std::ifstream inputFile(inputFileName);

  if (!inputFile) {
     std::cerr << "No se pudo abrir el archivo de entrada: " << inputFileName << std::endl;
     return 1;
   }

   std::ofstream outputFile(outputFileName);

   if (!outputFile) {
      std::cerr << "No se pudo abrir el archivo de salida: " << outputFileName << std::endl;
      return 1;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
          lineNumber++;

	  int count = 0;

          std::istringstream iss(line);
	  std::string word;

	  while (iss >> word) {
	        if (word == targetWord) {
		   count++;
		}
	   }

	   if (count > 0) {
	      outputFile << "Línea " << lineNumber << ": " << count << " veces." << std::endl;
	    }
        }

	inputFile.close();
	outputFile.close();

	std::cout << "Proceso completado. Resultado en el archivo: " << outputFileName << std::endl;

	return 0;
}

