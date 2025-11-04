#include "Nodo.h"

bool Nodo::estaVacio() const {
    return criatura == nullptr;
}

char Nodo::simboloPrincipal() const {
    return criatura ? criatura->simbolo() : '.';
}
