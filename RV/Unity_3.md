# Unity 3
Creamos plano y añadimos componente cloth
Modificamos los constraints en el primer icono, seleccionamos la parte de la tela que queremos como fija con el modo select
Creamos una esfera y ponemos un material nuevo. La parte de color será una imagen en el Albedo y la Normal en el Normal, si no tenemos podemos generarla con algun enlace (https://cpetry.github.io/NormalMap-Online/)
En el componente cloth cambiamos el Sphere Colliders a 1 y añadimos la esfera en ambos
Sobre la pestaña proyecto clickamos derecho y añadimos la pestalla animator, creamos una nueva animacion para la esfera de modo que interactue con la tela dando vueltas o algo
Para evitar el culling aumentamos el collider de la esfera ligeramente (de 0.5 a 0.6)
