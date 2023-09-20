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