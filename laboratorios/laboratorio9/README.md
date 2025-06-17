# Proyecto - Laboratorio 9

## Profesor: Esteban Badilla Alvarado 

## Integrantes:

- Emmanuel Avilés Ramírez (C20883) 
- Diego Acosta Obando (C00041)
- Josue Zúñiga Jiménez (B98738)

### Descripción:

El presente proyecto se enfoca en el análisis técnico del sistema **EIEInfo**, una plataforma desarrollada por la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica. El objetivo principal es comprender a fondo cómo está construido este sistema, evaluar su calidad técnica y funcional, y proponer mejoras que puedan contribuir a su evolución y mantenimiento a largo plazo.
El sistema **EIEInfo** es bastante amplio. No solo gestiona procesos académicos como matrícula y notas, sino que también da soporte a funciones administrativas, de extensión y comunicación interna. A lo largo del curso, el enfoque será actuar como un equipo de consultores que entra a revisar un sistema real, tratando de entender su estructura, cómo fue diseñado, qué tan bien está escrito el código, cómo se despliega y mantiene, y qué tan preparado está para seguir creciendo o adaptarse. 
El sistema está diseñado en **Django**, concretamente su Backend, lo cual da un buen punto de partida porque se trata de un framework robusto, pero también es importante reconocer que al ser un desarrollo hecho por el equipo interno de la escuela, puede haber áreas que no siguen todas las mejores prácticas modernas, especialmente en cuanto a modularidad, documentación o pruebas automatizadas. Por otro lado, el sistema **EIEInfo** emplea la integración de servicios externos como Google y Facebook, utilizando tecnologías como **NGINX**, **Gunicorn**, y **Docker**.



### Diagrama de la arquitectura física:

![Diagrama](https://github.com/emmanuelavilesucr/ie0417/blob/main/laboratorios/laboratorio9/Imagenes/Diagrama.jpeg)

### Diagrama de la arquitectura lógica:

![Diagrama](https://github.com/emmanuelavilesucr/ie0417/blob/main/laboratorios/laboratorio9/Imagenes/DiagramaLogica.jpeg)

### Módulos y tecnologías:

| Categoría                | Tecnología                           |
|--------------------------|--------------------------------------|
| Lenguaje Principal       | Python 3.4.3+                        |
| Framework Web            | Django 4.1.3                         |
| Base de Datos            | MySQL                                |
| Servidor de Aplicaciones | Gunicorn                             |
| Servidor Web             | NGINX                                |
| Sistema Operativo        | Linux (Servidor Faraday, con systemd)|
| Despliegue               | Docker (pruebas)                     |
| CI/CD                    | Drone                                |
| Buscador                 | Google Custom Search API             |
| Autenticación Externa    | Facebook API                         |
| Wiki                     | Django-Wiki (fork modificado)        |

| Módulo                     | Función Principal                                                                 |
|---------------------------|------------------------------------------------------------------------------------|
| Gestión Académica         | Matrícula, historial, cursos, calificaciones                                       |
| Perfiles de Usuario       | Roles de estudiante, docente, funcionario                                          |
| Autenticación y Seguridad | Manejo de sesiones y permisos por grupo en Django                                 |
| Comunicación Interna      | Envío de correos y notificaciones (configurable con APIs)                         |
| Educación Continua        | Administración de cursos abiertos y certificados                                  |
| Búsqueda Global           | Búsqueda integrada con Google Custom Search API                                   |
| Documentación y Reportes  | Generación de PDF, LaTeX, Excel, vCards, etc.                                     |
| Administración            | Interfaz administrativa Django para gestión interna                               |
| Archivos y Logs           | Manejo de archivos estáticos y subidos (/var/info)                                |
| Wiki Institucional        | Wiki embebida integrada a la plataforma                                            |



### Plan de trabajo:

![PlanDeTrabajo](https://github.com/emmanuelavilesucr/ie0417/blob/main/laboratorios/laboratorio9/Imagenes/Diagrama%20de%20Gantt.jpeg)
