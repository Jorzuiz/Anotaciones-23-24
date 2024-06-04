# Resumen

## 0 - Intro

- Android (SDK) y Java (JDK)
- Gestión de recursos (imágenes, audio…)
- Desarrollo de videojuegos multiplataforma (herramientas, arquitectura, ventajas, características…)
- Uso de sensores móviles (gestos, acelerómetro, geoposicionamiento…)

Android Studio, Gradrle, Firebase, proguard...
Características del mercado y estrategias de monetización .

## 1 - Mercado

Inicialmente había más diversidad de SO pero se redujo a iOS y Android
Aumenta el tamaño de los moviles con el objetivo de tener más batería
Moviles plegables permiten tener más batería

Han evolucionado de dispositivos de comunicación a pequeños ordenadores de bolsillo con gran cantidad de sensores, Acelerómetro, Barómetro, Giroscopio, Cámara....
Se utilizan para comunicación y entretenimiento.
las aplicaciones que más ingresan son los juegos.

>El mercado movil supone mas de un 50% de ingresos en vodeojuegos (Superan PC y consolas juntos)
>Asia genera mas del 60% de ingresos 

Las caracteristicas de un juego móvil son la de ser para "tontos" y "casuales"
Sesiones cortas con objetivos claros.
Poder pausar y retomar en cualquier momento y recibir ayuda cuando se necesite.

Las apps e pueden clasificar en 3 tipos
1. Nativas (Del Android/iOS exclusivamente)
2. Hibridas 
3. Apps Web 

## 2 - Desarrollo en Android

Basado en Linux, adquirido por Google en 2005, operado por la Open Handset Alliance (Conglomerado de fabricantes)
Programado en Java y Kotlin de manera intercambiable.
Android Studio está basado en InteliJ (IDEA)

1. Android SDK: Kit de desarrollo de Android con depurador, bibliotecas, siimulador, api...
2. JDK: Kit de desarrollo de Java, cpontiene la maquina virtual de Java, compila el codigo Java a Bytecode, que permite ser interpretado en diferentes dispositivos.

Maquinas virtuales basadas en Java que usand .dex en vez de Bytecode.

3. *DALVIK:* Compila Just In Time el codigo.
4. *ART:* Compila Ahead of Time el codigo. Tarda más en instalar la app, pero ahorra bateria a la larga con ejecuiones más cortas

5. NDK: Kit de Desarrollo Nativo de Android. COntiene herramientas para desarrollo en C/C++, Librerias, etc...
Utiliza JNI (Java Native Interface)
6. Gradle: Herramienta de automatización de Builds. Permite compilar, enlazar diferentes dependencias y librerias de modulos y lanzar el simulador de la app.

### Aplicaciones
Formadas por componentes (Actividades)
Actividad Principal
Se pueden relacionar Padre-Hijo en el manifiesto de Android
Actividades: representan una ventana o conjunto de vistas y tienen una funcion concreta, enviar email, mostrar direccion... Se componen de layouts
Layout; Existen jerarquis de Groups que contienen views u otros Groups
Ciclo de Vida

onCreate(Bundle savedInstanceState)
    onStart()
    onRestart() - Llama a OnStart() tras ser detenida (onStop())
        onResume() - Interactua con usuario
        onPause() - 
    onStop() - Invisible pero retiene informacion
onDestroy() - Se llama antes de que el sistema detenga la actividad

### Manifiesto
Archivo XML con informacion esencial de la app
Nombre del paquete
Componentes
Permisos
Requisitos Soft/hardware

### Intents
Activan componentes de la app (Actividades, servicios...)
Permiten la comunicacion entre Apps
>*Explicitos:* Llaman a una actividad de tipo especifico
>*Implicitos:* Comunican al SO la actividad para que gestione la llamada

## 3 - Java
Alto nivel, basado en clases y orientado a objetos
Compilado a lenguaje intermedio (Bytecode)
Se ejecuta en una máquina virtual (JVM)
Lenguaje multiplataforma
Fuertemente tipado
Permite reflexión
Recolector de basura

public static void Main(String[] args): empieza y acaba el programa
System.exit(0): cierra la JMV con codigo de error

Modificadores
Final: No se puede modificar, sobreescribir no heredar una clase/variable/metodo
Static, se puede usar sin isntanciar
abstract: No tiene implementacion y puede ser instanciada

Hilos
Permite correr hilos con diferentes estados implementando runnable
Start       ->      Stop
Runnable - Blocked - Running

reflexion, permite recorrer metodos de una clase.

## 4 - Gradle

Empaqueta APK o AAB
Gestiona dependencias

Gestiona los modulos en Android Studio
Se pueden compilar probrar y depurar en separado
*APK:* Paquete que contiene la aplicación al completo, codigo, assets, recursos...
*AAB:* Paquete que contiene la aplicaicon con recursos especificos del dispositivo, procesador, idioma, etc
Las APk se suben a la Play Store y las AAB se descargan de ella

### Ciclo de vida:

Inicializa los proyectos correspondientes
Configura ejecutando los scipts de construccion del los proyectos
Ejecuta cada una de las tareas

*Settings:* Archivo del proyecto
*Build:* archivo de proyecto y modulos

### Tareas
Se pueden configurar movimiento de archivos, copias, directorios...

## 5 - Android Canvas

Para dibujar se necesitan 4 Componente basicos
- Mapa de Bits - Papel donde pintamos en pixeles
- Lienzo - Lugar donde pintamos
- Primitiva - Herramientas de dibujo
- Pintura - Colores

*android.view.SurfaceView*
Superficie de dibujo compatible con jerarquia de vistas
la jerarquia determina las posiciones relativas por herencia.
Se puede llamar desde un hilo secundario para el render si:
- Todas las llamadas estan en el hilo que creó la ventana
- El hilo solo usa la superficie mietnras es valida

*android.view.SurfaceHolder*
interfaz abstracta que controla el acceso a las SurfaceViews

*android.graphics.Canvas* - metodos de pintado como circle, rect, bitmap....
*android.graphics.Paint* - informacion de color, grosor, etc
*android.graphics.Typeface* - Pintar texto
*android.graphics.Bitmap* - Pintar pixeles

- AssetManager
Sacado de Activity o Context con getAssets()
apunta a /app/src/main/assets/
Permite acceder a archivos que no son código
Se pueden listar en el sistema en compilacion
Proporcionan mas libertad pero tiene que gestionarse a mano

- Resource Mangaer
Igual que el Asset Manager pero para archivos reconocibles por android
Estos tienen que ser nombrados especificamente en el codigo
Delegan la gestion al sistema android (Podemos cargar mp4 y mp3 sin tener que implementarlos llamando al sistema)

## 6 - Android Renderizado
- Canvas
- OpenGL - API de controles para graficos 2D y 3D (NDK)
- Vulkan - Competidor de Directx de codigo abierto, controla  bajo nives (NDK)

Canvas es una librería de Android
metodos para creacion de UI
Todas las vistas de Android usan Canvas
- onDraw()
- onMeasure()

SurfaceView está preparada para ejecutarse en otro hilo
Se puede dibujar Tras sus vistar hermanas (permite dibujar botones)
Puede afectar al rendimiento (Dibuja sobre pixeles multiples veces)

## 7 - Desktop Canvas
Para dibujar se necesitan 4 Componente basicos
- Mapa de Bits - Papel donde pintamos
- Lienzo - Lugar donde pintamos
- Primitiva - Herramientas de dibujo
- Pintura - Colores

*javax.swing.JFrame* Crea una ventana invisible
*java.awt.image.BufferStrategy* Ordena la carga y renderizado de buffers de pantalla, bucle principal de pintado
*java.awt.Graphics2D* Metodos de pintado de formas, texto e imagenes.
*java.awt.Font*
*java.awt.Image*


## 8 - Android Eventos de entrada

Originalmente botones en teclados
Actualmente pantallas tácticles y ocasionalmente periféricos (mandos, pantallas...)

- Pantallas resistivas
Contiene dos capas conductoras separadas por espaciadores, ante la presión se conectan.
Bajo coste y consumo.
Robusto en clima extremo y sin toques falsos.

- Pantallas capacitivas
Conductores transparentes dispuestos en filas/columnas
Buena sensibilidad, multitouch...
Mas caras pero mñas faciles de limpiar

- Gestos
Touch, swipe, pinch, drag...

La clase View incorpora metodos para recibir eventos.
OnTouchEvent(), onKeyDown()....
No es eficiente extender la view asique vamos a extender las interfaces que lo componen  en listeners
OnTouchEvent(), onKeyDownEvent()...

La diferencia radica qen que uno extiende la clase View y el otro extiende el objeto solo

## 13 - Android Manifest
Informacion esencial
Nombre del paquete
Componentes
Permisos
Requisitos software/hardware

Actividad principal
COlores de la barra de accion

## 13.5 - Android Intents
Intent es un mensaje para empezar una actividad
Explicito: comienzan una actividad determinada
Implicito: envian un mensaje al SO para que determine que hacer con el tipo de actividad

Podemos filtrar y recibir items por tipo en nuestro manifest

## 14 - Mercado de juegos para moviles
Mercado casual
Barrera de entrada de pago, bajas ventas
F2P elimina esa barrera
5% de usuarios genera 95% de ingresos (ballenas)

## 15 - persistencia
Serializables: Transforman los datos del código a infromación en bytes que peude ser almacenada ena rchivos
*java.io.serializable:* debe ser implementada por cada objeto que quiera persistir

## 16 - Anuncios
Se espera que los juegos sean gratuitos y que las inversiones sean muy determinadas
Los anuncios son una manera de obtener ingresos de los jugadores gratuitos
Mantienen la retencion con recompensas
- Banner: Parece en una zona de la pantalla. Usan un view
- Intersitial: Interrumpe el juego ocupando la pantalla entera. Usan un Bundle para crear la nueva actividad
- Recompensado: Ofrece recompensa a cambio de itneraccion
- Nativo: Personalizado al estilo de la app

Requiere de dependencias en build, ID del paquete con los anucios (Exsite uno de prueba) en manifest e iniciar la SDK de anuncios

## 17 - Notificaciones
- Push: Aumentan la tasa de rentencion, pueden traer a jugadores que abandonaron. Requieeren de permisos. No es bueno abusar de ellas.
Se pueden usar para dar recompensas, ofrecer descuetnos, avisar de eventos...

