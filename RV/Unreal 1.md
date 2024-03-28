# Unreal things
La version de los labs tira raro, hay que dartle a opciones y enviar el acceso al escritorio.
En el bazar hay assets; se pueden filtrar por free.

Tropical vegetation Set
Open world demo collection
Temperate Vegetation

Que es el QUixel Bridge?
Megascan, empresa, escaneos?

Pestaña inferior de Content Drawer para todos los conetenidos del proyecto (Incluye los descargados)
En la vision de escena hay opciones en la parte superior. Arriba izquierda las referentes al proyecto y camara, arriba derecha referentes al modelo y el gizmo
Los assets tiene una "etiqueta" que cambia de color segun le tipo
Para hacer focus a un objeto, seleccionarlo ne jerarquia y ùlsar F
ALT + Click IZQ permite rotar con el raton sobre el objeto
Arriba izq está el boton Show que permite activar/desactivar capas de objetos para comprobar rendimiento
Texel density es cambiar la calidad de la textura segun proximidad a camara
Al eliminar objetos se mantienen sombras de mapa de iluminacion estática, recoockear la iluminacion.
En el modo foliage podemos arrastrar una hierba desde el content drawer y pintar con un pincel por zonas

Materiales
delectrics, plastic, glass ice, water rusted metal
Conductors, Gold, Silver, Aluminum, Iron, Copper
Creamos un constant 3 vector
Constat para valores como metallic y roughness
param>Vectorparam para valores parametricos(Opacity)
valor opaque constant 0
Material translucent y modo (mas abajo) surface translucent volume
Metalic 0.8
Roughness 0
opcaity 0.5

Lit>optimization viewport>shader complexity

Material Agua
Translucent volumetric directional
Linear interpolate para alternar 2 colores
Fresnel conectado al alpha
Multiply con el lerp y el depthfade
 adjunto captura porque pfff

 par englobar cosas en nodos comentarios rpesion C y listo
Se puede forzar a activar refraccion si no está bajando y activandola a mano