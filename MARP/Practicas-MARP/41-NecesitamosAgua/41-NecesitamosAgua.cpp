
/*@ <authors>
 *
 * MARP 51 Jorge Zurdo Izquierdo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "../DigrafoValorado.h"
#include "../indexPQ.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>


template <typename Valor>
class Dijkstra {
public:
    // Crea el recorrido de caminos minimos dado un Digrafo
    // Los carga en arista y las relaja
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {

        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

    int nodoDistancia(int d) const {
        int numNodosDistancia = 0;
        for (int v = 0; v < dist.size(); v++) {
            if (dist[v] <= d) {
                numNodosDistancia++;
            }
        }
        return numNodosDistancia;
    }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;

    // Actualiza la arista mas corta conocida usando los 2 valores
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};


struct Carretera {
    int tiempo;
    int id;
};

bool operator>(Carretera a, Carretera b) {
    return a.tiempo > b.tiempo;
}

// las tareas están ordenadas de mayor a menor beneficio
// La mitad de camiones salen de la arista 1 y la otra mitad de la arista N (N/2 camiones)
int resolver(vector<Carretera> const& tareas, DigrafoValorado<int> isla, vector<int>& sol) {
    int N = tareas.size(); // número de tareas
    int busA = (N - 2) / 2, busB = (N - 2) / 2;
    Dijkstra<int> plantaA(isla, 1); // Caminos minimos desde A
    Dijkstra<int> plantaB(isla, N); // Caminos minimos desde B
    
    
    // ordenar las diferencias entre los valores de los caminos
    DigrafoValorado<int> caminos(N);
    for (int i = 0; i<N;i++)
    {
        caminos.ponArista({isla[i],isla.ady(i), abs(plantaA.distancia(i)- plantaB.distancia(i))});
    }

    /*
    vector<int> libre(N + 1, 0);
    for (int i = 0; i <= N; ++i)
        libre[i] = i;
    vector<int> plan(N + 1); // 0 es que no está usado
    ConjuntosDisjuntos particion(N + 1);
    int beneficio = 0;
    // recorrer las tareas de mayor a menor beneficio
    for (int i = 0; i < N; ++i) {
        int c1 = particion.buscar(min(N, tareas[i].plazo));
        int m = libre[c1];
        if (m != 0) { // podemos colocar la tarea i
            plan[m] = tareas[i].id;
            beneficio += tareas[i].tiempo;
            int c2 = particion.buscar(m - 1);
            particion.unir(c1, c2);
            libre[c1] = libre[c2];
        }
    }// compactamos la solución
    for (int i = 1; i <= N; ++i) {
        if (plan[i] > 0)
            sol.push_back(plan[i]);
    }
    return beneficio;*/
}



bool resuelveCaso() {

    // Entrada n, pueblos, m carreteras
    int N, M;
    cin >> N >> M;

    if (!cin)
        return false;

    // leer el resto del caso y resolverlo
    int p1, p2, dist;
    DigrafoValorado<int> isla(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> p1 >> p2 >> dist;
        isla.ponArista({p1,p2,dist});
    }

    resolver(isla);

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
