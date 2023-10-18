# Tema 2 Ficheros
En una tabla indexada las coordenadas i (vertical) y J (Horizontal) son

$i = \frac{J}{M} \qquad j=J mod M$

Los bloques directos almacenan bloques hasta llegar a los bloques de indireccion, los cuales almacenan de manera indirecta $N$ bloques donde $N = \frac{\text{Tamaño del bloque}}{\text{Tamaño de direccion}}$ 