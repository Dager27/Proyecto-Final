#ifndef HERBIVORO_H
#define HERBIVORO_H

#include "Criature.h"

class Herbivoro : public Criatura {
public:
    Herbivoro(int x, int y);
    void actualizar() override;
    void mostrar() const override;
};

#endif
