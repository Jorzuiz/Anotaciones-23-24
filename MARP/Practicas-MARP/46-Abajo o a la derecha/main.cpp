
/*@ <authors>
 *
 *  Jorge Zurdo Izquierdo
 *  MARP51
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"

using namespace std;


/*@ <answer>

El problema usa una implementación de programación dinámica, busca por fuerza bruta todas las posibles combinaciones
purgando de manera selectiva las que memoriza como solución de manera previa.
El coste peor es de dimensiones O(N*M) en caso de ser una matriz de 1s completa, puesto que tendria quer ecorrerse cada casilla al menos una vez.
Los registros permiten que SOLO se recorra cada avance una vez, sumando los posibles avances por otros lados, evitando redundancia.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

int cuentaSaltos(Matriz<int>& matrix, Matriz<int>& marcas, const int N, const int M) {
   
    // Iniciamos el salto
    marcas[0][0] = 1;

    // Avanzamos por la matriz produciendo los saltos y registrandolos en la matriz de marcas
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {

            int salto = matrix[i][j];

            // Avance hacia la derecha
            if (i + salto <= N) {
                marcas[i + salto][j] += marcas[i][j];
            }

            // Avance hacia abajo
            if (j + salto <= M) {
                marcas[i][j + salto] += marcas[i][j];
            }
        }
    }

    // La ultima casilla guardará el salto acarreado de los anteriores
    return marcas[N][M];
}



bool resuelveCaso() {
  
  // leemos la entrada
  int N, M;
  cin >> N >> M;
  
  if (!cin)
    return false;

  // leer el resto del caso y resolverlo
  
  Matriz<int> m(N,M);
  for (int i = 0; i < N; i++)
  {
	  for (int j = 0; j < M; j++)
	  {
		  cin >> m[i][j];
	  }
  }
  m;

  Matriz<int> marcas(N, M, 0);
  cout << cuentaSaltos(m, marcas, N-1, M-1) << "\n";
  
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
