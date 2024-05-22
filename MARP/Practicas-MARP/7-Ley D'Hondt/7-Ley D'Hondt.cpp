/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * MARP51 Jorge Zurdo Izquierdo
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "../PriorityQueue.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

 // 5 4                <- 5 Candidaturas (int C) 4 escanyos (Int E) 
 // 100 226 20 80 170  <- 100 votos a candidatura 1, 226 a candidatura 2, etc..
 // 3 3
 // 60 28 60
 // 0 0                <- Caso de parada

struct partido {
    int coeficiente;
    int votos;
    int escanyos;
    int indice;


};

bool operator<(partido const& a, partido const& b) {
    // La asignación de cada escaño se rige por el coeficiente c_k=v_k/(e_k+1)
    // En caso de empate en el coeficiente se elige la de mayor votos
    // En caso de otro empate se elige la de índice menor

    return a.coeficiente < b.coeficiente ||
        (a.coeficiente == b.coeficiente && a.votos < b.votos) ||
        (a.coeficiente == b.coeficiente && a.votos == b.votos && a.indice < b.indice);
}



void asignaescanyos(int escanyos, priority_queue<partido>& partidos) {
    while (escanyos > 0) {
        partido actual = partidos.top();
        actual.escanyos++;
        //partidos.pop();
        actual.coeficiente = actual.votos / (actual.escanyos + 1);
        escanyos--;
    }
}

bool resuelveCaso() {

    // leemos la entrada
    int C, N;
    cin >> C >> N;

    if (C == 0)
        return false;

    // leer el resto del caso y resolverlo
    // La inicializacion de escanyos por candidatura es de 0 por defecto (e_k=0)
    priority_queue<partido> partidos;

    for (int i = 0; i < C; i++)
    {
        int votos;
        cin >> votos;
        partidos.push({ 0, votos, 0, i });
    }
    asignaescanyos(N, partidos);
    vector<int> asignados;
    asignados.resize(N + 1);
    while (!partidos.empty()) {
        partido actual = partidos.top();
        asignados[actual.indice] = actual.escanyos;
        partidos.pop();
    }

    for (int i = 0; i < N + 1; i++)
    {
        cout << asignados[i];
    }
    cout << "\n";


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
    system("PAUSE");
#endif
    return 0;
}
// 7-Ley D'Hondt.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}