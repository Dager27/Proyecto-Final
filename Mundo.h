#ifndef MUNDO_H
#define MUNDO_H

#include <vector>
#include "Nodo.h"

class Mundo {
private:
    int ancho;
    int alto;
    std::vector<std::vector<Nodo>> nodos; // Matriz del mundo

public:
    Mundo(int ancho, int alto);

    void agregarCriatura(int x, int y, std::shared_ptr<Criatura> criatura);

    void actualizar();
    void limpiar();

    bool estaVacio(int x, int y) const;
    char simboloPrincipal(int x, int y) const;

    int getAncho() const;
    int getAlto() const;

    const std::vector<std::vector<Nodo>>& obtenerNodos() const;
};

#endif // MUNDO_H
