# 5 Grafos Dirigidos y sus recorridos

Objetivos:

- Conocer el TAD de los grafos dirigidos y sus recorridos en profundidad y anchura. Y cómo pueden utilizarse para resolver problemas que puedan modelarse mediante grafos dirigidos.
- Conocer el problema de la ordenación topológica de un grafo dirigido acíclico y cómo puede aplicarse en la planificación de tareas con restricciones de precedencia.
- Saber cómo detectar si un grafo dirigido tiene ciclos o no.

## 5.1 Grafos dirigidos

Hay ocasiones donde es necesario orientar las aristas para poder modelar correctamente una aplicación. Por ejemplo, podemos representar la web con un grafo, donde cada página web es un vértice, y hay una arista entre una página, representada por el vértice v, y otra, representada por w, si la primera contiene un enlace a la segunda. Probablemente la segunda página no contenga un enlace a la primera (por lo que la relación entre ambas no es simétrica). Ese hecho queda bien reflejado si utilizamos una arista dirigida, v → w, que va de v a w. Así surgen los grafos dirigidos o digrafos.

![alt text](/MARP/Assets/grafoDirigido1.png)

Algunos de los conceptos de grafos que vimos para grafos no dirigidos siguen sirviendo, o se adaptan a su versión dirigida. Así hablaremos de caminos dirigidos o ciclos dirigidos.  Y también surgen otros conceptos nuevos, como el de ordenación topológica que vamos a estudiar.

El siguiente vídeo presenta los grafos dirigidos y sus recorridos en profundidad y anchura, que también van a ser muy útiles para resolver muchos de los problemas sobre estos grafos:

- Video apuntes - https://www.youtube.com/watch?v=1Nx-NYQgCLg

Código fuente: [Digrafo.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/main/MARP/Practicas-MARP/Digrafo.h)

> El problema de los caminos mínimos desde múltiples orígenes consiste en, dado un grafo dirigido y un conjunto de vértices origen, encontrar el camino más corto (con menos aristas) desde cualquiera de los orígenes al resto de vértices. Por ejemplo, en el siguiente grafo

![alt text](/MARP/Assets/grafoDirigido2.png)

> si los vértices origen son { 0, 2, 7 }, al vértice 8 llegaríamos desde el 0 por un camino de longitud 1, pero al vértice 6 llegaríamos desde el 2 por un camino de longitud 2. ¿Qué algoritmo utilizarías para encontrar el mejor camino desde cualquiera de los vértices origen?

En el siguiente vídeo se muestra la solución a un problema (cómo transformar un número en otro en el menor número de pasos, utilizando como operaciones sumar 1, multiplicar por 2 o dividir entre 3) modelándolo mediante un grafo dirigido y utilizando uno de sus recorridos:

- Vídeo apuntes - https://www.youtube.com/watch?v=FGIlp2nD4AM&feature=youtu.be

> El problema 17  La máquina calculadora del juez automático corresponde al problema resuelto en el vídeo anterior. Puedes probar ahí tu propia solución

## 5.2 Ordenación topológica

El problema de la planificación de tareas con restricciones de precedencia consiste en decidir en qué orden realizar una serie de tareas una detrás de otra respetando restricciones del estilo "La tarea A tiene que realizarse necesariamente antes que la tarea B.". Este problema puede modelarse con un grafo dirigido donde las tareas son los vértices y las restricciones corresponden a las aristas. La planificación que nos piden se conoce como ordenación topológica del grafo: los vértices se ordenan de tal forma que todas las aristas van de un vértice a otro posterior en la ordenación. Para que esto sea posible el grafo no puede tener ciclos.

El siguiente vídeo muestra cómo se puede calcular una posible ordenación topológica de un grafo dirigido acíclico:

- Vídeo apuntes - https://www.youtube.com/watch?v=tzbvVni76yY&feature=youtu.be

## 5.3 Detección de ciclos
Saber si un grafo dirigido tiene ciclos o no es interesante en muchas situaciones. ¿Tiene ciclos el siguiente grafo?

![alt text](/MARP/Assets/grafoDirigido3.png)

Para un algoritmo basado en un recorrido en profundidad la tarea de detectar ciclos es mucho más sencilla. 

El siguiente vídeo muestra algunas aplicaciones donde es interesante poder detectar ciclos y el problema se resuelve utilizando un recorrido en profundidad:

- Video apuntes - https://www.youtube.com/watch?v=4n_KkjxnZY8&feature=youtu.be

> El problema 18  Ordenando tareas del juez automático propone decidir si un conjunto de tareas pueden realizarse una detrás de otra respetando ciertas restricciones de precedencia, y si es posible, encontrar alguna forma de hacerlas.

1. Para el recorrido en postorden inverso enfocado en obtener una ordenación topológica, es indiferente en qué vértice comencemos.

Verdadero. Podemos empezar por cualquiera siempre y cuando pasemos por todos los vértices del grafo dirigido.

2. Dado el siguiente grafo dirigido,
![alt text](/MARP/Assets/testGrafoDirigido1.png)
El grafo es acíclico y por tanto su postorden inverso (3 4 0 1 2 7 5 6 8) es una ordenación topológica válida.

3. El complementario de un grafo $G=(V,A)$ es otro grafo $G^c=(V,A^c)$ donde $A^c=\{(u,v)\:|(u,v)\notin A,u\neq v\}$

¿Qué complejidad tendría un algoritmo para calcular el grafo complementario de un grafo dirigido representado mediante listas de adyacentes si el grafo tiene $V$ vértices y $A$ aristas?

Para calcular la lista de adyacentes asociada al vértice $u$ en el grafo $G^c$ podemos recorrer la lista $G[u]$ añadiendo a la primera los vértices que no estén en la segunda, lo que puede hacerce con un coste en $O(V)$ (utilizando un vector de booleanos de tamaño 
$V$, por ejemplo). Como hay $V$ vértices, el coste total está en $O(V^2)$.

4. Dado el siguiente grafo dirigido,
![alt text](/MARP/Assets/testGrafoDirigido2.png)

El grafo tiene ciclos por lo que no existe ninguna ordenación topológica de sus vértices.

5. ¿Cuáles de las siguientes permutaciones son ordenaciones topológicas de este grafo?

![alt text](testGrafoDirigido3.png)
- Falso. El vértice 0 no puede aparece antes que el vértice 2 ya que existe la arista 2 → 0.
- Falso. El vértice 0 no puede aparece antes que el vértice 5 ya que existe la arista 5 → 0.
- Cierto. Todas las aristas unen un vértice con otro posterior en la secuencia.
- Cierto. Todas las aristas unen un vértice con otro posterior en la secuencia.

6. ¿Cuántas aristas (sin contar autoaristas o aristas repetidas) puede tener como máximo un grafo dirigido de 7 vértices?

Pueden existir aristas de cada vértice a todos los demás. Si el grafo tiene $V$ vértices, el número máximo de aristas es $V*(V-1)$. Con 7 vértices puede haber 42 aristas distintas.

7. ¿Cuántas ordenaciones topológicas distintas puede tener como máximo un grafo dirigido con 7 vértices?

Si el grafo no tiene aristas todas las posibles ordenaciones de sus vértices son ordenaciones topológicas válidas. Es decir, las $V!$ permutaciones de sus vértices son válidas. Con 7 vértices puede haber 5040.

8. Dado un grafo dirigido implementado con listas de adyacencia, ¿cuál sería el coste de un algoritmo eficiente que busque un vértice con grado de entrada máxima, es decir, con grado de entrada $V-1$?

- Falso. Incorrecta. Es $O(A+V)$
- Falso. Incorrecta. Es $O(A+V)$
- Cierto. Para encontrar un nodo con grado de entrada $V-1$, tenemos que rerocrrernos todas las listas de adyacencia de cada vértice para ver si algún vértice aparece $V-1$ veces. Por lo tanto el coste es $O(A+V)$
- Falso. La respuesta correcta es $O(A+V)$

9. ¿En qué orden se visitarían los vértices de este grafo dirigido si realizamos un recorrido en profundidad del grafo completo? Escribe los identificadores de los vértices separados por espacios en el orden en que son visitados. Supón que los vértices en las listas de adyacentes están ordenados de menor a mayor, y que los vértices iniciales que hagan falta también se prueban en orden.

![alt text](/MARP/Assets/testGrafoDirigido4.png)

Los vértices se recorren en este orden: 0 3 2 7 1 4 6 5.

10. En un grafo dirigido, para encontrar el camino más corto (con menos aristas) entre dos vértices se utiliza

La búsqueda en anchura, al ir recorriendo los vértices por distancias crecientes desde el origen, garantiza que encuentra el camino con menos aristas.