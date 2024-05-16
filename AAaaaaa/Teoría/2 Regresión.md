# 2 Regresion Lineal
Funciona como una caja negra.

El modelo de regresión lineal funciona como en matemáticas/estadística.

Básicamente, partimos de un set de datos y tenemos que averiguar cual es la curva o linea que los conecta, de este modo podeos hacer predicciones sobre las partes que desconocemos.

![alt text](.\Assets\LinearRegression.png)

Se usa la función clásica de $$Y=w*x+b => f(w,b)=w*x+b$$
Existe unas funcionas llamadas *de coste* que se usan para corregir la desviación del modelo.
La más usada es Mean Square Error (MSE) $$MSE(Y,Y')=\frac{1}{m} * \sum^{m}_{i=1}(y_i - y'_i)^2$$
Básicamente, calculamos la diferencia entre lo que ha salido y lo que esperabamos y lo cuadramos para que sea positivo. Se suele dividir entre 2m para ayudar luego con la derivada parcial $$MSE(Y,Y')=\frac{1}{2m} * \sum^{m}_{i=1}(y_i - y'_i)^2$$

El objetivo final de la regresion lineal es disminuir el valor resultante de la función de coste

Al parecer según cosas que tengo que recordar de bachillerato para hallar el mínimo de una funcion hay que hacer la derivada, la integral es para hallar el área.
Que carajos es una derivada parcial?

![Alt text](./Assets/image.png)

¿Por lo visto hay que ir modificando los valores de $\alpha$ y $W$ hasta llegar al mínimo?


|Edad|Salario|Banco|
|---|---|---|
|30|23|10|
|40|35|15|
|x_1|x_2|y|

$Y'(fWb(\overline{X}))=w_1*x_1+w_2*x_2+b$

- w_1 =1
- w_2 =2
- b=1

$y'_1 = 30*1+23*2+1=77$

$y'_2 = 40*1+35*2+1=111$

$\frac{1}{2m} \sum^{n}_{i=1}(Y^{'}_1-Y_{\omega})$

$(77-10)^2 + (111-15)^2 = 13705$

Esto dividido entre 2 porque es /2m del sumatorio donde m es el numero de ejemplos de caso
3426.25

En los casoss sucesivos hay que ir modificando los valores de $w_1$ y de $w_2$

$w_1=w_1-\alpha*\sum_{\forall i}(y^{'}_{i}-y_{i})*x_{1i}$
$w_2=w_2-\alpha*\sum_{\forall i}(y^{'}_{i}-y_{i})*x_{2i}$

$w_1=1-0,5$ esto ultimo es el valor de $\alpha$
$\frac{(77-10)*30+(111-15)*40}{2}=\frac{2010+3840}{2}=292.5$
El valor es $W_1=291,5$ al restarle el 1 de alguna cosa que nor ecuerdo

Para evitar imprecisiones en los datos tenemos que normalizarlos.
Podemos dividirlos por la maxima, calcular la media y la dev tipica para restarsela....

## 2.1.1 Gradiente Descendente

Se usa para encontrar minimos locales en una funcion. Se "baja" por la pendiente hasta que esta se vuelve positiva $$w=w-\alpha\frac{\partial w}{w} J(w,b)$$
$\alpha$ es el ratio de variabilidad de $w$ y $b$ en cada repetición, las cuales se inician aleatoriamente.

Se puede entrenal al Gradiente de 3 maneras
- Batch: actualizando tras comprobar el error respecto a TODO el set de entrenamiento.
- Estocástico: actualizando tras comprobar con solo un ejemplo
- Mini-Batch: Actualizando tras comprobar respecto a un subgrupo del set de entremaniento

## 2.2 Regresión Multivariable

Los múltiples parámetros se cargan como un vector. $$f_{\vec{w},b}(\vec{x})=\vec{w}*\vec{x}+b$$ Vease $$f(w,b)=x_1*w_1+x_2*w_2+...+x_n*w_n+b$$
La funcion dot de numpy lo hace todo easy
```python
w = np.array([1.0,2.5,-3.3])
b = 4
x = np.array([10,20,30])
f = np.dot(w,x)+b
```
Dot realiza el producto escalar: Multiplica los valores parejos de los arrays entre ellos y los suma $w_0*x_0+w_1*x_1+...$

## 2.2.1 Feature Scaling
la dependencia entres las múltiples variables puede usar diferentes escalas, imagina que correlacionamos el numero de hijos con la renta de un hogar, valores que en un eje pueden ser de miles requieren de una escala difeerente que unas unidades.

 ![alt text](.\Assets\FeatureScaling.png)

## 2.2.2 Criterio de convergencia

Se determina que hemos acabado cuandoo
- El error baja de un numero determinado
- El modelo no mejora más allá de un valor dado

![alt text](.\Assets\Convergencia.png)

En esta gráfica podemos ver que entorno a la iteración 400 se produce una mejora de menos de 0.001 asique paramos

## 2.2.3 Valores de aprendizaje

Un valor muy alto puede producir saltos en la gradiente y uno muy bajo puede no acercarnos al valor real.
Se recomiendan valores como 1 0.3 0.1 0.03 0.01 0.003 0.001 etc

![alt text](.\Assets\Aprendizaje1.png) ![alt text](.\Assets\Aprendizaje2.png)

## 2.3 Clasificación
Podemos definir diferentes sistemas por ejemplo si contiene valores discretos o contiene decimales.
Para estos problemas discretos los modelos de regresión pueden ser imprecisos. Hemos pasado de tener formulas que predecian valores a buscar que estos valores (los cientos de pixeles de una imagen) nos devuelvan un valor discreto (Saber si es perro o gato).
Para ello tenemos que buscar convertirlo en valores discretos.
## 2.3.1 Regresion Logística
ALABADA SEA LA SIGMOIDE
$$g(z)=\frac{1}{1+e^{-z}}$$
Esta formula redondea valores de 0 a 1 desde la mitad. Los menores de 0,5 los pasa a 0 y los mayores a 1

## 2.3.2 Funcion de pérdida
Básicamente MSE $$J(\vec{w},b)=\frac{1}{2m} * \sum^{m}_{i=1}(f_{\vec{w},b}(\vec{x}_i) - y_i)^2$$
Hemos metido $(f_{\vec{w},b}(\vec{x}_i)$ por no repetir la patata de antes.

## 2.4 Regularizacion
Para evitar la sobreadeptacion usamos una cantidad de ejemplos y una de comprobaciones.
Los datos pueden no ser suficientemente representativos del problema, que falten casos limites, o que sean demasiados dispares.
Comprobar atributos que introducen ruido. En caso de una clasificación de mamíferos comprobar el pelo no es fiable, las ballenas no tienen pelo.
Estos atributos podrian detectarse solos en la muestra y bajar su peso.
la varianza es lo contrario del sesgo.

2.4.6.1 los valores de lambda tienen que ser mayor de 0 porque si no implica la no penalizacion. valores superiores de 1 reducen overfitting pero aumentan sesgo

2.4.7.1 El error del dataset es la media de los errores de los ejemplos.
