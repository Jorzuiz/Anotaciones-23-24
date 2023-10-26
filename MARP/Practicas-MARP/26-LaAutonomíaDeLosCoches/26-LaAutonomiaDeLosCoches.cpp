
/*@ <authors>
 *
 * Jorge Zurdo Izquierdo MARP 51
 *
 *@ </authors> */

#include <iostream> // Input/Output
#include <fstream>  // File Stream
#include <vector>
#include <algorithm>

using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

/*@ <answer>
* 
//  Emplearemos una modificacion al algoritmo de Kruskal que en vez de almacenar el valor del coste minimo del arbol completo,
//  irá actualizando el coste de la arista más grande segun la registra.
//  su valor será el del propio algortimo de Kruskal 0(A log A) sindo A el número de aristas y con un espacio adicional de 0(A)
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// Se ha modificado el algoritmo de kruskal, 
template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor maxCoste;
public:
    Valor costeMAX() const {
        return maxCoste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : maxCoste(0) {

        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                if (a.valor() > maxCoste) {  // Actualiza el coste de la arista mayor encontrada hasta ahora
                    maxCoste = a.valor();
                }
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    int ciudades, carreteras;
    std::cin >> ciudades >> carreteras;
    
    GrafoValorado<int> grafo(ciudades);

    int origen, destino, distancia;
    for (int i = 0; i < carreteras; i++)
    {
        cin >> origen >> destino >> distancia;
        grafo.ponArista({ origen - 1, destino - 1, distancia });
    }

    ARM_Kruskal<int> mst(grafo);

    // escribir la solución
    if (carreteras == 0) cout << 0 << endl;
    else if (mst.costeMAX() == 0 || mst.ARM().size() < ciudades - 1 )
        cout << "Imposible" << endl;
    else cout << mst.costeMAX() << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
