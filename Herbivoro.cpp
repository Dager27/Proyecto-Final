#include "Herbivoro.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Herbivoro::Herbivoro(int x, int y)
    : Criatura(x, y, "Herbívoro", 100) {}

void Herbivoro::actualizar() {
    // Movimiento aleatorio leve
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    mover(dx, dy);
    modificarEnergia(-3);
}

void Herbivoro::mostrar() const {
    cout << "🦓 Herbívoro en (" << obtenerX() << ", " << obtenerY()
         << ") con energía: " << energia
         << " -> " << (estaViva() ? "Vivo" : "Muerto") << endl;
}
