# Unity VR
Edit > Project Settings > XR plugin, install XR PLugin, activar Open XR

Cambiar opciones en Build Settings(File), tiene que estar en compatible con android
Cambuiar project settings(Edit) para el modo de color y mas cosas segun la guia
Descargar en Pakcage Manger (window) XR interactionToolkit con los starter assets de sample

Con la escena del campus borramos la camara y creamos el XR origin rig
Cambiamos las opciones de tracking (inspector) a suelo
En Left/Right hand controller estan las acciones, es una capa de abstraccion para no preocuparse por los botones del visor, solo las acciones con los objetos
Recordar darle al project validation para resolver los problemas
AL lado del Script XR controller hay un icono de dos lineas, si pulsamos podemos cargar los presets
Borramos todos los componentes que no sean XXR COntroller
Añadimos el componente XR Direct Interactor
A las cajas tendremos que añadir XR Grab Interactable
Podemos cambiar el movement type para hacer que el objeto sea kinematico o que reacciones solo a ser recogido por el controlador
El componente XR simple Interactable
El componente XR TInt Interactable Visual cambia de color el componente cuando interactuamos
EN Project Settings existe el componente Unity Mock HMD util para debuggear, tenemos su mapeo en las XR InteractionTool, lo descargamos desde el Packet manager, deberia ser la segunda sample, y cargamos el prefab en la escena.
Añadimos el direct interactor COMO HIJO a los dos controllers y lo borramos como componente
Añadimos tambien los componentes ray interactor
En el suelo añadimos script de Teleport area y cambiamos la layer a teleport
Añadimos el Asset teleport anchor
Arrastramos teleport interactor a right hand controler y desactivamos ray interactop
Añadimos un objeto vacio al xr origin (hijo) llamado locomotion system y le añadimos el script locomotion system, añadimos como destino XR Origin
Creamos tres componentes para move, turn y teleport
PAra cargar el mando tenemos que marcar Use Reference
Ajustamos velocidad, controles a left/right con turn/move locomotion
Turn tiene dos scripts para continuous o snap

Descargamos en samples XR InteracionToolkit y cargamos el Tinneling Vignette a la camara
Puede ayudar a evitar parte del mareo, idk how

Añadimos al tercer objeto del Locomotion System el componente teleport provider

Creamos Esfera vacia y añadimos componente Audio Source, tenemos un audio clip en lso assets
Activar Spatialize para que sea envolvente 
CAmbiamos el audio 3d a linear rolloff en vez de logarithmic esto hace que el audio se corte a una distancia y no permaneza eternamente

A la linterna le añadimos un Xr Grab Interactable y XR single
Metemos un hijo con el spotlight (cambiar solo el soft shadows?)
Creamos 2 eventos interactuables y en activable/desactivate ponemos el spotlight de la luz y el sonido del click, seleccionar en function light intensity (float) y Audiosource play