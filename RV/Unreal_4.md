# 11/3
Animacion extra
Ir a Mixamo, descargar animaciones de salto/baile
Abrir el Event GRaph en el Blueprint de animaciones del PJ
del GetMovementComponent sacamos la variable y creamos un componente IsFalling
En la seccion el blueprint con las variables (izq) creamos una variable jump booleana con el +
Arrastrar la variable al BP y crear un set variable
En la otra pestaña de logica de animaciones, volvemos en la ruta atras y pinchamos en la regla de idle a jump
Arrastramos la variable booleana a enter transition
Volvemos atras y cambiamos la regla de vuelta, arrastramos variable, ponemos set y conectamos un modulo NOT boolean entre medias
Entramos en el salto, cogemos la animacion de salto en el panel de asset browser (der) y arrastramos y conectamos al output
Vamos al BP del caballero
Podemos englobar varios nodos selecionandolos, pinchando con el click derecho y seleccionando add note from selection
Si clickamos derecho sobre el componenete IA podemos hacer gotodefinition para acceder al componente
Creamos nuevo IA componente (duplicamos uno que ya haya)
En la carpeta ThirPerson>Input tenemos el IMC con todas las acciones
En él, añadimos un + en el mapping para el control, asignamos el Dance y metemos dos botones para mapear teclado y mando
Creamos un nodo Enhanced Action Event del componente IA que hemos creado
Creamos variable (izq) booleana dancing y hacemos un set (arrastramos)
Copiamos o arrastramos el character Movement de la columna de la izq
Sacamos un nodo nuevo de él, get velocity, sacamos un Vector lenght y sacamos un greater, sacamos Branch (condicion)
arrastramos variable IsDancing 2 veces para sacar 2 sets y los conectamos al branch, uno de ellos tiene que tener el tick activo
Sacamos un coneector del Triggered(EnhancedAction) y conectamos al branch
Sacamos canceled u lo conectamos al setDancing
En el BP anim del caballero, en el Event Blueprint sacamos fleccha y creamos un cast to bp al Blueprint del Caballero
Creamos variable bool para el dancing y creamos un nodo set
Sacamos del Cast el Get de la variable IsDancing (herencia???)
Puenteamos del casto al set dancing y  rehacemos la conexion al salto
Conectar el modulo get pawn owner al cast
En BPANIM creamos estado nuevo de baile y conectamos
Abrimos el conector y arrastramos un get isDancing
creamos un conector de vuelta y haecmos lo mismo pero con el not
En el estado de baile creamos un radon sequence play
En lado derecho del componente añadimos una entrada por animacion
En el BP deñl Caballero añadimos nodo event tick
Copiamos la rama de character movement hasta el greater y sacamos un brnach
Conectamos el true al isdancing y el vent tick a la entrada

# Iluminacion
Cargamos el fbx y arrastramos TODO al nivel
Abrimos el panel de place actors en la escena, el cuadro con el mas arriba
Colocamos bombillo, poemos cambiar intensidad y atenuacion con el medidor de candelas y de atenuacion
Construimos la luz desde Build>BuildLignthing only
Creamos en el panel de actores un Post Process Volume y lo ajustamos a la habitacion
En su pestaña de detalles buscamos Infinite Extent para no desactivar su post procesado solo dentro, sino que lo aplique a todo el entorno
Podemos cambiar de candelas a lumens en las propedades del proyecto
Cambiar en exposure volume para activar exposure y metering mode, ajustar como a 5