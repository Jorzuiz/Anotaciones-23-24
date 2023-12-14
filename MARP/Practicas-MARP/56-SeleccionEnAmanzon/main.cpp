
/*@ <authors>
 *
 * Jorge Zurdo Izquierdo Marp 51
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"

/*@ <answer>

Como espcio adicional usaremos el vector parciales que almacenará las n posibles combinaciones en un espacio de O(n+1)


 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

long long formasDePagar(int cantidadMonedas, const vector<int>& monedas) {

    // Matriz de soluciones parciales, cada columna es una manera de pagar diferente con I monedas
    Matriz<long long> parciales(monedas.size() + 1, cantidadMonedas + 1, 0);

    // Caso base en la primera columna, solo se puede pagar de 1 manera con 0 monedas
    for (int i = 0; i <= monedas.size(); ++i) {
        parciales[i][0] = 1;
    }

    for (int i = 1; i <= monedas.size(); ++i) {
        for (int j = 0; j <= cantidadMonedas; ++j) {
            parciales[i][j] = parciales[i - 1][j];

            if (j >= monedas[i - 1]) {
                parciales[i][j] += parciales[i][j - monedas[i - 1]];
            }
        }
    }

    // cout << "Matriz de soluciones parciales:" << endl;
    // cout << parciales << endl;

    return parciales[monedas.size()][cantidadMonedas];
}

bool resuelveCaso() {
  
  int C, N;
  cin >> C >> N;
  if (!cin)
    return false;

  // leer el resto del caso y resolverlo
  vector<int> monedas(N);
  for (int i = 0; i < N; i++)
      cin >> monedas[i];

  cout << formasDePagar(C, monedas) << "\n";
  
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
