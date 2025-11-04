```mermaid
classDiagram
    class Creature {
        <<abstract>>
        +int id
        +string species
        +int age
        +double energy
        +virtual void actuar() = 0
        +virtual void moverse() = 0
        +virtual void reproducirse() = 0
        +virtual void morir() = 0
        +virtual json serializar()
        +virtual void deserializar(json)
    }

    class Mutant {
        +string mutation_signature
        +override void actuar()
        +override void reproducirse()
    }

    class WingedMutant {
        +double wing_span
        +override void moverse()
    }

    class Flyer {
        <<interface>>
        +virtual void volar() = 0
    }

    class Regenerator {
        <<interface>>
        +virtual void regenerar() = 0
    }

    class Chimera {
        +bool toxic
        +override void actuar()
        +override void moverse()
    }

    class Node {
        +int x
        +int y
        +vector<shared_ptr<Creature>> inhabitants
        +map<string,double> environment_factors
    }

    class World {
        +vector<vector<Node>> grid
        +vector<shared_ptr<Creature>> all_creatures
        +void tick()
        +void saveJSON()
        +void loadJSON()
    }

    Creature <|-- Mutant
    Mutant <|-- WingedMutant
    Flyer <|.. WingedMutant
    Regenerator <|.. Chimera
    Mutant <|-- Chimera
    Chimera --> Creature : interacts_with
    World *-- Node : contains
    Node o-- Creature : holds
