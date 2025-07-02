# Propuesta de Mejora Técnica – Plataforma EIEInfo  
**Semana 3 (23–29 de junio)**  
**Fecha de entrega: 29 de junio**

## Profesor: Esteban Badilla Alvarado 

## Integrantes:

- Emmanuel Avilés Ramírez (C20883) 
- Diego Acosta Obando (C00041)
- Josue Zúñiga Jiménez (B98738)

---

## 1. Objetivo  

- Esta fase del proyecto tiene como propósito identificar e implementar mejoras técnicas, respaldadas por evidencia empírica obtenida a partir de entrevistas, análisis estático con herramientas como SonarQube y principios reconocidos de ingeniería de software. El objetivo es optimizar la **funcionalidad, seguridad y usabilidad** del sistema EIEInfo, elevando así su calidad técnica y experiencia de usuario.

---

## 2. Áreas de Mejora Identificadas

### Mejora 1: Implementación de pruebas automatizadas (Testing Coverage)  

**Evidencia Técnica:**  
- **Cobertura actual de pruebas:** 0.0% (SonarQube).  
- **Riesgo asociado:** Aumenta la probabilidad de defectos no identificados antes del despliegue en producción.

**Justificación Técnica:**  
La cobertura de pruebas (code coverage) permite cuantificar la proporción del código fuente que ha sido verificada mediante pruebas automatizadas. Una cobertura adecuada contribuye significativamente a la estabilidad del sistema, facilita el mantenimiento y reduce el costo de errores en etapas avanzadas del ciclo de vida del software.

**Medidas Propuestas:**
Implementar herramientas como `coverage.py` para código Python y el software `Ranorex Studio` para pruebas funcionales de GUI garantiza un enfoque integral, abarcando tanto el backend como la interfaz gráfica del usuario.  
- `coverage.py` – Para análisis de cobertura de pruebas unitarias.  
- `Ranorex Studio` – Para pruebas automatizadas de interfaces gráficas.  

---

### Mejora 2: Refactorización para reducir duplicación de código  

**Evidencia Técnica:**  
- **Porcentaje de duplicación:** 29.3% en 279,000 líneas de código (SonarQube). 
- **Riesgo asociado:** Aumenta la deuda tecnica y aumenta la posiblidad de un mal rendimiento del sistema. 

**Justificación Técnica:**  
- El principio **DRY (Don't Repeat Yourself)** es un pilar fundamental del diseño limpio y sostenible. La duplicación excesiva no solo incrementa la deuda técnica, sino que también eleva el riesgo de inconsistencias lógicas y errores al modificar el sistema. Mediante la reutilización de componentes y plantillas base, se garantiza un sistema más limpio, mantenible y coherente.

**Medidas Propuestas:**
- Implementacion de herramientas como **flake8** para hallar de forma precisa patrones de codigo erroneos.
- Implementar el de **jscpd** para dectar y corregir duplicidad estructural.
---

### Mejora 3: Corrección de vulnerabilidades críticas de seguridad  

**Evidencia Técnica:**  
- **Vulnerabilidades registradas:** 377 issues de seguridad.  
- **Problemas tipo Blocker:** 67 (SonarQube).  


**Justificación Técnica:**  
Las vulnerabilidades de seguridad representan un riesgo significativo para la integridad del sistema y la privacidad de los datos de los usuarios. En particular, se identificaron posibles vectores de ataque como **Cross-Site Scripting (XSS)**, **inyecciones SQL**, y falta de **hashing seguro** de contraseñas.

**Medidas Propuestas:**  
- Validación estricta de entradas del usuario mediante expresiones regulares.  
- Implementación de hashing con **bcrypt** y uso de tokens seguros.   
- Uso de tokens temporales y autenticación basada en sesiones.

**Diagrama del Rediseño:** 

![Diagrama del Rediseño de Autenticación](Imagenes/DiagRediseñoAuth.png)

![Diagrama de Seguridad](Imagenes/DiagSeguridad.png)

---

## 4. Análisis de Impacto: Costo vs. Beneficio  

| Propuesta                            | Costo (Tiempo / Recursos)   | Beneficio Directo                                 | Viabilidad |
|-------------------------------------|------------------------------|---------------------------------------------------|------------|
| Automatización de pruebas           | Medio (inicial)              | Prevención de errores, agilidad en desarrollo     | Alta       |
| Refactorización de código duplicado | Medio                        | Mejora de mantenimiento, reducción de errores     | Alta       |
| Refuerzo de seguridad               | Medio - Alto (según alcance) | Protección de datos sensibles, confianza del usuario | Alta    |

---

## 5. Diagramas de Arquitectura:

![Diagrama de ARquitectura Propuesta](Imagenes/DiagArqProp.png)

---

## 7. Conclusión  

- Las mejoras propuestas no solo abordan debilidades técnicas identificadas a través de herramientas como SonarQube y entrevistas a tipos distintos de usuarios, sino que representan un avance tangible hacia una verdadera mejora de la página de la escuela, de lo cual todos nos beneficiamos.  
Al implementar pruebas automatizadas, eliminar código redundante y fortalecer la seguridad, se garantiza un sistema más **estable, escalable y confiable**, alineado con las mejores prácticas del desarrollo de software moderno.Estas acciones no solo beneficiarán al equipo de desarrollo, sino también a todos los usuarios finales, quienes experimentarán una plataforma más fluida, segura y robusta.

---

## 8. Recomendaciones Futuras


 - **Calidad de código**  Configurar **pre-commit hooks** con `black`, `isort`, `flake8`. Estilo uniforme y menos errores triviales. 
 - **Pruebas GUI esenciales** Scripts con **Selenium WebDriver** (login y CRUD principal) ejecutados en GitHub Actions. 
 - **Seguridad automatizada**  Incluir **Bandit**  u **OWASP ZAP** . Bloquea vulnerabilidades evidentes (XSS, SQLi) antes de producción. 
 - **HTTPS sin costo** Certificados **Let’s Encrypt** con renovación automática (`cron`) o servir front estático via GitHub Pages. 
 - **Logs útiles**  Activar `logging` con `RotatingFileHandler`; formato JSON. Facilita depuración y auditoría básica. |
 - **Documentación viva**  Mantener una wiki. 
---
