# Redes Neuronales
Las redes neuronales surgen de las analogías entre la naturaleza y las invenciones humanas.
En los años 50 se comienza a intentar replicar el funcionamiento del cerebro humano en los primeros ordenadores sin demasiado éxito más allá del planteamiento.
En los años 80 se comienzan las primeras implementaciones con el algoritmo de propagación (Backpropagation).
El sistema nervioso controla los seres vivos y está compuesto de neuronas, las cuales replicaremos con nuestras redes artificiales.
Las neuronas están compuestas de Axiones que propagan los impulsos a otras neuronas y las dendritas que procesan las entradas de las neuronas, este proceso de intercomunicacion de las dendritas se llama *Sinapsis*.
De media el número de interconexiones en cada neurona es de unas 10000.
Intentar replicar eso en un sistema convencional es harto difícil.

Esta analogía es muy simple en comparación con la realidad del cerebro.

Una neurona es capaz de activarse y de modular la cantidad de "energía" que le llega mediante salidas a otras neuronas.
La función que nos indica la activación se llama *Función de Activación*.

Cada entrada de la neurona se pondera con un peso diferente que simula el funcionamiento de la sinapsis.
Esta idea se aplica en un tipo de red conocida como Perceptrón Multicapa

$\boxed{\text{Capa neuronal de entrada}}\rightarrow \boxed{\text{Capa/s oculta}} \rightarrow \boxed{\text{Capa de salida}} $

![Alt text](./Assets/neuralEsquema.png)

Cada una de estas conexiones se pondera con diferentes pesos, una neurona de la capa entrada puede conectarse con peso $0,1$ a la primera de la siguiente, $0,5$ a la segunda, $0,3$ a la tercera....
Cada set de neuronas está conectado con un set de pesos a la siguiente capa, si la primera capa tiene $N$ neuronas y la siguiente tiene $M$, entonces tenemos $N*M$ pesos.

Una red neuronal puede definirse como un vector de ecuaciones:
$$\vec{S}=F(F(F(\vec{X}*W_{1})*W_{2})\dots W_{i})$$
Si la función es lineal, añadir más capas de neuronas no cambiará el resultado, por lo que  puede ser sustituida con una capa simple, normalmente no lo suelen ser.

### Funciones de activacion

Funcion escalonada
$$y(x)=\begin{cases}1 \qquad \text{si}\quad x\geq \alpha \\ -1 \quad o \quad 0 \quad \text{si}\quad x\leq \alpha\end{cases}$$

## 3.3 Perceptrón Multicapa

Forward Propagation

![Alt text](./Assets/perceptron.png)

## How dows an ANN learn?

$a^2_3=a^{'}_1*\theta ^{'}_{3,1}+a^{'}_2*\theta^{'}_{3,1}$

```python
float a[1];
float a2[3];
float a3[1];
float Tetha1[3,2];
float Tetha2[1,2];

for c in a2 # para todas las neuronas de la capa 1
for j in a1
a[i]=ai[j]*t1[i,j]
```

Ciclo de propgacion
1. Carga los inputs en las neuronas
2. Propaga la red
3. Calcula el error
4. Calcula $\delta$ de cada conexión
5. calcula los pesos de inicio/final de la red
6. Almacena el error

### Ejemplo:

- Neuronas de Entrada 2
- Neuronas de capa oculta 2
- Neuronas de salida 2

Salidas esperadas 0.7 0.1

Pesos iniciales:
- $\theta_1$ 2x2 $[[0.1,0.2],[0.2,0.1]]$
- $\newline\theta_2$ 2x2 $[[0.2,0.3],[0.1,0.1]]$

Salida [0.5,0.4]


y = [0.7,0.1]

Y = [0.5,0.4]
$\newline a^3 a^3_1 a^3_2$
$\newline (a^3_1-y_1)*a^3_1(1-a^3_1)$

(0.5-0.7)*0.5*(1-0.5)= 0.05 = $\delta^3_1\newline$
(0.4-0.1)*0.4*(1-0.4)= 0,072 = $\delta^3_2\newline$
$\delta^3[-0.05,0.072]$ = Error

$\newline\delta^2_1=\delta^3_1*\theta^2_{1,1}*a^2_1*(1-a_1)+\delta^3_2*\theta^3_{1,2}*(a^2_1*)$