#ifndef CARNIVORO_H
#define CARNIVORO_H

#include "Criature.h"

class Carnivoro : public Criatura {
public:
    Carnivoro(int x, int y, int energia);

    void actualizar() override;
    void mostrar() const override;
};

#endif
