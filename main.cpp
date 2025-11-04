#include "Mundo.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Serializador.h"
#include <iostream>
#include <memory>  // Para std::make_shared
#include <thread>  // Para pausas
#include <chrono>  // Para timing
#include <conio.h> // Para detectar teclas (Windows)
// Si usas Linux, comenta la línea anterior y usa: #include <ncurses.h>

using namespace std;

void mostrarMundo(const Mundo& mundo) {
    cout << "\n";
    for (int y = 0; y < mundo.getAlto(); ++y) {
        for (int x = 0; x < mundo.getAncho(); ++x)
            cout << mundo.simboloPrincipal(x, y) << ' ';
        cout << '\n';
    }
}

void mostrarEstadisticas(const Mundo& mundo) {
    cout << "Leyenda: H=Herbívoro, C=Carnívoro, .=Vacío" << endl;
    cout << "Presiona 'q' para salir, 's' para guardar estado" << endl;
}

int main() {
    Mundo mundo(10, 5);

    // ✅ Usamos smart pointers en lugar de new
    mundo.agregarCriatura(2, 2, std::make_shared<Herbivoro>(2, 2));
    mundo.agregarCriatura(5, 3, std::make_shared<Carnivoro>(5, 3, 10));

    // Agregar más criaturas para hacerlo más interesante
    mundo.agregarCriatura(1, 1, std::make_shared<Herbivoro>(1, 1));
    mundo.agregarCriatura(8, 4, std::make_shared<Herbivoro>(8, 4));
    mundo.agregarCriatura(3, 0, std::make_shared<Carnivoro>(3, 0, 15));

    cout << "=== SIMULADOR DE ECOSISTEMA ===" << endl;
    cout << "Estado inicial del mundo:" << endl;
    mostrarMundo(mundo);
    mostrarEstadisticas(mundo);

    // 🔄 BUCLE PRINCIPAL DEL JUEGO
    int turno = 0;
    bool ejecutando = true;

    while (ejecutando) {
        // Pequeña pausa entre turnos (500ms)
        this_thread::sleep_for(chrono::milliseconds(500));

        // Limpiar pantalla (simple aproximación)
        system("cls");  // Windows
        // system("clear");  // Linux/Mac

        cout << "=== SIMULADOR DE ECOSISTEMA - Turno " << turno + 1 << " ===" << endl;

        // Actualizar el mundo (mover criaturas, etc.)
        mundo.actualizar();

        // Mostrar el estado actual
        mostrarMundo(mundo);
        mostrarEstadisticas(mundo);

        turno++;

        // Verificar si el usuario quiere salir
        if (kbhit()) {  // Si hay una tecla presionada
            char tecla = getch();
            if (tecla == 'q' || tecla == 'Q') {
                ejecutando = false;
                cout << "\nSaliendo del simulador..." << endl;
            }
            else if (tecla == 's' || tecla == 'S') {
                Serializador::guardar(mundo, "estado_mundo.txt");
                cout << "\nEstado guardado en 'estado_mundo.txt'" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        }

        // Salir automáticamente después de 50 turnos (opcional)
        if (turno >= 50) {
            cout << "\nSimulación completada (50 turnos)" << endl;
            ejecutando = false;
        }
    }

    Serializador::guardar(mundo, "estado_mundo_final.txt");
    cout << "Estado final guardado en 'estado_mundo_final.txt'" << endl;
    cout << "Simulación terminada. Presiona cualquier tecla para salir...";
    cin.get();  // Esperar entrada antes de salir

    return 0;
}