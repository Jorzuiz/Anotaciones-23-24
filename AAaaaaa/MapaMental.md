# Mapa Mental

Machine Learning consiste en alimentar datos a una serie de algoritmos para que aprendan patrones.
La ensencia está en que no sabemos que patrones se van a generar, pero tenemos docenas de métodos para tratar estos datos.
$$\begin{array}{l}\text{} \\ \\ \boxed{DatasSet}\rightarrow\end{array}
\begin{array}{l} 
    \text{Repeticion} \\
    \curvearrowleft \\
    \boxed{\text{Algoritmo de entrenamiento}} 
\end{array}

\begin{array}{l}\text{} \\ \\ \rightarrow \boxed{\text{Red Entrenada}}\end{array}
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

Hay 2 técnicas de regularización:

- L1 o lasso, que consiste en corregir los valores ABSOLUTOS de aprendizaje, como efecto secundario puede bajar alguna caracteristica a 0 y la "saca" del modelo.

- L2, que  usa a suma de los cuadrados de los errores, que evita que algunas caracteristicas se salgan.

### Funcion de pérdida (Cost Function)

Sirve para medir el `error` del modelo respecto a los datos. Se usa para realizar `correciones` en los entrenamientos.
Se usa MSE, `Mean Square Error`.

## 3 Redes Neuronales

Las Neuronas son un tipo de célula que se interconecta entre ella y emite pulsos eléctricos de manera selectiva.
Imitamos ese comportamiento en programación mediante una estructura llamada `perceptrón multicapa`.

Creamos una serie de valores en un array inicial (`Neuronas de entrada`) y las conectamos a otra capa de neuronas intermedias conocidas como `capa oculta`. Estas conexiones tiene valores diferetes denominados `pesos`. Los valores de la segunda capa son el resultado de aplicar la mutiplicacion de los valores de la capa anterior por cada uno de los pesos sumados (neurona 1 * peso 1 con neurona intermedia 1 + neurona 2 * peso 2 con neurona intermedia 1....= neurona intermedia 1). Repetimos entre la capa oculta y la final, Finalmente interpretamos los pesos de la `capa de salida`.
![alt text](/AAaaaaa/Teoría/Assets/MMRedNeuronal.png)

La ultima capa es la respuesta que buscamos pero se suele usar algún tipo de codificación como `one-hot encoding`.

## Normalizacion

Las redes funcionan mejor con datos normalizados (0-1). Set rata de un proceso donde pasamos valores a ´estándares´ mediante calculos entre máximos/minimos para dejarlos entre valores de 0 y 1.
Sklearn tiene una funcion normalize.
Se puede usar la finción sigmoidal.

## Forward Propagation

Proceso de aprendizaje.
Se incian los pesos de las conexiones a valores aleatorios. Se realizan los cálculos avanzando desde la primera capa, se repite para la/s capa/s oculta/s y sale una serie de valores.

Las ecuaciones que los modifican pueden ser gradientes descendentes.

## Optimización de la red

Una red no se entrena en una `generación`, cuando se inicia con pesos aleatorios `FALLA`.
Partiendo del dataset, comprobamos el fallo del resultado con lo que esperabamos y modificamos el valor de los pesos ligeramente.

## 4 Diseño de ML

$$\boxed{\text{Recogida de datos}}\rightarrow\boxed{\text{Proceso/Limpieza}}\rightarrow
\boxed{\text{Entrenamiento}}\rightarrow$$

## 5 Aprendizaje Supervisado

### KNN (K Vecinos Cercanos)

1. Distancia Minkiwski, parecida a la manhattan/euclidea.
2. Distancia de Edición, mide el número de cambios necesarios (Casa/cala es 1)(Casa/calle es 3)
3. Distancia Mahalanobis

Entrenamiento inmediato.
Sensible a datos extremos, lenta y mucha memoria en datasets grande (calcula TODO)

```python
print(len(iris.data))       # Filas (Tamaño) del dataset
X_train = iris.data[:-20]   # Carga N-20 muestras en iris
y_train = iris.target[:-20] # Carga N-20 ETIQUETAS de las muestras
X_test = iris.data[-20:]    # Carga 20 Muestras en el test
y_test = iris.target[-20:]  # Carga 20 ETIQUETAS

from sklearn.neighbors import KNeighborsClassifier
model = KNeighborsClassifier(n_neighbors = 1)       # Instancia el modelo

model.fit(X_train, y_train)             # Entrena el modelo

prediction = model.predict(X_test)  # Devuelve predicciones del modelo sobre X_test
print("Predicción")
print(prediction)
print("Test")
print(y_test)                       # Imprimimos las estiquetas del test para comprobar

model.score(X_test, y_test)         # Calculamos la score
```

### Árbol de decisión

Crea diferentes `nodos condicionales`, con valores relativos al dataset que clasifican cada uno de estos hasta llegar a generar una serie de `hojas`.
Tiene un algoritmo que calcula la `entropia` de cada nodo para saber cual es el mejor.

Entrenamiento rápido, fácil de leer por un humano.
Vulnerable al ruido en la entrada y al sobreentrenamiento.

```python
from sklearn.tree import DecisionTreeClassifier

from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import export_test

iris = load_iris()
decision_tree = DecissionTreeClassifier(random_state=0, max_depth=2)
X_train = iris.data[:-20]   # Carga N-20 muestras en iris
y_train = iris.target[:-20] # Carga N-20 ETIQUETAS de las muestras
X_test = iris.data[-20:]    # Carga 20 Muestras en el test
y_test = iris.target[-20:]  # Carga 20 ETIQUETAS

decision_tree = decision_tree.fit(X_train, y_train)
r = export_text(decision_tree, feature_names=iris[`feature_names`])
print(r)
decision_tree.score(X_text, y_test)
```

### Random Forest

Genera varios `árboles de decisiones` con subconjuntos del dataset aleatorios y se combinan

### Support Vector Machine

Conjunto de vectores que definen los margenes del hiperplano que clasifican los datos