# Unreal_3
Proyecto en tercera persona
Mixamo, loguear y descargar un pj en formato fbx    
Buscargar y descargar una animacion Idle sin skin
Arrastrar a Asseets para importar
Marcar importacion como exqueleto y mesh
Marcar importacion de animaciones con animation time
Asegurarse de que importa el material
Crear nuevo blueprint tipo character
Editar el BP del personaje: Correr el proyecto y pulsar F8 para poder seleccionarlo
Cambiar a pestaña viewport, seleccionar mesh (izq)
Parar el proyecto para poder cambiar la mesh en pestaña de detalles
Cambiar Skeletal Mesh al personaje
Alinear Pj con la capsula del BP cambiando el transform
Dar a compilar y guardar
En Unreal, seleccionar la lista de Bp y entrar en Gamemode > Edit Gamemode y cambiamos el default Spwan class a nuestro pj
Copiar el Event Graph del BP base del juego a nuestro personaje para comenzar a ponerle animaciones
Arrastrar animaciones a Assets, tienen que tener marcadas un skeletal para poder importarse
Creamos un animation blueprint
En el blueprint (aba/der) hay una pestaña de animaciones, arrastramos una al graph
Conectamos y compilamos la animacion a Outputpose, para activar el loop activamos e details
Crear new State Machine (Icono cuadradito)
Crear en assets nuevo componente blend space
dentro del blend Space arrastrar idle al punto 0, walk al 50 y run al 100
Podemos desplazarnos para ver las animaciones con el cursor mientras mantenemos el control
Podemos cambiar las dimensiones de la linea de tiempo en Asset Details
Cambiamos el Sample Smooth a 100 (No me he enterado del porque)
Volvemos a Animation Component del Caballero y entramos en la State Machine
Sacamos una flecha de entry y creamos un nodo State para idle/walk/Run
Del estado arrastramos otra flecha y cambiamos a inicio salto
Doble click en el estado idle, creamos un modo Blendspace Player (Con el nombre de nuestro Pj)
Boton derecho en el boton none para crear variable
En BS cambiamos el nombre del eje horizontal a Velocidad, esto deberia verse reflejado en el nodo de la maquina
Cambiamos a pestaña eventgraph (habrá 2 nodos inactivos)
arrastramos el de salida para crear los componentes GEt movement component, Get Velocity y vector length
(Ab/iz) arrastramos la variable de velocidad al nodo (Lo mismo no cambiamos el nombre pero estaba en la maquina) y la creamos como set
COnectamos este ultimo nodo al componente rojo
En el pj, seleccionamos characeter movement (dr) y cambiamos walk speed a 300 (dr)
Lo mismo no lo he puesto antes, pero en mesh asigna en animacion el Animatioc del pj
Creamos componente InputAction para correr
En el Event Graph del Pj sellecionamos la lupa en mapping context y damos al IMC para editarlo
Añadimos un mas para seleccionar el nuevo componente correr y en tecla asignamos shift.
podemos añadir otro boton con el mas del input action
Volvemos al pj, bajamos al salto y  copiamos el nodo de input
Arrastramos character moveement (iz) al editor
Sacamos nodo y buscamos set max walk speed
ponemos a 600 y connectamos started al set
copiamos el nodo y conectamos a compelted con 300
En el pj tenemos el componente controler rotation yaw para que se rote con camara o no con el pj
Orient rotation to movement hace animaciones de giro
