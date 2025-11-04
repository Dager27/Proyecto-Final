#ifndef NODO_H
#define NODO_H

#include <memory>
#include "Criature.h"

using namespace std;

class Nodo {
private:
    shared_ptr<Criatura> criatura;

public:
    Nodo() = default;

    void agregarCriatura(std::shared_ptr<Criatura> criatura) {
        this->criatura = criatura;
    }
    void limpiar() {
        criatura.reset();
    };
    bool estaVacio() const;
    char simboloPrincipal() const;

    //Método para obtener la criatura
    std::shared_ptr<Criatura> obtenerCriatura() { return criatura; }
};

#endif