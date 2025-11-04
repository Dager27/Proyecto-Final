#include "Mundo.h"
#include <memory>
#include <iostream>
#include <random>

using namespace std;

// Generador de números aleatorios (moderno)
std::random_device rd;
std::mt19937 gen(rd());

Mundo::Mundo(int ancho, int alto) : ancho(ancho), alto(alto) {
    nodos.resize(alto, vector<Nodo>(ancho));
}

void Mundo::agregarCriatura(int x, int y, std::shared_ptr<Criatura> criatura) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto) {
        nodos[y][x].agregarCriatura(criatura);
    }
}

void Mundo::actualizar() {
    // Primero, actualizamos todas las criaturas
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (!nodos[y][x].estaVacio()) {
                auto criatura = nodos[y][x].obtenerCriatura();
                if (criatura && criatura->estaViva()) {
                    criatura->actualizar(); // Esto hace que se muevan
                }
            }
        }
    }

    // Luego, movemos las criaturas a sus nuevas posiciones
    vector<vector<shared_ptr<Criatura>>> nuevasPosiciones(alto, vector<shared_ptr<Criatura>>(ancho, nullptr));

    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (!nodos[y][x].estaVacio()) {
                auto criatura = nodos[y][x].obtenerCriatura();
                if (criatura && criatura->estaViva()) {
                    int nuevaX = criatura->obtenerX();
                    int nuevaY = criatura->obtenerY();

                    // Verificar límites del mundo
                    if (nuevaX >= 0 && nuevaX < ancho && nuevaY >= 0 && nuevaY < alto) {
                        // Solo mover si la nueva posición está vacía
                        if (nodos[nuevaY][nuevaX].estaVacio()) {
                            nuevasPosiciones[nuevaY][nuevaX] = criatura;
                            nodos[y][x].limpiar(); // Limpiar posición anterior
                        } else {
                            // Si no se puede mover, quedarse en la misma posición
                            nuevasPosiciones[y][x] = criatura;
                        }
                    } else {
                        // Si se sale de los límites, quedarse en la misma posición
                        criatura->mover(x - criatura->obtenerX(), y - criatura->obtenerY());
                        nuevasPosiciones[y][x] = criatura;
                    }
                }
            }
        }
    }

    // Actualizar el mundo con las nuevas posiciones
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (nuevasPosiciones[y][x]) {
                nodos[y][x].agregarCriatura(nuevasPosiciones[y][x]);
            }
        }
    }

    // Limpiar criaturas muertas
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (!nodos[y][x].estaVacio()) {
                auto criatura = nodos[y][x].obtenerCriatura();
                if (criatura && !criatura->estaViva()) {
                    nodos[y][x].limpiar();
                }
            }
        }
    }
}

void Mundo::limpiar() {
    for (int y = 0; y < alto; ++y)
        for (int x = 0; x < ancho; ++x)
            nodos[y][x].limpiar();
}

bool Mundo::estaVacio(int x, int y) const {
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        return nodos[y][x].estaVacio();
    return true;
}

char Mundo::simboloPrincipal(int x, int y) const {
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        return nodos[y][x].simboloPrincipal();
    return '.';
}

int Mundo::getAncho() const { return ancho; }
int Mundo::getAlto() const { return alto; }

const vector<vector<Nodo>>& Mundo::obtenerNodos() const {
    return nodos;
}