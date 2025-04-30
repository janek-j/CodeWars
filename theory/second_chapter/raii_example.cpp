/*
 * RAII to technika, w ktorej zasoby sa alokowane podczas inicjalizacji obiektu, a zwalniane podczas jego zniszczenia.
 * Czyli zasob jest nabywany w konstruktorze, a zwalniany w destruktorze. RAII pozwala na dynamiczne zarzadzanie pamiecia.
 *
*/


#include <iostream>
#include <fstream>

class FileHandler {
private:
    std::ifstream file;
public:
    FileHandler(const std::string &filename);
    void read_file();
    ~FileHandler();
};

FileHandler::FileHandler(const std::string &filename) {
    file.open(filename);
    if (!file) {
        std::cerr << "Failed to open a file" << std::endl;
    }
}

void FileHandler::read_file() {
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
}

FileHandler::~FileHandler() {
    if (file.is_open()) {
        file.close();
    }
}

int main() {
    FileHandler f("raii_example.txt");
    f.read_file();
}