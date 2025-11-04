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
- **Mapa dinámico** representado como una matriz de nodos (`Node`), donde cada celda puede contener múltiples criaturas.  
- **Ciclo de vida completo**: nacimiento, movimiento, reproducción, mutación y muerte.  
- **Evolución ambiental**: cada turno el entorno cambia (temperatura, recursos, humedad), afectando el comportamiento de las criaturas.  
- **Aleatoriedad controlada**: todos los procesos usan generadores pseudoaleatorios (`std::mt19937`) para ofrecer resultados diferentes en cada simulación.  
- **Persistencia**: el mundo puede **guardarse en JSON o XML** y **cargarse posteriormente** para continuar la simulación.  
- **Visualización textual** del mapa en consola (por ejemplo, `.` = vacío, `M` = mutante, `C` = quimera).  

---

### 🚀 Casos de uso  

1. **Iniciar una simulación nueva:**
   ```bash
   ./sim --size 20x15 --ticks 200 --seed 42
