# 📄 Propuesta de Mejora Técnica – Plataforma EIEInfo
**Semana 3 (23–29 de junio)**  
**Autores:** Equipo de Evaluación Técnica EIEInfo  
**Fecha de entrega:** 29 de junio  

---

## 1. ✅ Objetivo  
Identificar y proponer al menos tres mejoras técnicas fundamentadas en evidencia (entrevistas, análisis SonarQube y principios de diseño de software) para optimizar el funcionamiento, seguridad y usabilidad de la plataforma EIEInfo.

---

## 2. 📌 Áreas de Mejora Identificadas

### Mejora 1: Implementación de pruebas automatizadas (Testing Coverage)  
**Evidencia:**  
- **Cobertura actual:** 0.0% (SonarQube).  
- Riesgo alto de errores no detectados antes de producción.

**Justificación:**  

- **Testing Coverage:** Se refiere a una forma de cuantificar la parte del Código que se ha probado en tiempo real. Este método consiste en una herramienta de gran utilidad en desarrollo de Software, dado a que ayuda a validar de manera eficaz las diferentes partes del Código, con el fin de identificar brechas en la metodología de pruebas y encontrar errores poco visibles del Código.  La **cobertura de pruebas** expresa un porcentaje, que indica la proporción de elementos probados en comparación con el número total de elementos en la aplicación, en este caso líneas de Código. Lo que quiere decir, que si se tiene 100 líneas de código y sus pruebas cubren 80 de ellas, su cobertura de pruebas es del 80%. 

- La cobertura de pruebas ayuda a identificar partes del código que no han sido tocadas por las pruebas, lo que le permite crear nuevas pruebas para cubrir esas áreas. Además, al analizar la cobertura, puede refinar sus casos de prueba, lo cual ayuda a reducir la probabilidad de que aparezcan defectos en producción. Algunas de la herramientas de testing Coverage son: Ranorex Studio y Coverage.py.

- **Coverage.py** se utilizara para cuantificar la cantidad de duplicidad y mejorar la calidad del código mientras que Ranorex realizara pruebas automatizadas al GUI. 


**Propuesta Técnica (Pseudocódigo):**
```python
def test_usuario_login_exitoso():
    usuario = crear_usuario("profesora", "contrasena123")
    resultado = login(usuario.nombre, "contrasena123")
    assert resultado == True
```

---

### Mejora 2: Refactorización para reducir duplicación de código  
**Evidencia:**  
- 29.3% de duplicación en 279k líneas (SonarQube).  
- Código repetido = mayor riesgo de errores y más tiempo de mantenimiento.

**Justificación:**  
- Seguir principios DRY ("Don't Repeat Yourself").  
- Facilita refactorización futura y mejora mantenibilidad.

**Propuesta Técnica:**
```javascript
// Antes: código duplicado en varias vistas HTML
<div class="usuario-card"> ... </div>

// Después: plantilla base reutilizable
{% include "components/usuario_card.html" %}
```

---

### Mejora 3: Corrección de problemas críticos de seguridad  
**Evidencia:**  
- 377 vulnerabilidades de seguridad y 67 problemas tipo *Blocker* (SonarQube).

**Justificación:**  
- Riesgos de fuga de información.  
- Afecta directamente la confianza de usuarios (como reportó la profesora entrevistada).

**Propuesta Técnica (Checklist):**  

- El programa debe de validar las entradas de usuario para evitar **XSS**, ya que **XSS** es una situación de fuga de información, mediante el cual un atacante inserta scripts maliciosos en formularios o URLs para ejecutar código en el navegador de otros usuarios. Por otro lado, la inyección SQL es otra situación que puede ocurrir, y consiste en una situación manipulación externa maliciosa de consultas SQL para ejecutar comandos no deseados.

- Se implementara encriptación de contraseñas por medio de **Hash** con bcrypt (función de hashing con salting y coste computacional), ya esto le dificulta al atacante obtener la contraseñas e información de la base de datos. Por otro lado, la generacion de tokens seguros, es indispensable para mantener el codigo seguro y evitar fugas de informacion, por medio funciones como desecrets.token_urlsafe().

- Se implemetaran politicas de de control de dominios por medio de **CORS** y HTTPS para la encriptacion de la comunicacion entre el navegador y el servidor. 
  
```python
# Validación de entrada en Django
if not re.match(r'^[a-zA-Z0-9_]+$', nombre_usuario):
    raise ValidationError("Nombre inválido.")
```

---

## 3. 🧩 Maqueta / Diagrama del Rediseño Sugerido

Propuesta parcial del rediseño del flujo de autenticación con medidas de seguridad integradas:

```
[ Usuario ]
    |
    v
[ Formulario de Login ] --> Valida entradas (regex, max-length)
    |
    v
[ Back-end ] --> Verifica hash (bcrypt) <--> [ Base de Datos ]
    |
    v
[ Token de Sesión ] --> Encriptado, con vencimiento automático
```

---

## 4. ⚖️ Análisis de Impacto (Costo - Beneficio)

| Propuesta                            | Costo (Tiempo / Recursos) | Beneficio Directo                        | Viabilidad |
|-------------------------------------|----------------------------|------------------------------------------|------------|
| Testing automatizado                | Medio (configuración inicial) | Reduce bugs en producción                | Alta       |
| Reducción de código duplicado       | Medio                      | Menor carga técnica y más orden interno | Alta       |
| Seguridad (validaciones y hashing)  | Medio                      | Protección de datos, confianza del usuario | Alta    |

---

## 5. 📌 Conclusión  
Las propuestas presentadas no solo responden a problemas identificados mediante entrevistas y herramientas como SonarQube, sino que son soluciones escalables, sostenibles y de alto impacto. Implementarlas aumentaría la calidad percibida y real del sistema EIEInfo, disminuyendo riesgos y mejorando la experiencia de uso.
