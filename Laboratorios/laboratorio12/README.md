# Proyecto - Informe Técnico
## Profesor: Esteban Badilla Alvarado
## Integrantes:
- Emmanuel Avilés Ramírez (C20883)
- Diego Acosta Obando (C00041)
- Josue Zúñiga Jiménez (B98738)

### Descripción:

El presente proyecto se enfoca en el análisis técnico del sistema **EIEInfo**, una plataforma desarrollada por la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica. El objetivo principal es comprender a fondo cómo está construido este sistema, evaluar su calidad técnica y funcional, y proponer mejoras que puedan contribuir a su evolución y mantenimiento a largo plazo.
El sistema **EIEInfo** es bastante amplio. No solo gestiona procesos académicos como matrícula y notas, sino que también da soporte a funciones administrativas, de extensión y comunicación interna. A lo largo del curso, el enfoque será actuar como un equipo de consultores que entra a revisar un sistema real, tratando de entender su estructura, cómo fue diseñado, qué tan bien está escrito el código, cómo se despliega y mantiene, y qué tan preparado está para seguir creciendo o adaptarse. 
El sistema está diseñado en **Django**, concretamente su Backend, lo cual da un buen punto de partida porque se trata de un framework robusto, pero también es importante reconocer que al ser un desarrollo hecho por el equipo interno de la escuela, puede haber áreas que no siguen todas las mejores prácticas modernas, especialmente en cuanto a modularidad, documentación o pruebas automatizadas. Por otro lado, el sistema **EIEInfo** emplea la integración de servicios externos como Google y Facebook, utilizando tecnologías como **NGINX**, **Gunicorn**, y **Docker**.



### Diagrama de la arquitectura lógica:

![Diagrama de arquitectura lógica](Imagenes/DiagramaArqLogica.jpeg)

### Diagrama de la arquitectura física:

![Diagrama de arquitectura física](Imagenes/DiagramaArqFisica.jpeg)


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

![PlanDeTrabajo](Imagenes/DiagramaDeGantt.jpeg)


# Evaluación de Usuario – Plataforma EIEInfo

Este documento resume las entrevistas realizadas a dos usuarios de la plataforma EIEInfo: una profesora interina y un estudiante de Ingeniería Eléctrica. El objetivo es identificar fortalezas, debilidades y oportunidades de mejora en la experiencia de uso del sistema.

---

## 👩‍🏫 Usuario 1: Sofía Villalobos Brenes  
**Rol:** Profesora Interina

### Frecuencia de uso
- Aproximadamente 1 vez al mes.

### Funciones más utilizadas
- Consulta de información de contacto.

### Problemas reportados
- Caídas ocasionales de la plataforma.

### Opinión sobre velocidad y confiabilidad
- Considera el sistema como “normal” en rendimiento.

### Sugerencias de mejora
- Incluir una sección de noticias actualizada.
- Mejorar la sección de graduación para evitar consultas a secretaría.
- Eliminar la sección de empleo EIE (ya obsoleta frente a Alumni).
- Ampliar la información sobre práctica profesional (especialmente en el formulario de inicio).

### Facilidad de uso
- Fácil de usar.

### Reportes realizados
- Ha reportado problemas, pero no recuerda detalles.

### Importancia del sistema
> “Me parece que es la mejor forma de hacer que los estudiantes puedan conseguir la información sin necesidad de estar preguntando a los administrativos que ya tienen bastante trabajo :)”

---

## 👨‍🎓 Usuario 2: Santiago Arias  
**Rol:** Estudiante de Ingeniería Eléctrica

### Frecuencia de uso
- Uso ocasional: principalmente para historial académico y constancias.

### Funciones más utilizadas
- Resumen de cursos aprobados y pendientes.
- Consulta de notas de cursos anteriores.

### Problemas reportados
- Caídas esporádicas del sitio.

### Opinión sobre velocidad y confiabilidad
- Generalmente carga rápido.

### Sugerencias de mejora
- Modernizar la interfaz (dashboard o app móvil).
- Incluir una guía de uso o tutorial.
- Mejorar el sistema de búsqueda interna.

### Facilidad de uso
- La navegación no es intuitiva al inicio; se aprende por experiencia.

### Reportes realizados
- No ha reportado problemas formalmente.

### Importancia del sistema
> “Es el sistema base de la carrera, sin eso andaría bastante perdido.”

---

## 👩 Usuario 3: Margie Sánchez Chavarría
**Rol:** Recepcionista 

### Proceso mas complejo 
- Tramites relacionados con matriculas de inclusion y estudios de graduacion.
> “La escuela ha facilitado el formulario que esta en la pagina.”

### Procesos administrativos 
- Se realiza atencion de tramites de forma presencial en secretaria, por medio de la central telefonica y por  medio del correo oficial de la escuela.
  
### Tiempo del proceso
- Ya sea por telefono, correo o de forma presencial depende del tipo de consulta, ya que hay algunas rapidas y otras mas largas. 

### Consultas mas comunes por parte del estudiantado
- Tramites de graduacion. 
- Procedimiento EXMAA.
- Decuaciones curriculares.
- Plan de accion Individual.
- Consultas de practica profesional.
---

## 🧩 Resumen de Hallazgos Clave

- La plataforma es **fundamental** para la gestión académica tanto para docentes como estudiantes.
- Las funciones principales **son útiles y valoradas**, pero el sistema presenta **limitaciones en experiencia de usuario**.
- Se identifican problemas recurrentes como **caídas del sistema** y **falta de soporte interactivo**.
- Se recomienda:
  - Mejorar la **usabilidad y diseño**, adaptándolo a estándares modernos de UX.
  - Incluir **notificaciones automáticas** y una **búsqueda eficiente**.
  - Eliminar secciones obsoletas y **mantener actualizada la información clave**.
  - Desarrollar una **versión móvil oficial** o aplicación complementaria.

---

> Este documento forma parte de un proceso de mejora continua de la plataforma EIEInfo y busca visibilizar la voz de sus usuarios para futuras decisiones de diseño y desarrollo.

