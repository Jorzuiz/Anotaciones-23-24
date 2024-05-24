# Continuous Integration tool for Godot using Jenkins

Se plantea una herramienta de integración continua para Godot usando Jenkins.
Se configurará una plantilla de ejemplo en godot para al menos una plataforma. La integración continua se implementará usando Jenkins. Jenkins corre como proceso local y mediante plugins realiza acciones. Jenkins correrá en una red local, dos ordenadores conectados al mismo router.

## Godot Engine 4.2.2

- Godot corre en un ejecutable autocontenido (Open Source, no requiere instalación)
- Existe ejecutable para version GUI  y para version consola de comandos (headless en modo consola)
- Godot crea un proyecto llamado template, este se modifica con el ejecutable (Tanto consola como GUI)
- El template puede ser compilado/construido de diferentes formas/maneras para diversas plataformas
- La informacion de build de template tiene que settearse inicialmente/de manera manual antes de llamar a la build

- El repo estará en GitHub (Microsoft)
- El git es preferible para equipos pequeños con mucha responsabilidad, descarga el repo entero

## Jenkins 2452.1

- Podría tirar en Gitub Actions pero no es nuestro (Microsoft)
- La automatizacion va por Jenkins, primer paso para montar ecosistema propio (Open Source)
- Jenkins necesita correr en un servidor, este puede ser propio (controlamos los datos)
- Jenkins usa lenguaje de scripting, groovy, con sintaxis de Java
- Compatible con centenaroes de plugins, uno de ellos Github
- El plugin de jenkins desencadena los jobs que configuremos

## Jenkins - Automatization Tool

- https://stackoverflow.com/questions/63410442/jenkins-installation-windows-10-service-logon-credentials

## Godot Engine - Open Source game engine

- [Exportar plantillas](https://docs.godotengine.org/en/stable/tutorials/export/exporting_projects.html)  ==Incluye codificación para el exe==
- [Video build desde CMD](https://www.youtube.com/watch?v=qXBVrM9BHcQ)
- [Correr Godot desde Linea de Comandos](https://docs.godotengine.org/en/stable/tutorials/editor/command_line_tutorial.html)
- [Build desde linea de comandos en GitHub](https://github.com/slapin/godot-templates-build/blob/master/Jenkinsfile)

|Lunes|Martes|Miercoles|Jueves|Viernes|Sabado|Domingo|Planificacion|
|---|---|---|---|---|---|---|---|
|||||24|25|26|Repositorio inicial. Plantilla de Godot|
|26|27|28|29|30|31|1| Godot - Builds por scripting (Windows+plataforma extra) |
|2|3|4|5|6|7|8| Jenkins - Configuración de plugin Github / Jobs de build |
|9|10|11|12|13|14|15| Jenkins - Configuración de servidor. Build en local/ servidor |
|16|17|18|19|20|21|22| Rama secundaria. Jobs en Pull |
|23|24*|25|26|27|28|29|Contingencias/Presentación|
|30|1*||||||Presentación|

>Todo el proceso será acompañado de la documentación tanto en comentarios de código como en el documento final.

>La semana final se terminará la documentación, se creará una infográfica del ciclo de desarrollo y de las pipelines y se preparará la presentación