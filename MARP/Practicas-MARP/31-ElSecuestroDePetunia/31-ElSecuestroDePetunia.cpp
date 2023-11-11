
/*@ <authors>
 *
 * MARP 51 Jorge Zurdo Izquierdo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>

Utilizaremos el algoritmo de Dijkstra para evaluar los camino y encontrar los minmos
Luego realizamos una implementacion de un metodo que cuenta el numero de caminos minimos
El coste es el del algoritmo de Djikstra que evalua los nodos por tamaño ascendente (A logV)

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
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

bool resuelveCaso() {

    // leemos la entrada
    int Distancia, Pueblos, Carreteras;
    cin >> Distancia >> Pueblos >> Carreteras;

    if (!cin)
        return false;

    // lectura del grafo
    DigrafoValorado<int> digrafo(Pueblos);
    int p1, p2, dist;
    for (int i = 0; i < Carreteras; i++)
    {
        cin >> p1 >> p2 >> dist;
        digrafo.ponArista({ p1, p2, dist });
    }

    // lectura del vector de indices
    // Los indices se corresponde con los origenes sobre los que realizaremos la busqueda (Buscar los pueblos a distancia x de estos)
    vector<int> pueblosBorriquin;
    int Borriquin, aux;
    cin >> Borriquin;
    for (int i = 0; i < Borriquin; i++)
    {
        cin >> aux;
        pueblosBorriquin.push_back(aux);
    }

    // leer el resto del caso y resolverlo
    for (int i = 0; i < pueblosBorriquin.size(); i++)
    {
        Dijkstra<int> dijkstra(digrafo, pueblosBorriquin[i]);
        cout << dijkstra.nodoDistancia(Distancia) << endl;
    }

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
