# Machine learning y minería de datos aplicado a videojuegos
Python

Red bayesiana??
Mlegends?

How do Learning Machines? Learn
"Hay unas pelotas" - Ismael

Las reglas cubren la mayoría de los casos, pero no podemos cubrir todos

"Esque los murcianos no saben hablar" - Ismael
"-Es coña 
*pausa de 2 segundos* 
-Tengo familia en Murcia" -Ismael

librería scikit-learning
Tensorflow

# Gradiente descendiente
Formula que regula la diferencia entre el resultado y el valor obtenido de la manera más eficiente posible

Para realizar el calculo (Hallar la red) usamos el proceso de BackPropagation.

# Backpropagation
Si queremos procesar excritura a mano, usaremos imagenes de 28x28 pixeles como referencia en los datos de entrenamiento. Es importante normalizar los valores (Ajustarlos para que vayan desde 0 a 1).
Este ajuste se hace con la sigmoide, una formula que para valores muy negativos los ajusta a 0 y para valores muy positivos los ajusta a 1.
Una matriz de datos entrantes (784x1) se inicializa con pesos de los datos de entrenamiento, y se relaciona con la siguiente capa de "Neuronas" con pesos aleatorios inicializados (16x1).
Un peso es un valor que multiplica a una de las neuronas de entrada y se la suma a la de salida.
En el caso de la entrada CADA valor de la entrada (Cada uno de los 784) tiene un valor que lo multiplica y se lo suma a la siguiente (16 de salida).
Eso nos deja con 12544 multiplicaciones para la primera capa.
Se hace lo mismo para la segunda capa de 16 neuronas y finalmente se hace para la capa de salida de 10.
Analizamos los datos de salida, calculamos la diferencia entre la salida y lo que queriamos y modificamos los pesos en la red.
Un valor de 1 se codificaria en la red como [1, 0, 0, 0, 0, 0, 0, 0, 0, 0] y uno de 7 como [1, 0, 0, 0, 0, 0, 0, 0, 0, 0].
El valor de una neurona puede ser cualquier cosa [0.1, 0.3, 0.47, 0.55, 0.89, 0.26, 0.45, 0.65, 0.02, 0.04]

# One-Hot Encoding
Transformar variables cualitativas (Descriptivas) en cuantitativas (Numeros)

```python
from sklearn.preprocessing import OneHotEncoder
oneHotEncoder = OneHotEncoder(drop='first')
oneHotEncoderFit = oneHotEncoder.fit(provincias.reshape(-1,1))
oneHotEncoderFit.transform(provincias.reshape(-1,1)).toarray()
```

# Testing
Para evitar el overfitting o el sesgo los datos tienen que aleatorizarse y separar en subgrupos segun el tamaño del entrenamiento.

```python
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(data, y, train_size = 0.8, random_state = 1234)
```

Cross validation consiste en usar uno de los subgrupos para comprobar el entrenamiento de los demás, si hacemos 10, entrenamos con 9 y usamos para la validacion el décimo
```python
from sklearn.model_selection import cross_val_score
clf = Stimator(For example MLPClassifier)
scores = cross_val_score(clf, X, y, cv=5) #,scoring='f_1macro')
scores
print("%0.2f accuracy with a standard deviation of %0.2f" % (scores.mean(), scores.std()))
```