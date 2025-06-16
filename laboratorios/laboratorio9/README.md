# Proyecto - Laboratorio 8

## Profesor: Esteban Badilla Alvarado 

## Integrantes:

- Emmanuel Avilés Ramírez (C20883) 
- Diego Acosta Obando (C00041)
- Josue Zúñiga Jiménez (B98738)

### Descripción:

**EIEInfo** es el sistema de información oficial de la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica. Este sistema fue desarrollado internamente para cubrir las necesidades administrativas, académicas y de extensión de la unidad.

Su backend está construido sobre **Django** y emplea una arquitectura modular con integración a servicios externos como Google y Facebook. El despliegue se realiza en servidores de la escuela, utilizando tecnologías como **NGINX**, **Gunicorn**, y **Docker** para pruebas.



### Diagrama de la arquitectura:

![Diagrama](https://github.com/emmanuelavilesucr/ie0417/blob/main/laboratorios/laboratorio9/Imagenes/Diagrama.jpeg)


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
