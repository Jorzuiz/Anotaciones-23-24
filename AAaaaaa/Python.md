# Anotaciones de python
-Las identaciones del codigo se usan para separar metodos, bucles condiciones, etc.. del mismo modo que se usarian corchetes en C++
-Los tipos no se declaran, las variables pueden cambiar en ejecucion
-String por int multiplica int veces el string
-Sintaxis semejante a operaciones en C++, asignaciones += etc
-Por defecto se immprime la ultima variable en una celda

### String operaciones
- var.upper pasa a mayusculas
- print({} cosas, 21) inserta valor de vvariable en string
- var = string + string Concatena las variables
- String[7] para acceder a un char
- String[-4] para acceder desde el final 
- String[2:6] para acceder a una secuencia
- String[::-1] por defecto valores 0 end, invertir el valor inveirte la secuencia
- String.index("Cosa") devuelve el numero en la posicion del literal, devuelve error si no está
- String.split(' ') separa en una lista usando el separador proporcionado
- String = "{0} cosas {1}" permite reservar huecos a variabeles
- String.format(int) parsea el dato al añadirlo en un hueco


- Var.input("Mensaje") solicita la introduccion de un dato

### Condicionales
- Mismo funcionamiento que en C++
```python
if x > 2:
    #thingies
elif x <1:
    #more thingies
else
    #even more thingies
```

### Bucles
```python
while i<=10:
    #cosas
# fin del bucle por identacion
```
- EL bucle for solo puede recorrer listas