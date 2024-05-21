# 1 Árboles de búsqueda avanzados

Objetivos:

- Reconocer el problema de coste en el caso peor de las operaciones de los árboles binarios de búsqueda, cuando estos son degenerados.
- Conocer los árboles AVL (árboles binarios de búsqueda autoequilibrados) y sus ventajas.
- Utilizar los AVL para implementar de forma eficiente el TAD de los conjuntos (de elementos ordenables).

## 1.1 Árboles Binarios de Búsqueda (BST)

Conocemos, de la asignatura Estructuras de Datos y Algoritmos de segundo curso, que las operaciones de búsqueda, inserción o borrado en un árbol binario de búsqueda comparan un elemento con la raíz del árbol y van pasando, recursivamente, al hijo izquierdo o al hijo derecho, hasta encontrar en el árbol el elemento o llegar a un árbol vacío. Por tanto, estas operaciones tienen un coste en el caso peor proporcional a la altura del árbol. Si tenemos mala suerte, puede que la altura del árbol crezca en cada inserción, construyéndose un árbol degenerado que tiene una altura proporcional al número de nodos.

- Video [Repaso ABB y costes](https://www.youtube.com/watch?v=ehj9Ns8ucKc)

:godmode: Busqueda: Linear en el peor caso, proporcional a la altura. Se recorre el árbol hasta encontrar el elemento o llegar a una hoja.
> Insercion: Igual que busqueda, puede modificar altura. 
> Eliminación: Lineal, proporcional a la altura. Se borra de diferentes maneras en base al tipo de nodo.

Apuntes de ED

- Introduccion - https://www.youtube.com/watch?v=RDxSW4j3iGw&feature=youtu.be
- Insercion - https://www.youtube.com/watch?v=jqqeKBskGuw&feature=youtu.be
- Eliminación - https://www.youtube.com/watch?v=jClulLAZYcA&feature=youtu.be

## 1.2 Árboles AVL
Los árboles AVL solucionan el problema con los costes en el caso peor cuando el árbol es degenerado, al mantener el árbol equilibrado: todos los nodos cumplen que la diferencia de alturas entre sus hijos es como mucho 1. Como consecuencia de esto, la altura del árbol es logarítmica respecto a su número de nodos, lo que hace que las operaciones de búsqueda, inserción y borrado (y otras, como calcular el menor elemento del árbol) tengan un coste en el caso peor proporcional al logaritmo del número de nodos, que está muy bien.

- Vídeo de apuntes - https://www.youtube.com/watch?v=ehj9Ns8ucKc
Un árbol AVL es un BST que mantiene diferencia de altura entre sus hijos de como mucho 1.
La altura es proporcional al logaritmo del número de nodos. $Nodos(h)=Nodos(h-1)+Nodos(h-2)+1$ $Nodos(0)=0$ $Nodos(1)=1$

## 1.3 Implementación del TAD de los conjuntos mediante un árbol AVL
Los árboles binarios de búsqueda son una muy buena opción para implementar el TAD de los conjuntos (con operaciones para añadir o eliminar elementos, y consultar si un elemento pertenece o no al conjunto) cuando además queremos poder recorrer los elementos del conjunto de manera ordenada, por ejemplo, de menor a mayor, o necesitamos otras operaciones que tengan que ver con el orden entre los elementos, como conocer el menor elemento del conjunto.
- Video de apuntes - https://www.youtube.com/watch?v=of1dbhM3hFU

## 1.4 Otros árboles autoequilibrados (opcional)
Existen otros tipos de árboles de búsqueda que se mantienen equilibrados en el sentido de que su altura se mantiene siempre proporcional al logaritmo del número de nodos. Algunos de ellos son:
- Árboles rojinegros - https://en.wikipedia.org/wiki/Red–black_tree
- Árboles 2-3 - https://en.wikipedia.org/wiki/2–3_tree
- Árboles biselados - https://en.wikipedia.org/wiki/Splay_tree

## Test de control y respuestas

1. El coste de obtener el máximo de un AVL con N nodos está en O(logN)

Para buscar el máximo hay que bajar por el árbol siempre hacia la derecha hasta que no se pueda más. En el caso peor habría que bajar la altura del árbol, y como el árbol es equilibrado, esta es proporcional al logaritmo del número de nodos.

2. Si en el árbol AVL eliminamos el valor 20 se produce una rotación simple a la derecha

![alt text](.\Assets\testAVL1.png)

Tras eliminar el valor 20 el nodo con valor 17 pierde la condición de equilibrio, y hace falta una rotación simple a la derecha para restablecerla. Tras la rotación el árbol queda equilibrado.

3. El subárbol T de altura ℎ Tiene que tener una altura 1-2 y cualquier elemento entre 13 y 44

![alt text](.\Assets\testAVL2.png)

En tanto que árbol de búsqueda, cualquier elemento $e$ de T ha de cumplir 13<$e$<44. Según la definición de árbol AVL, T debe ser AVL y su altura solo puede ser 1 o 2 para no desequilibrar el nodo 13. La condiciones de árbol AVL se cumplen en el resto de nodos, así que el árbol completo sí que puede ser AVL.

4. Al eliminar el nodo G se produce una rotación doble izquierda-derecha

![alt text](.\Assets\testAVL3.png)

Como resultado de la eliminación del nodo G, el nodo D queda desequilibrado y es necesario hacer una rotación doble izquierda-derecha para recolocar el árbol (que deja a F como nueva raíz del subárbol, con E y D como hijos izquierdo y derecho, respectivamente).

5. ¿Cuál de los siguientes árboles binarsion son AVL?

![alt text](.\Assets\testAVL4.png)![alt text](.\Assets\testAVL5.png)![alt text](.\Assets\testAVL6.png)![alt text](.\Assets\testAVL7.png)

- Cierto. Es un árbol binario de búsqueda correcto y está equilibrado.
- Falso. No es un árbol binario de búsqueda, al tener valores repetidos.
- Cierto. Es un árbol binario de búsqueda correcto y está equilibrado.
- Falso. No es un árbol binario de búsqueda correcto, al estar el valor 20 a la izquierda del 10.

6. Si en este árbol AVL eliminamos el valor 41 se producen 2 rotaciones (contando rotaciones dobles como una)

![alt text](.\Assets\testAVL8.png)

Tras eliminar el valor 41 el nodo con valor 43 pierde la condición de equilibrio, y hace falta una rotación simple a la izquierda para restablecerla. Eso hace que la raíz también se desequilibre, y haga falta una rotación doble izquierda-derecha para equilibrar el árbol.

7. Si en este árbol AVL insertamos el valor $n$ se deberá reequilibrar con rotaciones si $n$<26

![alt text](.\Assets\testAVL9.png)

Si se inserta un valor $n$<26, el nuevo nodo se colocará como hijo del nodo 9 y su padre 26 perderá la condición de equilibrio, por lo que será necesario realizar una rotación. En cambio, si se añade un valor 26<$n$<31, el nuevo nodo se ubicará como hijo derecho de 26 y no será necesario realizar ninguna rotación. Tampoco será necesario realizar rotación alguna si $n$>31, pues ningún nodo perderá la condición de equilibrio en tal caso.

8. Si al insertar consecutivamente los elementos 4 y 12 en el siguiente árbol AVL no se ha realizado ninguna rotación su valor es como mínimo 5

![alt text](.\Assets\testAVL10.png)

Como los valores a insertar (4 y 12) son menores que 19, tendrán que colocarse necesariamente como descendientes del nodo x. En función del orden relativo de x, 4 y 12 se dan tres situaciones posibles:

- Si 4<$x$<12, cada valor acaba a un lado de x y no se produce ninguna rotación.
- Si x es menor que 4, se necesita una rotación simple a izquierda para reequilibrar el nodo x.
- Si x es mayor que 12, se necesita una rotación doble izquierda-derecha para reequilibrar el nodo x.
En conclusión, se tiene que dar la primera de las situaciones para evitar una rotación y entonces el menor valor posible de x es 5.

9. Si se utiliza un árbol AVL para representar un conjunto, el recorrido en Inorde recorre de menor a mayor el conjunto

Al ser un árbol binario de búsqueda, el hijo izquierdo tiene valores menores que la raíz y el hijo derecho tiene valores mayores que la raíz. Y eso ocurre también de manera recursiva en los hijos. Por tanto, el recorrido en inorden, que recorre primero el hijo izquierdo en inorden, después la raíz, y después el hijo derecho en inorden, recorre los elementos de menor a mayor. El resto de recorridos no recorren los elementos en orden en todos los casos.

10. Tras insertar el valor 15, se produce una rtación doble izquierda-derecha

![alt text](.\Assets\testAVL11.png)

El nodo con el valor 25 es el nodo $a$ (el primero que no cumple la condición de equilibrio si vamos desde el nuevo nodo insertado hasta la raíz), y para equilibrarlo hace falta una rotación doble izquierda-derecha dando lugar al siguiente árbol

 ![alt text](.\Assets\testAVL12.png)


Arboles ordenados respecto a valores absolutos.
Complejidad de O(n) sobre la altura del arbol
Cuando se inserta o elimina un elemento se producen rotaciones respecto a la posición para mantener el orden.
Propiedades del proyexto c c++ 17/19 para poder poner anotacion en corchetes
Preorden (raiz, iz, dr)
Inorden (iz, raiz, dr)          Orden de menor a mayor
Postorden (Iz, dr, raiz)

```c++
if arbol.empty()
    return {true, 0, {}, T()};

else {
auto [avl_iz, alt_iz, min_iz, max_iz] = es_avl_rec(arbol.left());
auto [avl_dr, alt_dr, min_dr, max_dr] = es_avl_rec(arbol.right());

int alt = 1 +max(alt_iz, alt_dr):

T max = arbol.right().empty ? arbol.root :max_dr;
T max = arbol.left().empty ? arbol.root :max_iz;

bool avl = alv_iz && alv_dr && abs(alt_iz - alt_dr) <= 1 &&
(arbol.left().empty() || arbol.root() > max_iz) &&
(arbol.right().empty() || arbol.root() < max_dr);

return {avl, alt,  min, max};
}
```