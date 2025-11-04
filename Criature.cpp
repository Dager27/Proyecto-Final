#include "Criature.h"

Criatura::Criatura(int x, int y, const std::string& tipo, int energia)
    : x(x), y(y), tipo(tipo), energia(energia) {}

void Criatura::mover(int dx, int dy) {
    x += dx;
    y += dy;
}

void Criatura::modificarEnergia(int cantidad) {
    energia += cantidad;
    if (energia < 0) energia = 0;
}

int Criatura::obtenerX() const {
    return x;
}

int Criatura::obtenerY() const {
    return y;
}
bool Criatura::estaViva() const {
    return energia > 0;
}


std::string Criatura::obtenerTipo() const {
    return tipo;
}
char Criatura::simbolo() const {
    if (tipo == "Carnívoro" || tipo == "Carnivoro") return 'C';
    if (tipo == "Herbívoro" || tipo == "Herbivoro") return 'H';
    return '?';
}