
/*@ <authors>
 *
 * Jorge Zurdo Izquierdo, Marp51
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "Matriz.h"

/*@ <answer>

    Usa una modificacion del algoritmo de los patindromos para resolverse.
    En el algoritmo original usamos solo una lista de letras y comparamos por delante y detras,
    mientras que en nuestro algoritmo compararesmos ambas listas desde el principio.
    Los indices progresan desde el principio de cada lista [i,j] y evaluan todas las posibilidades en una tabla
    La solucion se reconstruye a partir de esa tabla

    El coste final es de O(N*M) dado que para construir la tabla se recorre los N elementos de una lista 
    y se comparan con los M elementos de la otra

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

// Calcula la longitud del mayor palindromo entre los indices i,j del vector original
// generando una tabla con todas las posible ssoluciones
int listaCanciones(vector<string> const& lista1, vector<string> const& lista2, int i, int j, Matriz<int>& sol) {

    if (i >= lista1.size() || j >= lista2.size()) return 0;

    int& res = sol[i][j];
    if (res == -1) {

        if (lista1[i] == lista2[j])        // Caso recursivo, los indices son iguales (Misma cancion)
            res = listaCanciones(lista1, lista2, i + 1, j + 1, sol) + 1;
        else                                    // Caso recursivo, canciones diferentes
            // Hacemos 2 llamadas recursivas, cada una avanzando por una lista diferente
            res = max(listaCanciones(lista1, lista2, i + 1, j, sol),
                listaCanciones(lista1, lista2, i, j + 1, sol));
    }

    return res;
}


// reconstruye en un acumulador la solucion de la lista de canciones mas larga
void reconstruir(vector<string> const& lista1, vector<string> const& lista2,  Matriz<int> const& sol, int i, int j, string& res) {
    while (i < lista1.size() && j < lista2.size()) {
        if (lista1[i] == lista2[j]) {
            res = res + ' ' + lista1[i];
            i++; j++;
        }
        else if (i + 1 < lista1.size() && j + 1 < lista2.size() && sol[i + 1][j] >= sol[i][j + 1])
            i++;
        else
            j++;
    }
}


vector<string> leerLista() {
    string linea;
    getline(cin, linea);
    if (!cin)
        return {};
    vector<string> sec;
    stringstream ss(linea);
    string pal;
    while (ss >> pal)
        sec.push_back(pal);
    return sec;
}


bool resuelveCaso() {

    // leemos la entrada
    auto lista1 = leerLista();
    if (!cin)
        return false;
    auto lista2 = leerLista();

    // resolver el caso

    string res;
    Matriz<int> sol(lista1.size(), lista2.size(), -1);
    listaCanciones(lista1, lista2, 0, 0, sol);
    reconstruir(lista1, lista2, sol, 0, 0, res);
    res.erase(0,1);
    cout << res << '\n';

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
