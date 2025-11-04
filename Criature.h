#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <iostream>

class Criatura {
protected:
    int x;
    int y;
    int energia;
    std::string tipo;

public:
    Criatura(int x, int y, const std::string& tipo, int energia);

    virtual void actualizar() = 0;
    virtual void mostrar() const = 0;

    // Métodos comunes
    void mover(int dx, int dy);
    void modificarEnergia(int cantidad);
    int obtenerX() const;
    int obtenerY() const;
    std::string obtenerTipo() const;
    char simbolo() const;
    bool estaViva() const;

};

#endif
