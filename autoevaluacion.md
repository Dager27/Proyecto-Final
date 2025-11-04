📊 Evaluación del Proyecto - Simulador de Ecosistema
Tabla de Evaluación Técnica
Criterio	Puntaje	Máximo	Justificación
Uso de GitHub y Gestión del Proyecto	8/10	10	Commits organizados, estructura clara, pero sin issues documentados
Herencia y Jerarquía de Clases	10/10	10	Jerarquía clara: Criatura → Herbivoro/Carnivoro con 2 niveles funcionales
Composición, Agregación y Asociación	10/10	10	Composición: Mundo→Nodos, Agregación: Nodo→Criatura, Asociación: Serializador→Mundo
Polimorfismo	10/10	10	Métodos virtuales puros actualizar(), mostrar() correctamente sobreescritos
Uso de Contenedores STL	10/10	10	vector<vector<Nodo>>, shared_ptr, string - uso variado y pertinente
Uso de Aleatoriedad	3/5	5	Básico pero funcional en Herbivoro, usa rand() en lugar de <random>
Persistencia de Datos	6/10	10	Guardado funcional en texto, falta implementar carga y formato JSON completo
Diseño y Organización del Código	9/10	10	Código modular y limpio, separación .h/.cpp clara
Manual del Usuario	12/15	15	README completo, falta sección de instalación paso a paso
Documentación del Código	3/5	5	Comentarios escasos, código auto-documentado en su mayoría
README Técnico	4/5	5	Información técnica completa, podría mejorar con diagramas UML
