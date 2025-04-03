# Tarea 1 - IE0417

## Profesor: Esteban Badilla Alvarado 

## Asistente: Brenda Castro 

## Estudiante: Emmanuel Aviles Ramirez 




### 1. Herramientas de gestión de proyectos de software (tecnología de apoyo) 

#### - Breve descripción de cada herramienta.

**1. Adobe Workfront:** Esta herramienta consiste en un planificador, cuya función es elaborar un sistema de registro al integrar la opción de trabajo entre equipos con el sistema de gestion. 

**2. Asana:** Es un Software de gestion de proyectos utilizado en la gestion de proyectos, enfocado en la eficiencia y simplificación del trabajo. Este software ofrece un seguimiento detallado del proyecto.

**3. Microsoft Project:** Es un software diseñado por Microsoft, con fin de organizar, planificar y gestionar proyectos y programas. Este asistente a los organizadores asignar tareas, estimar costos y generar informes detallados de cada etapa del proyecto. Es Software puede ser utilizado tanto de forma online como offline por medio de la nube.

 
#### - Principales funcionalidades. 

**1.** Permiten gestionar proyectos de desarrollo de software en tareas, subtareas y actividades. Tambien se pueden establecer plazos concretos para cada fase del proyecto y la distribución de cada tarea a cada miembro del grupo. 

**2.** Permiten el seguimiento del progreso visual detallado de cada fase del proyecto. Esto se realiza mediante Diagramas de Gantt y tableros Kanban, los cuales poseen métricas de desempeño, porcentaje completado y tiempo transcurrido del proyecto.

**3.** Facilitan la organización y comunicación entre los miembros del grupo de trabajo mediante comentarios y actualizaciones del proyecto en tiempo real. Por otro lado, permiten compartir documentación entre miembros del equipo. 


#### - Relación con metodologías ágiles (por ejemplo: cómo se implementan Scrum o Kanban en la herramienta).

###### Scrum:

**1. Adobe Workfront:** Esta herraminta no fue desarrollada pensando exclusivamente en Scrum, pero posee muchas funcionalidades que permite emplearlo como Scrum. La organizacion de tareas, la visibilidad del flujo de trabajo y el seguimiento de los sprints, son algunas de las funcionalidades de posee Adobe Workfront que permite que sea utilizado bajo la metodologia de **Scrum**.

**2. Asana:** No posee tableros de **Scrum**, pero se puede utilizar los tableros **Kanban** para visualizar las tareas de los sprints y organizar el flujo de historias, tareas y subtareas.

**3. Microsoft Project:** Este software si posee soporte **Scrum**, pudiéndose realizar todo el flujo de **Scrum**, desde el backlog del producto hasta los sprints y la asignación de roles del equipo. 

###### Kanban:

**1. Adobe Workfront:** Posee un tablero **Kanban**, que es presentado con columnas de Pendiente, En progreso y Completado, facilitando el ciclo de trabajo. 

**2. Asana:** Posee un tablero nativo especializado en **Kanban**, organizado por medio de columnas. Además, se pueden añadir subtareas, comentarios y fechas de vencimiento.

**3. Microsoft Project:** No posee un soporte directo a **Kanban**, pero en el software se puede realizar una organización por medio de fases y visualizarlas por medio de gráficos o tableros. Además, este software permite integrar herramientas externas como **Trello**, el cual esta especializada en **Kanban**.
 


#### - Comparación entre ellas en cuanto a facilidad de uso, integración con otras plataformas, popularidad, entre otros.  Ejemplos sugeridos: Jira, Azure DevOps, Trello, GitHub Projects, Monday.com, ClickUp, etc. 

**1. Adobe Workfront:** Posee compatibilidad con Jira y Slack.
**2. Asana:** Compatibilidad con Azure Devops y ClickUp.
**3. Microsoft Project:** Compatibilidad con Trello, Githud Projects y Azure Devops.



### 2. Marco teórico profundo de Scrum y Kanban 

#### - Historia y origen del enfoque. 

**Scrum:** Esta metodología nace en 1986 en un articulo llamado **The New New Product Development Game" publicado por Hirotaka Takeuchi y Ikujiro Nonaka. En este articulo los autores exponen la importancia de los enfoques agiles en la gestion de proyectos, basado en pequeños equipos organizados. Aunado a esto, en 1990 Ken SchWaber y Jeff Sutherland, adoptaron este enfoque de trabajo estableciendo roles, artefactos y ceremonias, con el fin de aumentar la eficiencia de la producción en proyectos grandes y complejos. 


**Kanban:** Este enfoque proviene de la vision de producción Toyotista. Taiichi Ohno, quien de diseño el sistema de producción de Toyota también, también llamado **TPS**, también es reconocido por utilizar la metodología **Kanban** en su sistema. Por otro lado, el termino "Kanban" se refiere a una señal visual, ya que esta metodología se refiere a un sistema de gestion del flujo de trabajo implementado por Toyota en 1940, para optimizar los costos y rapidez del proceso de manufactura.   


#### - Principios fundamentales. 

**Scrum:** Transparencia, Inspección, Adaptación.

**Kanban:** Visualización, Gestion del flujo, Limitación del trabajo en progreso (WIP), Mejora continua.


#### - Estructura del trabajo (roles, artefactos, ceremonias en Scrum; columnas, flujo, WIP en Kanban).
 

  
|              |                                                  **Scrum**                                                |                             **Kanban**                                    |
|--------------|-----------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
|**Roles**     | - Owner: Es el encargado de la vision del proyecto                                                        | - No posee                                                                |
|              | - Scrum Master:                                                                                           |                                                                           |
|              | - Equipo de desarrollo: Se encarga del                                                                    |                                                                           |
|**Artefactos**| - Product Backlog: Es una lista de características y mejoras para un producto.                            | - No posee                                                                |
|              | - Sprint Backlog: Son una serie de tareas que fueron seleccionadas en el Product Backlog para el sprint.  |                                                                           |
|              | - Incremento: Resultado del trabajo en cada sprint.                                                       |                                                                           |
|              |                                                                                                           |                                                                           | 
|**Ceremonias**|  - Sprint Planning: Reunion de planificación del trabajo en el sprint.                                    | - No posee                                                                |
|              |  - Daily Standup: Es una reunion para evaluar los avances diarios                                         |                                                                                                                                         |
|              |  - Sprint Review: Reunion al final de cada sprint para evaluar si las tareas fueron completadas.          |                                                                                                                                         |
|              |  - Sprint Retrospective: El fin de esta reunion es realizar una autocritica del tabajo realizado.         |                                                                                                                                         |
|**Columnas**  |                                          No posee                                                         | - Las tareas se visualizan por medio de una conjunto de columnas    en un tablero dividido en: "Por hacer", "En progreso","Completado".                                                                                                                                                                                                                                                                        
|**Flujo**     | - No posee                                                                                                | - Posee un flujo continuo y desacuerdo a la tarea, se gestionan por columnas.                                                            |
|**WIP**       | - No posee                                                                                                | - Esta limitado en cada columna para evitar cuellos de botella.                                                                          |





#### - Ventajas y limitaciones de cada uno. 

   
|              |            **Scrum:**              |                                                                       **Kanban:**                                                                                               |
|--------------|------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------| 
| Ventajas     | - Colaboración eficaz entre grupos.| - Otorga flexibilidad al no definir rolesclaros.                                                                                                                                  |                                                                   
|              | - Proporciona una distribución clara del trabajo por medio de roles. | - Permite visualizar claramente el flujo de trabajo por medio de tableros.                                          
|              |                                                                                         |                                                                                                                                                                           |
|Limitaciones  | - Requiere mucha coordinación entre los miembros para organizar las reuniones.          | - La falta de reuniones puede provocar una comunicación poco eficiente entre los miembros del grupo de trabajo.                                                                    |
|              | - Es una metodología muy rigida, dado a sus roles y reuniones fijas.                    | - Esta metodología depende del compromiso de cada uno de los miembros, dado a que la falta de disciplina y compromiso de los miembros puede perjudicar el desarrollo del proyecto. |                                                                        
|              |                                                                                         |                                                                                                                                                                                    |



#### - Cuándo es más adecuado utilizar uno u otro. 

**Scrum:** A diferencia de Kanban es un marco de trabajo mas rígido. Esta metodología se recomienda en casos de proyectos de un alcance ya establecido por las empresas. En esta metologia se establecen una serie de roles, ceremonias y artefactos fijos, por medio de ciclos con fechas de entrega de las tareas.  

**Kanban:** Esta metodología es mas adecuada cuando los proyectos no tiene flujos de trabajo definidos, como en labores de soporte técnico. Tambien, Kanban es adecuada cuando se necesita flexibilizar la gestion del trabajo lo que permite un marco de innovación en los grupos de trabajo. 



### 3. Casos reales de aplicación en la industria 

#### ¿Qué marco de trabajo utilizan? ¿Scrum, Kanban, una combinación, u otro? 

- La metodologías **Agiles** utilizada en Spotify es una combinación entre Scrum y Kanban, dado a que esta empresa organiza su personal en grupos o equipos con el fin promover la eficiencia. Además, cada grupo o equipo posee total autonomía en la distribución del trabajo lo que fomenta la innovación y adaptabilidad.


#### ¿Qué herramientas tecnológicas usan para gestionarlo? 

- Dado a la libertad de gestion de tareas de cada grupo de trabajo, **Spotify** no cuenta con una herramienta especifica.  


#### ¿Cómo adaptan las metodologías a su cultura organizacional? 

- La cultura organizacional de **Spotify** permite una gran adaptabilidad a las demandas del mercado, debido a su cultura descentralizada que promueve la innovación de los grupos de trabajo.

#### ¿Qué beneficios o retos han reportado? 

**- Beneficios:** Mayor eficiencia en el desarrollo de proyectos y adaptabilidad a las demandas del mercado mediante el fomento de una cultural laboral basada el la libertad de distribución de tareas.

**- Retos:** La comunicación y organización entre los diferentes grupos de trabajo que conforman la empresa.

#### Reflexión crítica: ¿qué se puede aprender de este caso? 

- El sistema descentralizado y de libre gestion utilizado por **Spotify**, aunque puede ser una propuesta innovadora para atender las demandas del mercado, dificulta la organización y comunicación entre los grupos que conforman la empresa, los cuales deben de compartir un conjunto de misiones y visiones de la empresa. 




# Referencias Bibliográficas:

- Adobe for Business. Planifica, asigna y ejecuta desde unico lugar. https://business.adobe.com/es/products/workfront.html

- Asana. Gestiona tus proyectos de manera eficiente, incluso cuando cambien las prioridades.  https://asana.com/es/uses/project-management

- Microsoft. Microsoft Project para la web. https://www.microsoft.com/es-es/microsoft-365/planner/microsoft-project

- Cruch, M. Descubre el modelo de Spotify. Atlassian. https://www.atlassian.com/es/agile/agile-at-scale/spotify

