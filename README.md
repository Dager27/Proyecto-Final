# 🌿 Simulación “Las Criaturas del Valle”  

### 🧩 Proyecto de Programación Orientada a Objetos  

---

## 📘 Descripción del proyecto  

**“Las Criaturas del Valle”** es una simulación basada en los principios de la **Programación Orientada a Objetos (POO)**, donde un ecosistema digital evoluciona de manera dinámica.  
En este valle, distintas especies de criaturas conviven, se adaptan, mutan y mueren según las condiciones cambiantes del entorno.  

El proyecto tiene como objetivo **modelar el comportamiento emergente de un ecosistema virtual**, aplicando conceptos avanzados de diseño orientado a objetos, incluyendo:
- Herencia múltiple  
- Polimorfismo  
- Composición y agregación  
- Asociación simple entre objetos  
- Persistencia en **JSON** y **XML**  
- Uso de contenedores **STL**  
- Aleatoriedad con `<random>`  

### 🎯 Propósito del sistema  
El sistema busca demostrar cómo los principios de la POO permiten crear mundos complejos y adaptativos.  
Los estudiantes o investigadores pueden usarlo como base para estudiar dinámicas ecológicas, algoritmos evolutivos o sistemas artificiales inspirados en la naturaleza.  

### 👥 Usuarios objetivo  
- Estudiantes de programación que deseen practicar POO aplicada a simulaciones.  
- Profesores que busquen una herramienta didáctica para enseñar herencia, polimorfismo y persistencia.  
- Investigadores o curiosos interesados en observar evolución artificial o comportamiento emergente.  

---

## 🧑‍💻 Manual del usuario  

### 🕹️ Funcionalidades principales  
- **Mapa dinámico** representado como una matriz de nodos (`Nodo`), donde cada celda puede contener múltiples criaturas.  
- **Ciclo de vida completo**: nacimiento, movimiento, reproducción, mutación y muerte.  
- **Evolución ambiental**: cada turno el entorno cambia (temperatura, recursos, humedad), afectando el comportamiento de las criaturas.  
- **Aleatoriedad controlada**: todos los procesos usan generadores pseudoaleatorios (`std::mt19937`) para ofrecer resultados diferentes en cada simulación.  
- **Persistencia**: el mundo puede **guardarse en JSON o XML** y **cargarse posteriormente** para continuar la simulación.  
- **Visualización textual** del mapa en consola (por ejemplo, `.` = vacío, `H` = herbívoro, `C` = carnívoro).  

--
### 🚀 Casos de uso  

1. Iniciar una simulación nueva:
   ./sim --size 20x15 --ticks 200 --seed 42

2. Agregar criaturas al mundo:
   mundo.agregarCriatura(2, 2, std::make_shared<Herbivoro>(2, 2));
   mundo.agregarCriatura(5, 3, std::make_shared<Carnivoro>(5, 3));

3. Mostrar el estado del mundo:
   for (int y = 0; y < mundo.getAlto(); ++y) {
       for (int x = 0; x < mundo.getAncho(); ++x)
           std::cout << mundo.simboloPrincipal(x, y) << ' ';
       std::cout << '\n';
   }
-->

<!--
## 💻 Instrucciones de compilación y ejecución

1. Clonar el repositorio:
   git clone <URL_DEL_REPOSITORIO>
   cd ProyectoFinal

2. Compilar con CMake (Windows / Linux / Mac):
   mkdir build
   cd build
   cmake ..
   cmake --build .

3. Ejecutar el programa:
   ./ProyectoFinal.exe
-->

<!--
## 📂 Estructura de carpetas y explicación del código

ProyectoFinal/
├── CMakeLists.txt                # Configuración del proyecto
├── main.cpp                      # Punto de entrada del programa
├── Mundo.h / Mundo.cpp            # Clase que maneja la grilla y criaturas
├── Nodo.h / Nodo.cpp              # Cada celda del mapa
├── Criatura.h / Criatura.cpp      # Clase base abstracta
├── CriaturasDerivadas.h / CriaturasDerivadas.cpp # Herbívoros y Carnívoros
├── Serializador.h / Serializador.cpp  # Guardado y carga de estado
└── README.md                     # Documentación del proyecto

- Criatura: Clase base con métodos comunes (mover, modificarEnergia, estaViva, etc.)
- Herbivoro y Carnivoro: Clases derivadas con comportamiento específico.
- Nodo: Representa celdas del mundo y contiene referencias a criaturas.
- Mundo: Gestiona la grilla de nodos y la lógica de actualización de criaturas.
- Serializador: Guarda y carga el estado del mundo desde archivos.
-->

<!--
## 📸 Capturas de pantalla / Ejemplos de salida

Estado inicial del mundo:
. . . . .
. . H . .
. . . . .
. . . C .
. . . . .

H = Herbívoro, C = Carnívoro, . = espacio vacío


---

## 🏆 Créditos

- **Autor del proyecto:** David Gaviria  
- Desarrollado como proyecto académico de POO en C++ con enfoque en simulación de ecosistemas y persistencia de datos.
