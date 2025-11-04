#include "Serializador.h"
#include <fstream>
#include "Mundo.h"

using namespace std;

void Serializador::guardar(const Mundo& mundo, const string& archivo) {
    ofstream out(archivo);
    if (!out) return;

    out << "Tamaño: " << mundo.getAlto() << "x" << mundo.getAncho() << "\n";

    for (int i = 0; i < mundo.getAlto(); ++i) {
        for (int j = 0; j < mundo.getAncho(); ++j)
            out << mundo.simboloPrincipal(j, i) << ' ';
        out << '\n';
    }
    out.close();
}
