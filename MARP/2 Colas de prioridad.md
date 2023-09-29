# Priority Queue

Funcionamiento y métodos externos identicos a cola normal.
La inserción depende de unas comparativas para que aun siendo FIFO se ordene.
Su estructuración interna es como un árbol apra facilitar la inserción en tiempo O(logN)
```c++
insert_with_priority(template<T> var); //inserta en la cola respetando un nivel de prioridad que puede ser por máximo o por mínimo
template<T> pull_highest_priority(); // Elimina elto de max prioridad
template<T> peek(); // Comprueba en O(1) el valor max o min de la cola
```

        7
10          20
18 15

No se suele utilizar la primera posicion por comodiad al pasar las operaciones del hijo al padre
Cola
0   1   2   3   4   5   6
    7   10  20  18  15

        8
10          9
20  30

# Monticulo binario
Tipo de dato con estructuración arborea que respeta que cada valor padre es mayor que sus hijos.
Su estructuración es la de un árbol binario.

Solucion ordenado pacientes
Para distinguir pacientes iguales, elementos iguales se puede usar el comparador de tipos
Para pacientes con mismo valor se hace un orden estricto de llegada, se debe asignar un turno de llegada no absoluto, relativo a ese valor.
```c++ Struct{
        int dolor;
        int turno;
}```

Solucion Multitarea
Se intenta usar la cola de prioridad par que te de las siguientes 2 tareas y eso no es uena idea
La cola de prioridad tiene que tener de tamaño max el numero inicial de repeticiones para evitr timelimit
La cola de proridad solo guarda la siguiente activvacion de esta tarea periodica
Sis acas dos tareas no tienen porque ser contiguas
No se deben sacar 2 a la vez porque quizás se solapan al volver a entrar
