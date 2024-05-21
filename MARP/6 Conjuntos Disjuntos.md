# 6 Conjuntos Disjuntos, grafos valorados y árboles de recubrimiento de coste mínimo

Objetivos:

- Conocer el TAD de los conjuntos disjuntos para representar relaciones de equivalencia dinámicas y cómo implementarlos de forma eficiente.
- Conocer los grafos valorados y poder utilizarlos para resolver problemas que al modelarse mediante grafos necesitan que las aristas tengan asociado un valor.
- Saber hallar el árbol de recubrimiento de coste mínimo de un grafo conexo mediante los algoritmos de Prim o Kruskal.

## 6.1 Conjuntos disjuntos

A veces, para resolver un problema, necesitamos representar una relación de equivalencia (reflexiva, simétrica y transitiva) entre elementos. Y además esta relación es dinámica, en el sentido de que van apareciendo nuevas relaciones entre elementos a la vez que nos preguntamos si dos elementos concretos están relacionados entre sí.

Las relaciones de equivalencia inducen sobre el conjunto de elementos una partición, una serie de conjuntos disjuntos cuya unión es el total, es decir, que cada elemento pertenece exactamente a un subconjunto. El TAD de los conjuntos disjuntos permite modelar particiones de este estilo. El siguiente vídeo los presenta y muestra cómo se pueden implementar de forma muy eficiente:

- Video [Conjuntos Disjuntos](https://www.youtube.com/watch?v=RqcwQS_0mcA)

Código [ConjuntosDisjuntos.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/9eadb51cbe3c460a5ebb6bab0dd7fdd5bfaf03cc/MARP/Practicas-MARP/ConjuntosDisjuntos.h)

> Comenzando con una partición unitaria de 10 elementos, muestra el contenido del vector id[] si utilizas la implementación de búsqueda rápida, y se unen los siguientes pares de elementos 9-0 3-4 5-8 7-2 2-1 5-7 0-3 4-2. Si utilizas la implementación con unión rápida, dibuja los árboles que se van formando, y el correspondiente valor del vector p[], con esa misma secuencia de uniones. Haz lo mismo utilizando la implementación con unión rápida por tamaños.

> El problema 22  Petroleros hundidos del juez automático es una extensión del problema de la detección de manchas negras en una imagen que vimos la Semana 4. La diferencia está en que la imagen va cambiando al ir apareciendo más píxeles negros (también la definición de mancha es algo distinta). ¿Se podría utilizar la solución que vimos entonces, aplicada a cada imagen? ¿Qué coste tendría procesar todas las imágenes? ¿Se puede hacer mejor utilizando conjuntos disjuntos? ¿Y qué coste tendría esta otra solución?

## 6.2 Grafos valorados

Hay problemas que, al modelarlos mediante un grafo, necesitan que asociemos valores a las aristas. Por ejemplo, si los vértices representan ciudades y las aristas conexiones por avión, el valor puede ser la distancia que recorre el avión, el tiempo que tarda o la tarifa del vuelo. Estos grafos son los que se conocen como grafos valorados. Existen grafos valorados tanto dirigidos como no dirigidos, según sus aristas estén orientadas o no. Esta semana nos centraremos en grafos valorados no dirigidos y la semana que viene estudiaremos los dirigidos.

El siguiente vídeo introduce los grafos valorados, qué tipo de cosas se puede hacer con ellos y cómo se implementan:

- Vídeo de apuntes - https://www.youtube.com/watch?v=Z9V-CG5uBu4

Código [GrafoValorado.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/9eadb51cbe3c460a5ebb6bab0dd7fdd5bfaf03cc/MARP/Practicas-MARP/GrafoValorado.h)

## 6.3 Árboles de recubrimiento de coste mínimo

Dado un grafo no dirigido conexo, un árbol de recubrimiento suyo es un subgrafo que conecta a todos los vértices (por eso se dice que es de recubrimiento) y que no contiene ciclos (por eso es un árbol). Por ejemplo, la unión de los caminos que encuentra un recorrido en profundidad o en anchura de un grafo conexo es un árbol de recubrimiento. 

Si el grafo es valorado, tiene sentido preguntarse por un árbol de recubrimiento de coste mínimo suyo, es decir, uno tal que no existe otro con coste menor, donde el coste del árbol de recubrimiento es la suma de los valores de las aristas.

La siguiente figura muestra un grafo valorado donde se han resaltado las aristas que forman un árbol de recubrimiento de coste mínimo:
![alt text](.\Assets\ArbolRecMinimo.png)

El siguiente vídeo muestra cómo se puede resolver este problema de forma eficiente utilizando el algoritmo de Kruskal:

- Vídeo Apuntes - https://www.youtube.com/watch?v=sQsWEzVv8Lc&feature=youtu.be

El [algoritmo de Prim](https://en.wikipedia.org/wiki/Prim%27s_algorithm) es otro algoritmo voraz que también resuelve el problema de hallar el árbol de recubrimiento mínimo de un grafo valorado. Este algoritmo comienza desde un vértice del grafo y va expandiendo desde él un árbol que termina siendo de recubrimiento del grafo completo si este es conexo (si no, el árbol recubrirá la componente conexa del vértice con el que se empieza). Para conseguir que el coste del árbol sea mínimo el árbol se va expandiendo eligiendo cada vez la arista de menor peso que une un vértice del árbol con otro que no pertenece al árbol (la corrección se basa también en la propiedad del corte de la que se habla en el vídeo anterior). El algoritmo puede implementarse con un coste en $O(A\:logV)$ para un grafo con $V$ vértices y $A$ aristas, utilizando una cola de prioridad para seleccionar cada vez la arista más prometedora.

## Test Semana 6

1. Utilizando las estructuras de partición podemos detectar si un grafo es acíclico. Si están implementadas con unión rápida por tamaño y compresión de caminos, ¿cuál sería la complejidad de dicho algoritmo si el grafo tiene $V$ vértices y $A$ aristas?.

El algoritmo consiste en recorrer todas las aristas haciendo unión de sus extremos. Si los extremos de una arista ya pertenecen a la misma clase de equivalencia el grafo contiene un ciclo. Se realizan $A$ operaciones de unión sobre $V$ elementos, por lo que utilizando unión rápida por tamaño y compresión de caminos el coste de todas las operaciones está en $=(V+A\:lg*V)$.

2. Supongamos que tenemos una estructura de partición con $N$ elementos que utiliza unión rápida por tamaño y compresión de caminos. La estructura empieza vacía (partición trivial) y después se realizan $N^2$ operaciones de unión aleatorias. A continuación, se realizan operaciones para saber si están unidos o no cada posible par de elementos (aproximadamente $\frac{N^2}{2}$. El orden de complejidad de la altura de los árboles en la estructura resultante es:

Al haber compresión de caminos, al buscar un elemento este termina estando en la raíz de un árbol o en la raíz de un hijo de la raíz de un árbol, es decir, a profundidad 1 o 2. Si se realizan búsquedas con todos los elementos, todos los árboles terminan teniendo altura 1 o 2.

3. Considera el siguiente grafo no dirigido y valorado,

![alt text](.\Assets\testConjuntoDisjunto1.png)

El algoritmo de Kruskal considera las aristas de menor a mayor coste, y selecciona aquellas que al unirlas a las ya seleccionadas no crean ciclos. Las aristas se añaden al ARM en este orden: 10 20 40 60 80 90.

4. Si el TAD de conjuntos disjuntos se implementa con la versión de unión rápida, ¿cuál es el coste de la operación buscar en el caso peor si el conjunto tiene $N$ elementos?

En el caso peor la altura de un árbool que represente un conjunto puede ser lineal respecto al número de elementos de la partición.

5. Sea $G$ un grafo conexo no dirigido cualquiera con todos los valores de las aristas distintos. Sea $e_M$ la arista con mayor valor y $e_m$ la arista con menor valor. ¿Cuáles de estas afirmaciones son falsas?

- Es cierta. Si $e_M$ está en un ARM es porque es imprescidible seleccionarla, porque conecta dos partes del grafo que no se conectan por ninguna otra arista, por lo que al eliminarla el grafo dejaría de ser conexo.
- Es cierta. Si los valores de las aristas son todos distintos el ARM es único.
- Es cierta. Si $e_m$ no formara parte de un ARM, al añadirla se crearía un ciclo, y quitando cualquier otra arista del ciclo tendríamos un ARM de coste menor, lo cual es imposible.
- Es falsa. Según cómo sea el grafo puede hacer falta seleccionar $e_m$, porque si no no podríamos conectar todo el grafo.

6. Si el TAD de conjuntos disjuntos se implementa con la versión de unión rápida por tamaños, ¿cuál es el coste de la operación unir en el caso peor si el conjunto tiene $N$ elementos?
Si los tamaños de los árboles se tienen en cuenta al unirlos, la altura máxima de un árbol es logarítmica respecto al número $N$ de elementos en la partición. La unión requiere la búsqueda de las raíces de los árboles que contienen los elementos a unir. Esa búsqueda tiene un coste en $O(logN)$ en el caso peor.

7. El árbol de recubrimiento de un grafo conexo no tiene por qué ser único pero el de coste mínimo (ARM) siempre es único.

Falso. Solamente si el coste de todas las aristas es distinto está garantizado que el ARM es único. Con costes repetidos puede haber varios ARMs distintos, como ocurre con este grafo

![alt text](.\Assets\testConjuntoDisjunto2.png)

que tiene 3 ARM distintos, según quitemos una cualquiera de sus aristas.

8. Sea $G$ un grafo no dirigido con valores de las aristas enteros positivos distintos. Su ARM aparece marcado en rojo en la imagen. ¿Cuál es la mínima suma posible del valor del resto de aristas (las marcadas con ?)?

![alt text](.\Assets\testConjuntoDisjunto3.png)

La arista $0-2$ tiene que tener un valor mayor o igual que 10, ya que si no el vértice 0 se podría unir al resto mediante esta arista en vez de la arista $0-1$. La arista $1-3$ tiene que tener un valor mayor o igual que $16$, porque si no se podría usar en vez de la arista $2-4$ para conectar las partes izquierda y derecha del grafo. Y la arista $4-3$ tiene que tener un valor mayor o igual que 7 porque si no podría utilizarse para unir el vértice 3 al ARM, en vez de la arista $3-5$. La suma mínima posible es por tanto $10+16+7=33$.

9. El algoritmo de Kruskal para calcular el árbol de recubrimiento de coste mínimo se pueden utilizar también (o adaptar) para calcular el árbol de recubrimiento de coste máximo.

Verdadero. Se puede cambiar de signo a todas las aristas y aplicar directamente el algoritmo o considerar las aristas de mayor a menor coste.

10. ¿Cuántos árboles de recubrimiento mínimo distintos tiene el siguiente grafo valorado?
![alt text](.\Assets\testConjuntoDisjunto4.png)
El grafo tiene 6 posibles ARM distintos. Las aristas con coste 1 son todas necesarias, así como la arista de coste 2 que no aparece dentro de ningún círculo en el siguiente dibujo
![alt text](.\Assets\testConjuntoDisjunto5.png)
