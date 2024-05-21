# Priority Queue y Heap

## 2.1 Colas de prioridad
En las colas FIFO (estudiadas en Estructuras de Datos) los elementos salen de la cola en el mismo orden en que entraron. Pero hay aplicaciones donde los elementos tienen que ir siendo atendidos según su prioridad, y además se da el caso de que llegan algunos elementos, se atiende el más prioritario, luego posiblemente llegan otros que se mezclan con los que quedaban, se atienen a otros por orden de prioridad y así sucesivamente. Necesitamos un TAD que tenga operaciones para insertar elementos y también para conocer y eliminar el más prioritario cada vez. Esas son las colas de prioridad. 

Para que podamos conocer, dados dos elementos, cuál es el más prioritario, utilizamos una relación de orden total, <. En las colas de prioridad de mínimos, el elemento más prioritario es el menor, y en las colas de prioridad de máximos, el elemento más prioritario es el mayor.

>Se suelen usar en algoritmos de bíusqueda de camino más corto, Dijkstra o Priority Queues


- Video de apuntes - https://www.youtube.com/watch?v=mvaLy_ta3Qw&feature=youtu.be

## 2.2 Montículos binarios
Los montículos binarios de mínimos (respectivamente, de máximos) son árboles binarios semicompletos donde cada nodo guarda un valor que es menor o igual (respectivamente, mayor o igual) que todos sus descendientes. Por tanto, la raíz contiene el menor (respectivamente, mayor) elemento.

Los montículos son una buena estructura de datos para representar las colas de prioridad, ya que el elemento más prioritario se encontrará siempre en la raíz y las operaciones de insertar un nuevo elemento o eliminar la raíz se pueden implementar eficientemente en un montículo, como se explica en el siguiente vídeo:
- Video de apuntes - https://www.youtube.com/watch?v=J0lMpMKf8LE&feature=youtu.be

1. Un árbol binario completo de altura $h≥1$ tiene $2i−1$ nodos en el nivel $i$, para todo $i$ entre $1$ y $h$.
2. Un árbol binario completo de altura $h≥1$ tiene $2h−1$ hojas.
3. Un árbol binario completo de altura $h≥0$ tiene $2h−1$ nodos.
4. La altura de un árbol binario semicompleto formado por n nodos es $⌊log n⌋+1$.

## Test Semana 2
1. El coste de insertar en una cola de prioridad de mínimos incialmente vacía implementada mediante un montículo de mínimos una secuencia de Nelementos distintos ordenada de mayor a menor es O(N log N)

Cada nuevo elemento que se inserta es menor que todos los que ya hay en el montículo, por lo que al colocarlo en la última posición es necesario flotarlo hasta la raíz, teniendo cada inserción un coste en O(log N).

 2. La altura de un árbol binario semicompleto formado por 167 nodos es 8.
 El máximo número de nodos que puede tener un árbol binario de altura ℎ es $2^ℎ−1$, cuando es completo. Y el mínimo número de nodos es $2^{ℎ−1}$, cuando tiene ℎ−1 niveles completos y solamente un nodo en el nivel ℎ.

- Falso. Si la altura es 10, tiene que tener al menos 512 nodos.
- Falso. Si la altura es 9, tiene que tener al menos 256 nodos.
- Falso. Si la altura es 6, solamente caben 63 nodos.
- Cierto. Un árbol semicompleto de altura 8 tiene entre 128 y 255 nodos.

3. En este montículo de mínimos 9, 11 y 12 han sido los últimos en insertarse.

![alt text](.\Assets\TestMonticulos1.png)

El último elemento insertado se añadió en la hoja más a la derecha del último nivel y después fue flotado si hacía falta hacía la raíz. Puede haber sido el 12 y no haber necesitado ser flotado. Puede ser el 11 y haberse intercambiado con el 12, que ocupaba su posición. Y puede haber sido el 9, habiendo sido flotado dos niveles. En cambio, no puede ser el 2, porque en ese caso el 9 ocuparía su lugar antes de la inserción, y eso no es posible porque el 9 no puede ser el padre del 4 en un montículo de mínimos.

4. La eliminación del máximo(26) en el siguiente montículo de máximos de la izquierda da como resultado el montículo de la derecha:

![alt text](.\Assets\testMonticulos2.png)

El valor oculto puede ser 9,10 o 13. Por ser hijo del 14 antes de la eliminación sabemos que tiene que ser menor que 14. Por ser padre del 8, tiene que ser mayor que 8. Como el 11 y el 12 ya están, solamente puede ser 9, 10 o 13.

5.  El coste, en el caso peor, de consultar el elemento más prioritario de una cola de prioridad de mínimos con $N$ elementos implementada mediante un montículo de mínimos es O(1).

En un montículo de mínimos, el elemento más prioritario es el menor, que está en la raíz del montículo o primera posición del vector. Acceder a él tiene coste $=(1)$

6. El coste, en el caso peor, de eliminar el elemento más prioritario de una cola de prioridad de máximos con $N$ elementos implementada mediante un montículo de máximos es $O(log N)$.

Para eliminar el elemento más prioritario la raíz del árbol se sustituye por el último elemento del último nivel, y este es hundido en el caso peor la altura del árbol, que es logarítmica respecto al número de nodos.

7. Este vector se representa con el siguiente montículo de máximos.

![alt text](.\Assets\testMonticulos3.png)
![alt text](.\Assets\testMonticulos4.png)

La raíz está en la posición 1, y el nodo de la posición $i$ tiene su hijo izquierdo en la posición $2i$ y su hijo derecho en la posición , si estos números no exceden 𝑛𝑢𝑚𝐸𝑙𝑒𝑚𝑠. Todo nodo cumple que es mayor (o igual) que sus hijos, si estos existen.

8. En este monticulo de máximos elúltimo en haberse introducido puede haber sido el 10 o el 9.

![alt text](.\Assets\testMonticulos5.png)

El último elemento insertado se añadió en la hoja más a la derecha del último nivel y después fue flotado si hacía falta hacía la raíz. Puede haber sido el 9 y no haber necesitado ser flotado. Puede haber sido el 10 y haberse intercambiado con el 9, que ocupaba su posición. Pero no puede ser el 19, porque entonces el 10 ocuparía su posición antes de la última inserción, y el 10 no puede ser padre del 13 en un montículo de máximos. Por el mismo motivo no puede ser el 25 el último elemento insertado.

9. Este vector representa un montículo de mínimos

![alt text](.\Assets\testMonticulos6.png)
Visto como árbol semicompleto (en realidad, completo), todo nodo cumple que es mayor (o igual) que su padre. El padre del nodo en la posición $i(i>1)$ está en la posición $i/2$.

10. El recorrido por niveles (o en anchura) de un montículo de mínimos **NO** produce una sencuencia de creciente de valores.

 En un montículo de mínimos el hijo derecho puede tener valores menores que el hijo izquierdo, dentro del mismo nivel.

## Anotaciones propias

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
