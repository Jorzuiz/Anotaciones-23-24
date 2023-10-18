/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * MARP31 Manuel Prada
  * MARP51 Jorge Zurdo Izquierdo
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "..\indexPQ.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

IndexPQ<string> twitter;

bool resuelveCaso() {

    int numEventos;
    cin >> numEventos;

    if (!cin)
        return false;
    
    char accion;
    string tema;    int puntos;

    for (int i = 0; i < numEventos; i++)
    {
        cin >> accion;
        cin >> tema >> puntos;
        if (accion = 'C') //Inserta
            twitter.push(puntos, tema);
        else if (accion = 'E') { //Elimina
            twitter.update(puntos, tema);
            if(twitter.top().elem < 1)
                twitter.pop();
        }
        //else if (accion = 'TC')
            //cout << twitter.top().elem;
    }

    // leer el resto del caso y resolverlo



    cout << "---\n";
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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
