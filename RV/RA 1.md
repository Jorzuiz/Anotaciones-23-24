# IA y el arte 
Puede la IA ser realmente creativa?

1956 - Dartmouth college

1957 - Primer perceptron

1966 - Eliza chatbot

1997 - Deep Blue

2017 - OpenAI crea GPT (Deep Learning)

2018 - Edmond de Belamy

2019 - Meena google

2023 - GPT4

### Piezas por IA

1960 michael Noll Gaussian-Quadratic

1968 proyecto AARON - Harold Cohen

1973 - Generatic Computergrafik

2008 - Leonel Moura - Robotic Action Painter

2015 - Mario Klingemann - NeuroGraphy

2016 - The next Rembrandt

### Ejemplos de Herramientas

Dall-E 3

Generador de imagenes de Bing

Bard google

Laeonardo ai

Lexica art

csm 3d ai

Mixamo

Genie Lumalabs

### Vuforia 2

- Ground Plane

Camara igual que en P1.

Añadir Gameobject Ground Plane Finder y Ground Plane Stage.

Contienen 3 scripts.

Anchor behaviour puede ser plane o mid air.

Default Observer puede extender el tracker, pero hoy no.

Añadimos modelo 3D a escena y lo ahijamos a la Stage.

Los scripts de anchor input listener deteta(?) los inputs.

Plane find behaviour detecta el suelo constate y llama al Content Positioning Behaviour.

En plane find behaviour > advanced podemos seleccionar la altura por defecto del movil.

La casilla de duplicar permite crear mas instancias con click.

Content Positioning Behaviour contiene anchor stage que es la imagen que queremos mostrar, en este caso el Ground Plane Stage podemos usar el emulador que representa 2x2 cuadros del ground plane.

En los assets del juego Vuforia Engine AR > Vuforia >database >emulator.

- Multitarget

Add target en Vuforia targets (web) con escalas 1.

Podemos añadir las caras de los targets al cubo.

Instalamos el Traget en el proyecto.

Contiene varios gamobjects con los diferentes targets.

La oclusion permite que las caras tapen el objeto.

Cada gameobject puede emparentarse con un objeto diferente pero todos se muestran individualmente de la cara

>Las runas en futhark pueden resultar interesantes para la generacion de puntos

Los modelos de mixamo vienen SUPER chiquitos.

Hay que añadir el componente de animacion a mano.

- Cylinder target  

Dot CSV Lab Gaussian Splatting Lumalabs