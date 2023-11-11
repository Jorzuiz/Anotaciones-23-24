# 4 Diseño de proyecto de Machine LEarning

La mayoría del tiempo en el proyecto se irá recabando, limpiando y procesando los datos.
Grandes cantidades de datos como por ejemplo los biométricos pueden conteener errores que nov eremos y que afectarán al modelo (Desconesxiones de los sensores, etc)
Eso es el trabajo del cientifico de datos

para el procesamiento de estos datos realizamos un ciclo:
Elegimos arquitectura, entremaos el modelo y diagnosticamos los datos (Limpiamos y tratamos los errores)

A la hora de limpiar los datos la maenra mñas sencilla es eliminar las entradas con errores (NaN)
Esto no es viable para bases con pocos datos.
Podemos calcular la media de los datos mas similares (KNNImputer)

4.2.1 Algoritmos categóricos
Cuando tratamos con categorías, para tratarlo con AMchine LEarning tenemos que pasar los valores a variables.
Elementos como blanco negro rojo o azul no tienen orden, pero las notas de un examen si.
Una tñecnica que podemos emplear es one-hot encoder, podemos crear una feature por cada uno de los valores de la categoría.
Si queremos entrenar machine learning para por ejemlpo calcular la nacionaldidad de alguien en base a su color de pelo, tendremos que suar One-Hot Encoding para codificar cada color, por ejmeplo, si eres rubiso serás, rubio =1, pelirrojo =0, moreno =0, blanco =0

4.3 Evaluacion del modelo
1. Lo evaluamos con el error cuadrático
2. Confussion matrix: 
$\boxed{}\boxed{\text{C observed T}}\boxed{\text{C observed F}}\newline
\boxed{\text{C predicted T}}\boxed{\text{True Positive (TP)}}\boxed{\text{False Positive (FP)}}\newline
\boxed{\text{C predicted F}}\boxed{\text{False Negative (FN)}}\boxed{\text{True Negative (Tn)}}\newline$
3. Precisión
$\text{Accuracity}\frac{TP+TN}{TP+N+FP+FN}=\frac{V}{N}$
4. Sensibility (Recall o True Positive Rate)
$Recall = \frac{TP}{TP+FN}$
5. Predicted Positive Value
$Precision = \frac{TP}{TP+FP}$
6. F1 Score
$2*\frac{Precision*Recall}{Precision+Recall}=\frac{2*TP}{2*TP +FP+FN}$
