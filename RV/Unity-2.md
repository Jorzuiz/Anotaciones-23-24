# Unity 2
Descargar los starter assets del XR Interaction Toolkit sobre el tuto normal del campus

Action based coponents
Movemos prefab Teleport interactor al control derecho
Add component Grab interactor a los 3 abjetos
arrastrar los puntos de teleport anchor desde el prefab
Añadir Teleportation Area a la zona de juego
Seleccionar bien las pacas de colision a Teleport, tanto en las bases, como en el suelo como en los manodos

Los mandos tiene 3 componentes, ray interactorr, Direct interactor y teleport interactor (crear desde el prefab), para este ultimo configurar bien las capas.


En componente Locomotion system añadimos 3 hijos Move, Turn y Teleport, cada uno con un script de su nombre (Action-Based)
Añadimos un XR Controller en Teleport y seleccionamos un preset, none, al lado de la interrogacion. Descativamos los 4 primeros y en los siguientes 2 cambiamos a teleport select
En Move, Gravitty aplication mode puede perjudicar otras opciones

A controller añadir componente Interaction group, en starting 
Añadir Action based Controller Manager, asignar sus controles, son mas o menos obvios
En XR origin añadir un character controller
tambein en su Input Action Manger añadir XRI Default Input Actions, cambiar su XR Origin>Tracking origin Mode a floor

Linterna tiene XR Grab Interactable y XR Single Grab Free Transform
En grab interactable starting single grab transformers añadimos la linterna
Linterna tiene un attach transform que cambia la posicion de agarrado del objeto, no se donde uwu
En la base de la linterna añadimos el componente XR socket interactor

## Seccion Luz
Podemos seleccionar los objetos manualmente como Static para que la luz se precalcule (Baking)
Window>Rendering>Light Explorer
Para optimizar es recomendable reducir el numero e luces dinámicas y hronear todo lo que se pueda.
Usar universal render pipeline.

Reflection prop
Crear un cubo crearle un material y ponerlo, subir metal y smoothness y bajamos el alfa de albedo a 0
GameObject>light>Reflection Probe
En su script si pulsamos el primer icono podemos cambiar el área de reflexion
Hay que usar un light Probe Group, cada material tendrá asignado uno de estos, delimitando zonas de sombra, o el color del suelo, podemos duplicar puntos con CTRL+D, creamos los que correspaondan a materiales y materiales sombra del suelo, duplicamos y los subimos
