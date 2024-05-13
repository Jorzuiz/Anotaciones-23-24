# 6 - Aprendizaje NO supervisado

Se buscan relaciones de parentesco o paridad entre los clusteres analizados de datos.
Se intenta minimizar la distancia intragrupo y maximizar la distancia intergrupo.
Estrategia de aglomeramiento.

6-5 K-medias
Todos los ejemplos se van particionando en base a la distancia.
El aprametro a tener en cuenta es la cantidad de K que esperamos.
(Suele usarse algoritmo PCA para reducir las dimensiones y tener una vosualizacion mas clara)
(hace combinación lineal de algunos atributos apra construir otros)
Sklearn
Standard scaler
calculamos el PC

1 Como podemos mejorrar el perceptron multicapa?
Modificar el leraning rate
Mejorar los datos con mayor cantidad
Eliminar atributos no representativps

2 Elije un modelo y razonalo
Segun el ejercicio el random forest es el mejor y KNN el peor.
Tampoco tendria sentido usar el perceptron muticapa
Las ventajas de random foresto son caja gris, dado que permite ver el razonamiento parcialmente

3 KNN con valores 0, 1 y 2 

P2
Se ha suado train_test_split (sklearn)

P3
Detectar tumor a partir de Xrays
tenemos 100k imagenes

Reducir dimensionalida de datos PCA


P4
Tetris, se crea un sistema que registra x eventos y asigna una captura dedatos  para imitar estilo de juego del jugador.
Como se codificatian los datos y con que medida de distancia?
Distancia euclidea funciona siempre, pero la idea es usar otra.
Distancia Manhattan en este caso, porque nunca habrá diagonales