#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H

#include <string>
#include <fstream>

class Mundo; // puedes dejarla si evitas incluir Mundo.h aquí

class Serializador {
public:
    static void guardar(const Mundo& mundo, const std::string& archivo);
    static void cargar(Mundo& mundo, const std::string& archivo);
};

#endif
