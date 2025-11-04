```mermaid
classDiagram
    class Estudiante {
        +int id
        +string nombre
        +string apellido
        +agregarCalificacion(Asignatura asignatura, float nota)
        +obtenerPromedio() float
    }

    class Asignatura {
        +int id
        +string nombre
        +float obtenerPromedio() 
    }

    class Calificacion {
        +float nota
        +Estudiante estudiante
        +Asignatura asignatura
    }

    Estudiante "1" --> "0..*" Calificacion : tiene
    Asignatura "1" --> "0..*" Calificacion : tiene
