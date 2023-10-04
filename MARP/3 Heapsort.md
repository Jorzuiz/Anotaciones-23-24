# 3 Heapsort y colas de prioridad con prioridades variables
## 3.1 Heapsort
Una posible forma de ordenar de menor a mayor los elementos de un vector consiste en insertar todos los elementos del vector en una cola de prioridad de mínimos y después ir extrayendo uno a uno los elementos de la cola para ir guardándolos de izquierda a derecha en el vector. Si el vector tiene N
 elementos, este método tiene una complejidad en tiempo en Θ(NlogN)
 y en espacio adicional en Θ(N)
 por el espacio necesario para almacenar el montículo utilizado en la implementación de la cola de prioridad.

Podemos ahorrarnos el espacio adicional si el montículo se construye sobre el propio vector a ordenar. Primero los elementos se distribuyen para convertir el vector en un montículo y después se van extrayendo uno a uno colocándolos en la parte del vector que ya no es necesaria para almacenar el montículo, que va siendo cada vez más pequeño. El siguiente vídeo ilustra con detalle el proceso:

https://www.youtube.com/watch?v=mqOIxe3ip0o

## 3.2 Colas de prioridad con prioridades variables
Hay aplicaciones donde interesa cambiar la prioridad de elementos que ya se encuentran en la cola de prioridad, de modo que estos ocupen su nueva posición atendiendo a la nueva prioridad. Eso ocurre, por ejemplo, en el algoritmo de Dijkstra para encontrar caminos de coste mínimo en un grafo dirigido valorado (que veremos más adelante).

Una forma cómoda de referirse a los elementos que pueden formar parte de la cola de prioridad es numerarlos, dando un número distinto a cada uno.

El siguiente vídeo muestra cómo modificar la implementación mediante montículos de las colas de prioridad para obtener esta nueva funcionalidad:

https://www.youtube.com/watch?v=dVwcKjXsqZc

## 3.3 Cuestionario repaso

1. A la hora de convertir un vector en un montículo como primera fase para ordenarlo de menor a mayor por el método heapsort, ¿cuál es el caso peor (el caso que provoca que haya que hacer más trabajo)?
>Cuando el vector inicial está ordenado de menor a mayor.
Para ordenar de menor a mayor el vector tiene que convertirse en un montículo de máximos. El caso peor se da cuando el vector está inicialmente ordenado de menor a mayor porque cada elemento (en la primera mitad del vector) es menor que todos los siguientes y tiene que ser hundido hasta una hoja.

2. Si se hace de forma eficiente, ¿cuál es la complejidad de convertir un vector de $N$ elementos en un montículo en el caso peor?
>$O(N)$
Si se recorre la primera mitad de los elementos del vector de derecha a izquierda y cada elemento se hunde entre los siguientes la complejidad total está en $O(N)$

3. Si se hace de forma eficiente, ¿cuál es la complejidad en espacio adicional del algoritmo heapsort para ordenar un vector de $N$ elementos? 
>$O(1)$
Se puede recorrer la primera mitad de los elementos del vector de derecha a izquierda hundiendo cada elemento entre los siguientes, y haciendo todas las transformaciones sobre el propio vector, por lo que la complejidad en espacio adicional está en $O(1)$

4. La función
```c++
   void funcion(vector<int> & v) {
      for (int i = 1; i < v.size(); ++i) {
         hundir_max(v, v.size(), i);
      }
   }
```
>Mueve los elementos del vector pero no lo convierte necesariamente en eun montículo. 
Un vector puede convertirse en un montículo de dos maneras distintas:
>* Recorriendo los elementos de izquierda a derecha y flotando cada elemento entre los anteriores (ya procesados), o
>* Recorriendo la primera mitad de los elementos de derecha a izquierda, hundiendo cada elemento entre los siguientes, que ya forman montículos.
Aquí se han mezclado las dos ideas, lo que no garantiza que el resultado final sea un montículo, aunque haya elementos que cambien de lugar.

5. Para ordenar un vector de menor a mayor utilizando el método heapsort (con un coste en espacio adicional constante), primero el vector tiene que convertirse en un montículo de máximos.
>Verdadero. Al convertir el vector, sobre sí mismo, en un montículo de máximos, podemos ir sacando los elementos de mayor a menor, e irlos colocando de derecha a izquierda en el vector, en las posiciones que van quedando vacías al no ser necesarias para almacenar el montículo.

6. Para ordenar un vector de mayor a menor utilizando el método heapsort (con un coste en espacio adicional constante), primero el vector tiene que convertirse en un montículo de máximos.
>Falso.Si convertimos, sobre sí mismo, el vector en un montículo de máximos, el primer elemento en salir sería el mayor, y dejaría libre una posición al final del vector. Pero si queremos ordenar de mayor a menor, ahí debería ir el menor elemento. Esta estrategia no ordena como queremos. El vector debería convertirse en un montículo de mínimos.

7. En las colas de prioridad con prioridades variables, cambiar la prioridad de un elemento que se encuentra en una cola con $N$ elementos tiene un coste en
>$O(log N)$
Al cambiar la prioridad de un elemento este tiene que ser flotado o hundido en el caso peor un número de veces igual a la altura del montículo, que es logarítmica respecto al número de nodos.

8. Cuando en un montículo de mínimos cambiamos la prioridad de un elemento a un valor menor, el elemento tiene que ser flotado (intercambiado con su padre mientras este sea mayor).
>Verdadero. Al ser un montículo de mínimos, los elementos menores se acercan a la raíz.

9. Cuando en un montículo de máximos cambiamos la prioridad de un elemento a un valor menor, el elemento tiene que ser flotado (intercambiado con su padre mientras este sea menor).
>Falso. Al ser un montículo de máximos, los elementos mayores son los que más cerca están de la raíz. Si la prioridad de un elemento se hace menor, el elemento tiene que ser hundido.

10. Cuando en una cola de prioridad de mínimos con prioridades variables, implementada mediante un montículo, se cambia la prioridad de uno de los elementos, este siempre cambiará de posición en el montículo.
>Falso. No necesariamente tiene que cambiar de posición. Solo cambiará si la prioridad se hace menor que su padre o mayor que el menor de los hijos.

# 3.4 Cuestionario de evaluacion

1. Hemos visto en IndexPQ una implementación de colas con prioridad variable que hace uso de un vector de pares ⟨ elemento, prioridad ⟩ y un vector de posiciones de esos elementos.

>Imagina que modificamos esta implementación eliminando el vector de posiciones. ¿Cuál de estas afirmaciones es correcta?
>* Cierto. El montículo está ordenado según prioridades, no elementos, eso quiere decir que para modificar la prioridad de un elemento, antes, hay que encontrarlo. Como el elemento puede estar en cualquier posición hay que recorrer todos los elementos.
>* Falso. Incorrecta. Sigue siendo logarítmica, flotamos un elemento ya encontrado.
>* Falso. Incorrecta. Por ejemplo, modificar la prioridad (update) pasa a tener coste lineal.
>* Falso. La respuesta correcta es: Modificar la prioridad (update) pasa a tener coste lineal.

2. ¿Cuál es el coste de la operación de eliminar el elemento más prioritario (pop) vista en IndexPQ?
>* Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
>* Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
>* Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
>* Cierto. $O(log N)$

3. La función
```c++
   void funcion(vector<int> & v) {
      for (int i = v.size() - 1; i > 0; --i) {
         flotar_max(v, v.size(), i);
      }
   }
```
>Mueve los elementos del vector pero no lo convierte necesariamente en un montículo. Un vector puede convertirse en un montículo de dos maneras distintas:
>* recorriendo los elementos de izquierda a derecha y flotando cada elemento entre los anteriores (ya procesados), o
>* recorriendo la primera mitad de los elementos de derecha a izquierda, hundiendo cada elemento entre los siguientes, que ya forman montículos.

>Aquí se han mezclado las dos ideas, lo que no garantiza que el resultado final sea un montículo, aunque haya elementos que cambien de lugar.

4. ¿Cuál es el coste de una implementación eficiente de un algoritmo de ordenación basado en comparaciones de elementos (como son por ejemplo heapsort, mergesort, etc)?
>No se puede hacer un algoritmo de ordenación basado en comparaciones con coste inferior a $O(log N)$ y los ejemplos que hemos puesto son algoritmos con coste en $O(log N)$.

5. Dado un vector ordenado de menor a mayor, ¿cuál es el coste de convertirlo en un montículo de máximos?
>$O(N)$ Sí que se puede convertir en un montículo de máximos. Ahora bien, si el vector está ordenado de menor a mayor, cada elemento (en la primera mitad del vector) es menor que todos los siguientes por lo que tendrá que ser ser hundido hasta una hoja. Esto quiere decir que el coste será de $O(N)$.

6. Para ordenar un vector de enteros usando la idea de heapsort no se puede implementar usando colas de prioridad, es necesario usar montículos.
>Falso. Se puede usar una cola de prioridad a cambio hay que pagar el uso extra en memoria de esa cola, ya que no podemos reutilizar el vector inicial también como cola de prioridad.

7. Cuando en un montículo de mínimos cambiamos la prioridad de un elemento a un valor menor, el elemento tiene que ser flotado (intercambiado con su padre mientras este sea mayor).
>Verdadero. Al ser un montículo de mínimos, los elementos menores se acercan a la raíz.

8. ¿Cuál es el coste de la operación de añadir un nuevo elemento (push) vista en IndexPQ?
>* Falso. Incorrecta. Es logarítmica, ya que flotar es logarítmico
>* Falso. Incorrecta. Es logarítmica, ya que flotar es logarítmico
>* Cierto. Al añadir un nuevo elemento, éste debe flotarse hasta encontrar su lugar y flotar es logarítmica
>* Falso. Ninguna de las anteriores

9. Para ordenar un vector de mayor a menor utilizando el método heapsort (con un coste en espacio adicional constante), primero el vector tiene que convertirse en un montículo de máximos.
>Falso. Si convertimos, sobre sí mismo, el vector en un montículo de máximos, el primer elemento en salir sería el mayor, y dejaría libre una posición al final del vector. Pero si queremos ordenar de mayor a menor, ahí debería ir el menor elemento. Esta estrategia no ordena como queremos. El vector debería convertirse en un montículo de mínimos.

10. Considerando el TAD de colas con prioridades variables implementado en la clase IndexPQ visto, ¿cuál de estas operaciones tiene un coste lineal?
>* Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
>* Falso. Incorrecta. Es logarítmica, ya que tanto flotar como hundir son logarítmicos.
>* Falso. Incorrecta. Es constante, basta consultar el tamaño del array.
>* Cierto. Ninguna de las anteriores. La respuesta correcta es: La constructora, es decir, crear una cola vacía