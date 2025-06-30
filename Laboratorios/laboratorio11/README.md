# 📄 Propuesta de Mejora Técnica – Plataforma EIEInfo  
**Semana 3 (23–29 de junio)**  
**Fecha de entrega: 29 de junio**

## Profesor: Esteban Badilla Alvarado 

## Integrantes:

- Emmanuel Avilés Ramírez (C20883) 
- Diego Acosta Obando (C00041)
- Josue Zúñiga Jiménez (B98738)

---

## 1. Objetivo  

El presente documento tiene como propósito identificar e implementar al menos tres mejoras técnicas, respaldadas por evidencia empírica obtenida a partir de entrevistas, análisis estático con herramientas como SonarQube y principios reconocidos de ingeniería de software. El objetivo es optimizar la **funcionalidad, seguridad y usabilidad** del sistema EIEInfo, elevando así su calidad técnica y experiencia de usuario.

---

## 2. Áreas de Mejora Identificadas

### Mejora 1: Implementación de pruebas automatizadas (Testing Coverage)  

**Evidencia Técnica:**  
- **Cobertura actual de pruebas:** 0.0% (SonarQube).  
- **Riesgo asociado:** Alta probabilidad de defectos no identificados antes del despliegue en producción.

**Justificación Técnica:**  
La cobertura de pruebas (code coverage) permite cuantificar la proporción del código fuente que ha sido verificada mediante pruebas automatizadas. Una cobertura adecuada contribuye significativamente a la estabilidad del sistema, facilita el mantenimiento y reduce el costo de errores en etapas avanzadas del ciclo de vida del software.

Implementar herramientas como `coverage.py` para código Python y `Ranorex Studio` para pruebas funcionales de GUI garantiza un enfoque integral, abarcando tanto el backend como la interfaz gráfica del usuario.

**Herramientas Sugeridas:**  
- `coverage.py` – Para análisis de cobertura de pruebas unitarias.  
- `Ranorex Studio` – Para pruebas automatizadas de interfaces gráficas.  

**Ejemplo Técnico:**
```python
def test_usuario_login_exitoso():
    usuario = crear_usuario("profesora", "contrasena123")
    resultado = login(usuario.nombre, "contrasena123")
    assert resultado is True
```

---

### Mejora 2: Refactorización para reducir duplicación de código  

**Evidencia Técnica:**  
- **Porcentaje de duplicación:** 29.3% en 279,000 líneas de código (SonarQube).  

**Justificación Técnica:**  
El principio **DRY (Don't Repeat Yourself)** es un pilar fundamental del diseño limpio y sostenible. La duplicación excesiva no solo incrementa la deuda técnica, sino que también eleva el riesgo de inconsistencias lógicas y errores al modificar el sistema.

Mediante la reutilización de componentes y plantillas base, se garantiza un sistema más limpio, mantenible y coherente.

**Ejemplo Técnico:**
```html
<!-- Código duplicado antes -->
<div class="usuario-card">
  <h3>{{ usuario.nombre }}</h3>
  <p>{{ usuario.rol }}</p>
</div>

<!-- Reutilización con plantilla -->
{% include "components/usuario_card.html" %}
```

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
- Configuración adecuada de políticas **CORS** y **encriptación HTTPS**.  
- Uso de tokens temporales y autenticación basada en sesiones.

**Ejemplo Técnico:**
```python
# Validación segura de nombre de usuario
if not re.match(r'^[a-zA-Z0-9_]+$', nombre_usuario):
    raise ValidationError("Nombre de usuario inválido.")

# Generación de token seguro
import secrets
token = secrets.token_urlsafe(32)
```

---

## 3. Maqueta / Diagrama del Rediseño de Autenticación  

A continuación se presenta una propuesta de rediseño para el flujo de autenticación, incorporando validaciones robustas y manejo seguro de credenciales:

```
[ Usuario ]
    |
    v
[ Formulario de Login ] --> Validación: regex + límites de longitud
    |
    v
[ Backend ] --> Verificación con bcrypt <--> [ Base de Datos ]
    |
    v
[ Generación de Token de Sesión ] --> Encriptado, expiración automática
    |
    v
[ Redirección a Zona Segura ]
```

---

## 4. Análisis de Impacto: Costo vs. Beneficio  

| Propuesta                            | Costo (Tiempo / Recursos)   | Beneficio Directo                                 | Viabilidad |
|-------------------------------------|------------------------------|---------------------------------------------------|------------|
| Automatización de pruebas           | Medio (inicial)              | Prevención de errores, agilidad en desarrollo     | Alta       |
| Refactorización de código duplicado | Medio                        | Mejora de mantenimiento, reducción de errores     | Alta       |
| Refuerzo de seguridad               | Medio - Alto (según alcance) | Protección de datos sensibles, confianza del usuario | Alta    |

---

## 5. Conclusión  

Las mejoras propuestas no solo abordan debilidades técnicas identificadas objetivamente a través de herramientas como SonarQube y entrevistas a usuarios clave, sino que representan un avance tangible hacia la profesionalización de la plataforma EIEInfo. 

Al implementar pruebas automatizadas, eliminar código redundante y fortalecer la seguridad, se garantiza un sistema más **estable, escalable y confiable**, alineado con las mejores prácticas del desarrollo de software moderno.

Estas acciones no solo beneficiarán al equipo de desarrollo, sino también a todos los usuarios finales, quienes experimentarán una plataforma más fluida, segura y robusta.

---

---

## 6. Diagramas Técnicos Complementarios

### Diagrama de Arquitectura Propuesta (Simplificada)
```
                +---------------------+
                |   Navegador Web     |
                +---------+-----------+
                          |
                          v
                +---------+-----------+
                |     Servidor Web     |
                | (Django / Flask API) |
                +---------+-----------+
                          |
        +-----------------+-----------------+
        |                                   |
        v                                   v
+---------------+                 +------------------+
| Motor de Base |                 | Servicios Externos|
|   de Datos    |                 | (Auth, Email, etc)|
+---------------+                 +------------------+
```

---

### Diagrama de Seguridad: Flujo de Prevención XSS y SQLi

```
[ Usuario ]
    |
    v
[ Formulario Web ]
    |
    v
[ Validación del Lado del Cliente (JS) ]
    |
    v
[ Backend ]
  |- Escapa caracteres peligrosos (XSS)
  |- Prepara consultas parametrizadas (SQLi)
    |
    v
[ Base de Datos ]
```

---

## 7. Fragmentos de Código Adicionales

### Validación Extendida de Inputs (XSS y Longitud)

```python
from django.core.exceptions import ValidationError
import re

def validar_input_usuario(input_str):
    if not re.match(r'^[a-zA-Z0-9_.-]{4,30}$', input_str):
        raise ValidationError("Input inválido: solo se permiten letras, números y ciertos caracteres.")
```

### Generación y Validación de Tokens de Sesión

```python
import secrets
from datetime import datetime, timedelta

def generar_token_seguro():
    return secrets.token_urlsafe(32)

def token_valido(fecha_creacion, duracion_minutos=30):
    return datetime.now() < fecha_creacion + timedelta(minutes=duracion_minutos)
```

### Pruebas Unitarias Adicionales

```python
def test_validar_input_usuario_valido():
    assert validar_input_usuario("usuario_123") is None

def test_validar_input_usuario_invalido():
    try:
        validar_input_usuario("<<script>>")
    except ValidationError as e:
        assert str(e) == "['Input inválido: solo se permiten letras, números y ciertos caracteres.']"
```

### Refactorización con Componentes Reutilizables (Frontend - HTML + Jinja2)

```html
<!-- components/usuario_card.html -->
<div class="usuario-card">
  <h3>{{ usuario.nombre }}</h3>
  <p>{{ usuario.rol }}</p>
</div>

<!-- uso -->
{% include "components/usuario_card.html" %}
```

---

## 8. Recomendaciones Futuras

- Incorporar integración continua (CI) para ejecutar pruebas automáticamente en cada commit.
- Añadir análisis dinámico de seguridad (DAST) con herramientas como OWASP ZAP.
- Implementar logging centralizado con auditoría de eventos sensibles.
- Establecer un pipeline DevSecOps para prevenir problemas de seguridad desde etapas tempranas.

---
