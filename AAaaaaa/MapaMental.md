# Mapa Mental

Machine Learning consiste en alimentar datos a una serie de algoritmos para que aprendan patrones.
La ensencia está en que no sabemos que patrones se van a generar, pero tenemos docenas de métodos para tratar estos datos.
$$\begin{array}{l}\text{} \\ \\ \boxed{DatasSet}\rightarrow\end{array}
\begin{array}{l} 
    \text{Repeticion} \\
    \curvearrowleft \\
    \boxed{\text{Algoritmo de entrenamiento}} 
\end{array}

\begin{array}{l}\text{} \\ \\ \rightarrow \boxed{DatasSet}\end{array}
$$
De tal modo que nuestra red sea capaz de procesar nuevos datos siguiendo los patrones que haya aprendido.

$$\boxed{\text{Foto de un animal}}\rightarrow\boxed{\text{Red Entrenada}}\rightarrow\boxed{\text{Resultado: Perro(\%99)}}$$

## 1 Intro

Los algoritmos `aprenden` a base de realizar algoritmos aplicados sobre `casos` de ejemplo previos.
EL aprendizaje consiste en corregir las desviaciones sobre estos ejemplos hasta que el algoritmo tiene una `confianza` alta sobre lo que debería ser el resultado al aplicarla en casos nuevos.
Este aprendizaje requiere de `abstraccion`, no podemos diseñar un algoritmo que se aplique a todo, lo que sirva para clasificar imagenes de gatos no servirá para modelos 3d de gatos.
Esta abstracción hace que lo que se aprenda contenga `sesgos`.
El algoritmo aprende caracteristicas que no pueden ser las que queramos.
Los algoritmos pueden desarrollar `overfitting` si se adaptan MUCHO a nuestros ejemplos en vez de al caso general.
`bias` y `variance` se pueden describir como precision y exactitud.
La primera es como de cerca nos hemos quedado del resultado esperado y la segunda la dispersion de los resultados al respecto de ese resultado. 

- Aprendizaje supervisado: Ejemplos con soluciones
- Aprendizaje SIN supervisión: Ejemplos sin clasificar
- Aprendizaje reforzado: Aprendizaje a mano

No todos los problemas se pueden resolver con Machine Learning:
- Clasificacion: Identificar categorías
- Regresion: Predecir valores en casos continuos
- Clustering: Descubrir agrupamientos
- Reduccion de dimensionalidad: Sacar datos no relevantes
- Asociacion: Relacionar variables

## 2 Regresion

### Lineal
Aprende correlacion entre variables.
Sirve para predecir valores donde los datos no cubren.
Suele verse como una gráfica (X,Y) entre dos variables.
![alt text](/AAaaaaa/Teoría/Assets/MMRegresion.png)

La tipica ecuación lineal de:
$$Y=w*x+b$$

Los errores se corrigen con una `Funcion de coste` que mide la diferencia de lo que hemos calculado con los datos.
La que usamos se llama `Media de error cuadrático`.
Nuestro objetivo es llevar la Funcion de coste a un valor minimo

### Gradiente Descendente
La `Funcion de Coste` se repite hasta que se invierte la pendiente.

Segun las comparaciones con el dataset podemos hablar de
- Gradiente Descendiente Total: Compara con todos los ejemplos
- Gradiente Descendiente Estocástica: Compara con un ejemplo
- Gradiente Descendiente Parcial: Compara con un grupo de ejemplos

Dentro de las parciales podemos hacer:
- Forward
- Backward

### Clasificacion
Si queremos clasificar los datos, cuando damos con valores continuos tenemos que hacerlos discretos, para ellos popdemos usar `Regresion Logistica`, una ecuacion que acerca valores a sus extremos.

### Regularización
Se usa para evitar el `overfitting`.
Es cuando el modelo se aprende demasiado el dataset, no lo que queremos que aprenda.
Podemos:
- Aumentar el dataset
- Seleccionar valores a mano
- Regularizar: reducir los valores de aprendizaje

## 3 Redes Neuronales

Las Neuronas son un tipo de célula que se interconecta entre ella y emite pulsos eléctricos de manera selectiva.
Imitamos ese comportamiento en programación.

Creamos una serie de valores en un array inicial (Neuronas de entrada) y las conectamos a otra capa. Los valores de la segunda capa se calculan realizando "conexiones" con diferentes pesos.
![alt text](/AAaaaaa/Teoría/Assets/MMRedNeuronal.png)

### Normalizacion 
Las redes funcionan mejor con datos normalizados (0-1).
Sklearn tiene una funcion normalize

### Forward Propagation
Se realizan los cálculos avanzando desde la primera capa.
Se usan valores aleatorios para los pesos, y cada iteración se varian segun parámetros.
Las ecuaciones que los modifican pueden ser gradientes descendentes.
