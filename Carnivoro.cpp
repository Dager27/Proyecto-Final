#include "Carnivoro.h"
#include <iostream>

Carnivoro::Carnivoro(int x, int y, int energia)
    : Criatura(x, y, "Carnivoro", energia) {}

void Carnivoro::actualizar() {
    mover(1, 1);              // Se mueve en diagonal
    modificarEnergia(-8);     // Consume energía
}

void Carnivoro::mostrar() const {
    std::cout << "Carnívoro en (" << obtenerX() << ", " << obtenerY()
              << ") con energía: " << energia << std::endl;
}
