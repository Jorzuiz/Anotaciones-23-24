# 4 Grafos no dirigidos y sus recorridos
Objetivos:
- Conocer el TAD de los grafos no dirigidos y cómo pueden utilizarse para modelar aplicaciones.

- Aprender un patrón de diseño para resolver problemas sobre grafos de forma independiente a su representación.

- Conocer el recorrido en profundidad de grafos no dirigidos y utilizarlo para resolver problemas sobre grafos como la alcanzabilidad entre vértices, o detectar componentes conexas, entre otros.

- Conocer el recorrido en anchura de grafos no dirigidos y cómo se utiliza para encontrar caminos mínimos desde un origen.

## 4.1 Grafos no dirigidos
Los grafos son una herramienta para modelar problemas en los que tenemos elementos, representados por vértices en el grafo, y conexiones uno a uno entre ellos, representadas por las aristas. Los grafos pueden ser dirigidos (cuando las aristas están orientadas) o no, y pueden ser valorados (cuando las aristas tienen asociado un valor) o no. Esta semana nos centramos en los grafos no dirigidos y no valorados.
![alt text](/MARP/Assets/grafoNoDirigido.png)

El siguiente vídeo presenta los grafos no dirigidos y cómo pueden representarse en memoria con el objetivo de poder resolver eficientemente problemas de procesamiento de grafos:

- Video de apuntes - https://www.youtube.com/watch?v=Mql9tPi0uAI&feature=youtu.be


>Código de [Grafo.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/1ed2239c08e2bc11f14e6932349eeee3323ca064/MARP/Practicas-MARP/Grafo.h)

Extiende la clase Grafo (implementada mediante listas de adyacentes, como en el fichero anterior) con un nuevo método hayArista que sirva para averiguar si existe una arista que conecte dos vértices dados. ¿Qué coste tiene esta nueva operación?
>Solucion [hayArista.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/main/MARP/Practicas-MARP/hayArista.h)

En el vídeo se habla también de la representación de un grafo mediante una matriz de adyacencia. Aunque no sea la representación más útil en general, hay ocasiones en que sí es la representación más apropiada. Implementa la clase Grafo utilizando una matriz de adyacencia. ¿Qué coste tienen todas las operaciones del TAD con esta representación?

>Solucion [matrizAdyacencia.h](https://github.com/Jorzuiz/Anotaciones-23-24/blob/main/MARP/Practicas-MARP/matrizAdyacencia.h)


## 4.2 Recorrido en profundidad
El recorrido en profundidad de un grafo explora todos los vértices alcanzables desde un vértice origen. Se puede pasar de un vértice a otro si estos son adyacentes, es decir, existe una arista que los conecta. El recorrido en profundidad imita en cierto sentido una estrategia para resolver un laberinto, donde vamos avanzando mientras podemos desenrollando una cuerda, hasta que llegamos a un sitio sin salida o desde donde podemos llegar solamente a posiciones ya visitadas. En ese caso toca retroceder recuperando la cuerda, hasta una posición donde haya otro camino no explorado. Esta estrategia garantiza que si la salida es alcanzable desde la entrada, la encontramos.

El recorrido en profundidad de un grafo, que se implementa sencillamente de manera recursiva, puede utilizarse para resolver muchos problemas sobre grafos. El siguiente vídeo muestra cómo funciona el recorrido en profundidad utilizando un ejemplo, y utiliza el recorrido para encontrar caminos desde un vértice origen a todos los vértices conectados a él.

- Video apuntes - https://www.youtube.com/watch?v=W5y3KFz5Pu4

> Un árbol libre es un grafo no dirigido, conexo y acíclico, es decir, donde todo par de vértices está conectado exactamente por un camino. El problema 11  Árboles libres del juez automático propone averiguar, dado un grafo, si es árbol libre o no. El problema puede resolverse de manera sencilla utilizando un recorrido en profundidad del grafo.

En el siguiente vídeo se resuelven de forma muy similar dos problemas que en principio pueden parecer bastante diferentes (dado un grupo de personas saber cuál es el tamaño del grupo más grande de amigos y dada una imagen como matriz de píxeles blancos y negros averiguar el tamaño de la mancha negra más grande) utilizando grafos y un algoritmo basado en un recorrido en profundidad del grafo.

- Video apuntes - https://www.youtube.com/watch?v=JZmIjOpvyEQ

> Los problemas 12  Los amigos de mis amigos son mis amigos y 13  Detección de manchas negras del juez automático corresponden a los problemas resueltos en el vídeo anterior. Puedes probar ahí tu propia solución.

## 4.3 Recorrido en anchura
El recorrido en anchura de un grafo desde un vértice origen también lo explora siguiendo caminos, pero de tal forma que se garantiza que la primera vez que se alcanza un vértice se ha seguido un camino de longitud mínima, es decir, que utiliza el menor número de aristas. El siguiente vídeo muestra su funcionamiento a través de un ejemplo y muestra cómo se puede implementar utilizando una cola.

- Video apuntes - https://www.youtube.com/watch?v=bcTsV94Lg1I

La página web [The Oracle of Bacon](https://oracleofbacon.org/) contiene un juego que consiste en comenzar con un actor o actriz y conectarlo con Kevin Bacon en el menor número de pasos. Dos actores están conectados directamente si han participado en la misma película. El menor número de películas por las que hay que pasar para conectar a un actor con Kevin Bacon se conoce como el número de Bacon de ese actor. Por ejemplo, Woody Allen tiene un número de Bacon de 2, como muestra la siguiente imagen:
![Alt text](/MARP/Assets/recorridoAnchura.png)

De hecho el grafo es un grafo bipartito, donde los vértices representan actores (o actrices) o películas. Cada actor está conectado mediante aristas con todas las películas en las que ha participado (por lo que no hay aristas entre actores o entre películas, lo que hace que el grafo sea bipartito). Para encontrar el número de Bacon de un actor obviamente hay que realizar un recorrido en anchura. Actualmente el grafo tiene unas 128.000 películas y unos 358.000 actores o actrices. ¡Y es difícil encontrar actores que tengan un número de Bacon mayor que 3!

## Test Semana 3
1. Hemos visto en $IndexPQ$ una implementación de colas con prioridad variable que hace uso de un vector de pares $< elemento, prioridad >$ y un vector de posiciones de esos elementos.

> Imagina que modificamos esta implementación eliminando el vector de posiciones.
- Cierto. El montículo está ordenado según prioridades, no elementos, eso quiere decir que para modificar la prioridad de un elemento, antes, hay que encontrarlo. Como el elemento puede estar en cualquier posición hay que recorrer todos los elementos.
- Falso. Incorrecta. Sigue siendo logarítmica, flotamos un elemento ya encontrado.
- Falso. Incorrecta. Por ejemplo, modificar la prioridad (update) pasa a tener coste lineal.
- Falso. La respuesta correcta es: Modificar la prioridad (update) pasa a tener coste lineal.

2. ¿Cuál es el coste de la operación de eliminar el elemento más prioritario (pop) vista en IndexPQ?
- Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
- Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
- Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
- Cierto. La respuesta correcta es: $O(logN)$

3. La función
```c++   
void funcion(vector<int> & v) {
      for (int i = v.size() - 1; i > 0; --i) {
         flotar_max(v, v.size(), i);
      }
   }
```
Mueve los elementos del vector, pero no lo convierte necesariamente en un montículo.
n vector puede convertirse en un montículo de dos maneras distintas:

- Recorriendo los elementos de izquierda a derecha y flotando cada elemento entre los anteriores (ya procesados), o
- Recorriendo la primera mitad de los elementos de derecha a izquierda, hundiendo cada elemento entre los siguientes, que ya forman montículos.

Aquí se han mezclado las dos ideas, lo que no garantiza que el resultado final sea un montículo, aunque haya elementos que cambien de lugar.

4. El coste de una implementación eficiente de un algoritmo de ordenación basado en comparaciones de elementos (como son por ejemplo heapsort, mergesort, etc) es $O(N\:logN)$

No se puede hacer un algoritmo de ordenación basado en comparaciones con coste inferior a $O(N\:logN)$ y los ejemplos que hemos puesto son algoritmos con coste en $O(N\:logN)$.

5. Dado un vector ordenado de menor a mayor, ¿cuál es el coste de convertirlo en un montículo de máximos?

Sí que se puede convertir en un montículo de máximos. Ahora bien, si el vector está ordenado de menor a mayor, cada elemento (en la primera mitad del vector) es menor que todos los siguientes por lo que tendrá que ser ser hundido hasta una hoja. Esto quiere decir que el coste será de $O(N)$.

6. Para ordenar un vector de enteros usando la idea de heapsort no se puede implementar usando colas de prioridad, es necesario usar montículos.

Falso. Se puede usar una cola de prioridad a cambio hay que pagar el uso extra en memoria de esa cola, ya que no podemos reutilizar el vector inicial también como cola de prioridad.

7. Cuando en un montículo de mínimos cambiamos la prioridad de un elemento a un valor menor, el elemento tiene que ser flotado (intercambiado con su padre mientras este sea mayor).

Verdadero. Al ser un montículo de mínimos, los elementos menores se acercan a la raíz.

8. ¿Cuál es el coste de la operación de añadir un nuevo elemento (push) vista en IndexPQ?

- Falso. Incorrecta. Es logarítmica, ya que flotar es logarítmico
- Falso. Incorrecta. Es logarítmica, ya que flotar es logarítmico
- Cierto. Al añadir un nuevo elemento, éste debe flotarse hasta encontrar su lugar y flotar es logarítmica
- Falso. La respuesta correcta es: $O(N\:logN)$

9. Para ordenar un vector de mayor a menor utilizando el método heapsort (con un coste en espacio adicional constante), primero el vector tiene que convertirse en un montículo de máximos.

Falso. Si convertimos, sobre sí mismo, el vector en un montículo de máximos, el primer elemento en salir sería el mayor, y dejaría libre una posición al final del vector. Pero si queremos ordenar de mayor a menor, ahí debería ir el menor elemento. Esta estrategia no ordena como queremos. El vector debería convertirse en un montículo de mínimos.

10. Considerando el TAD de colas con prioridades variables implementado en la clase IndexPQ visto, ¿cuál de estas operaciones tiene un coste lineal?

- Falso. Incorrecta. Es logarítmica, ya que hundir es logarítmico.
- Falso. Incorrecta. Es logarítmica, ya que tanto flotar como hundir son logarítmicos.
- Falso. Incorrecta. Es constante, basta consultar el tamaño del array.
- Cierto. La respuesta correcta es: La constructora, es decir, crear una cola vacía

## Diapositivas Grafos No Dirigidos

Los grafos sirven para representar elementos y conexiones uno a uno entre
ellos.

|aplicación|elemento|conexión|
|---|---|---|
|mapa|intersección|calle,carretera|
|internet|subred clase C|cable red|
|web|página|enlace|
|red social|persona|amistad|
|juego|estado del tablero|movimiento legal|
|circuito|puerta lógica, transistor|cable|
|red de metro|estación|vía|

Un grafo es un conjunto de vértices y un conjunto de aristas que conectan pares de vértices.

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos1.png)

|problema|descripción|
|---|---|
|camino s-t|¿Existe un camino entre s y t?|
|camino más corto s-t|¿Cuál es el camino más corto (menos aristas) entre s y t?|
|grafo conexo|¿Existe un camino entre todo par de vértices?|
|ciclo|¿Existe un ciclo en el grafo?|
|ciclo euleriano|¿Existe un ciclo que utiliza cada arista del grafo exactamente una vez?|
|ciclo hamiltoniano|¿Existe un ciclo que pasa por cada vértice del grafo exactamente una vez?|
|grafo bipartido|¿Se pueden repartir los vértices en dos conjuntos de tal forma que las aristas
siempre conecten vértices en conjuntos distintos?|
|grafo planar|¿Puede dibujarse el grafo en un plano sin que haya aristas que se crucen?|
|grafos isomorfos|¿Existe un isomorfismo entre los grafos?|

En general, los nombres de los vértices no son importantes, pero hay que distinguirlos. Los numeramos de 0 a V – 1
Un dibujo del grafo nos da intuición sobre su estructura, pero a veces confunde.

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos2.png)

El TAD de los grafos cuenta con las siguientes operaciones:

```c++
Grafo(int V);
void ponArista(int v, int w);
Adys ady(int v) const;  // Consultar los adyacentes a un vértice
int V() const;  // Número de vértices
int A() const;  // Número de aristas

int grado(Grafo const& g, int v) {
    int grado = 0;
    for (int w : g.ady(v))
        ++grado;
    return grado;
}

int aristas(Grafo const& g) {
    int aristas = 0;
    for (int v = 0; v < g.V(); ++v)
        aristas += grado(g, v);
    return aristas / 2;
}
```

Los grafos se pueden implementar de varias maneras:
1. Matrid de adyacencia por booleanos

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos3.png)

Usa una tabla para consultar con valores true/false las conexiones, la tabla es simétrica diagonalmente y aunque 

```c++
int grado(Grafo const& g, int v);   // O(V)
int aristas(Grafo const& g);        // O(V²)
```

2. Lista de Adyacentes

Un vector guarda vectores que contienen cada una una lista de conexiones a los otros nodos

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos4.png)

```c++
int grado(Grafo const& g, int v);   // O(V)
int aristas(Grafo const& g);        // O(V+A)
```

En la práctica se usan listas adyacentes y pueden llegar a ser dispersos

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos5.png)

|representación|espacio|añadir arista v-w|comprobar si v y w son adyacentes|recorrer los vñertices adyacentes a v|
|---|---|---|---|---|
|matriz de adyacencia|V²|1|1|V|
|listas adyacentes|V+A|1|grado(V)|grado(V)|
|conjuntos de adyacentes|V+A|log V|log V|grado(V)|
|lista de aristas|A|1|A|A|

```c++
using Adys = std::vector<int>; // lista de adyacentes a un vértice
class Grafo {
    private:
    int _V; // número de vértices
    int _A; // número de aristas
    std::vector<Adys> _ady; // vector de listas de adyacentes
public:
    Grafo(int V) : _V(V), _A(0), _ady(_V) {}
    int V() const { return _V; }
    int A() const { return _A; }
    void ponArista(int v, int w) {
    if (v < 0 || v >= _V || w < 0 || w >= _V)
        throw std::domain_error("Vertice inexistente");
    ++_A;
    _ady[v].push_back(w);
    _ady[w].push_back(v);
    }
    Adys const& ady(int v) const {
    if (v < 0 || v >= _V)
        throw std::domain_error("Vertice inexistente");
    return _ady[v];
    }
};
```

### Patrón de diseño
Para cada problema sobre grafos que resolvamos crearemos una clase específica, Problema.
Generalmente, el constructor realizará cierto trabajo sobre el grafo y creará estructuras para contestar eficientemente a las preguntas del problema.
El usuario creará un grafo, después creará un objeto de la clase Problema pasándole el grafo como argumento a la constructora, y por último utilizará los métodos de consulta de esta clase para averiguar propiedades del grafo.

```c++
class Conexion {
    public:
    Conexion(Grafo const& g, int s); // Busca vértices conectados a s
    bool conectado(int v) const; // ¿está v conectado a s?
    int cuantos() const; // ¿cuántos vértices están conectados a s?
};

void resuelve(Grafo const& g, int s) {
    Conexion conex(g,s);
    cout << "Vértices conectados a " << s << ":";
    for (int v = 0; v < g.V(); ++v) {
        if (v != s && conex.conectado(v))
            cout << ' ' << v;
    }
    cout << '\n';
    
    if (conex.cuantos() != g.V()) cout << "no ";
    cout << ”es conexo\n";
}
```

Un grafo puede ser no conexo si su recorrido está separado

![Alt text](/MARP/Assets/diaposGrafosNoDirigidos6.png)

## Recorridos en Profundidad

Los recorridos son los caminos que unen diferentes nodos de los grafos, estos se exploran recorriendo los vertices y sus aristas.
Un recorrido en profundidad imita la resolución de un laberinto.
Se usa un algoritmo recursivo que recorre los vértices.
La visita de un vñertice consiste en:
1. Marcarlo como visitado
2. Realizar una acción
3. Visitar de manera recursiva los adyacentes no visitados

```c++
class CaminosDFS {
    private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    int s; // vértice origen
    void dfs(Grafo const& G, int v) {
    visit[v] = true;
    for (int w : G.ady(v)) {
        if (!visit[w]) {
            ant[w] = v;
            dfs(G, w);
        }
    }
}
public:
    CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
    ant(g.V()), s(s) {
    dfs(g, s);
}
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
}
```