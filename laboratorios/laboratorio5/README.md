
---

## `informe_tecnico`

# Informe Técnico — Proyecto Django + PostgreSQL + Docker

## Arquitectura del Sistema

![image](https://github.com/user-attachments/assets/ae3881b4-3f8c-42ba-a81e-e0125d6865ad)


---

### **Componentes de la Arquitectura**

#### 1. **Sensores y Actuadores**

* **Función**: Dispositivos físicos que:

  * Envían datos (temperatura, humedad, etc.) al servidor.
  * Reciben comandos (encender bomba, activar alarma, etc.) desde el servidor.
* **Comunicación**: Se comunican usando el protocolo **MQTT**, ideal para dispositivos con recursos limitados, baja latencia y red inestable.

#### 2. **Servidor Backend (Django)**

* **Tecnología**: Django con Python + `paho-mqtt` para manejar la lógica del broker.
* **Responsabilidades**:

  * Recibe los datos desde MQTT y los **almacena en base de datos**.
  * Expone una API REST (`/api/latest-readings/`) para el frontend.
  * Permite controlar actuadores (vía comandos MQTT publicados desde Django).
  * Ejecuta procesos programados (compresión de datos, limpieza, generación de históricos).

> Este componente actúa como el **cerebro** del sistema.

---

#### 3. **Base de Datos (PostgreSQL)**

* **Función**: Persistencia de datos.
* **Ventajas** sobre SQLite:

  * Escalabilidad.
  * Transacciones ACID robustas.
  * Concurrencia y rendimiento en producción.
* **Modelo de datos**:

  * `Sensor`, `SensorReading`, `Actuator`, etc.
  * Almacenamiento de lecturas en tiempo real e histórico.

---

#### 4. **Frontend (Usuarios)**

* **Función**: Interfaz web para:

  * Visualizar métricas y lecturas en tiempo real (polling vía JavaScript).
  * Descargar históricos.
  * Activar actuadores.
  * Consultar gráficas.
* **Tecnología**: HTML + JS modular con Chart.js y componentes personalizados.

---

### **Flujo de Datos**

1. **\[MQTT In]**
   Sensores publican en `sensors/+/+`.
   Django suscribe (con un custom management command) y guarda los datos.

2. **\[DB Persistencia]**
   Django guarda en PostgreSQL cada lectura.

3. **\[Frontend]**
   Cliente web consulta `/api/latest-readings/` periódicamente (RealTimeUpdater).

4. **\[MQTT Out]**
   Si un usuario activa un actuador, Django publica vía MQTT a `actuators/...`.

---

### **Servicios de soporte**

* **Mosquitto**: Broker MQTT dentro del entorno Docker, facilitando pub/sub local.
* **Caddy**: Reverse proxy con certificados TLS automáticos para HTTPS.
* **Docker Compose**: Orquestación del stack (web, broker, workers, crons, etc.).

---

### **Buenas prácticas aplicadas**

* Arquitectura modular.
* Separación de preocupaciones (MQTT ≠ API ≠ frontend).
* Escalabilidad (PostgreSQL, microservicios).
* Seguridad (HTTPS, CSRF, `SESSION_COOKIE_SECURE`, `SECURE_SSL_REDIRECT`).
* Observabilidad (logging de componentes).
* Automatización: scripts `management/commands` como workers recurrentes.


* **Contenedor Web**: ejecuta Django, realiza migraciones, sirve archivos estáticos y se comunica con la base de datos.
* **Contenedor DB**: almacena datos persistentes de PostgreSQL.
* **Volúmenes**: aseguran que los datos no se pierdan al reiniciar los contenedores.
* **Red `iot-net`**: permite comunicación entre servicios de forma aislada.

---

## Archivos Clave del Proyecto

### `Dockerfile`

Define cómo construir la imagen de Django, instala dependencias, copia el proyecto y configura el punto de entrada.

```dockerfile
FROM python:3.10-slim
WORKDIR /app
RUN apt-get update && apt-get install -y gcc libpq-dev && pip install --upgrade pip
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY . .
COPY entrypoint.sh /app/entrypoint.sh
RUN chmod +x /app/entrypoint.sh
ENV DJANGO_SETTINGS_MODULE=iot_ucr.settings.dev PYTHONUNBUFFERED=1
ENTRYPOINT ["/app/entrypoint.sh"]
```

---

### `entrypoint.sh`

Script que:

1. Espera la base de datos
2. Ejecuta migraciones
3. Recolecta archivos estáticos
4. Lanza Gunicorn

```bash
#!/bin/sh
python wait_for_db.py
python manage.py migrate --noinput
python manage.py collectstatic --noinput
exec gunicorn iot_ucr.wsgi:application --bind 0.0.0.0:8000
```

---

### `wait_for_db.py`

Evita errores de conexión lanzando Django solo cuando PostgreSQL esté listo.

```python
import time, os, psycopg
from psycopg import OperationalError
# configuración...
```

---

### `docker-compose.yml`

Orquesta los servicios de Django y PostgreSQL, define la red y volúmenes.

```yaml
services:
  web:
    build: .
    ports: ["8000:8000"]
    environment: {...}
    depends_on: [db]
  db:
    image: postgres:15
    environment: {...}
volumes:
  postgres_data:
  static_volume:
networks:
  iot-net:
```

---

### `.env` (opcional)

Archivo con las variables de entorno utilizadas por el contenedor `web`:

```
POSTGRES_DB=iotdb
POSTGRES_USER=postgres
POSTGRES_PASSWORD=postgres
POSTGRES_HOST=db
POSTGRES_PORT=5432
DJANGO_SETTINGS_MODULE=iot_ucr.settings.dev
```

> **Nota de seguridad:**
> En entornos de producción, este tipo de variables sensibles (como contraseñas, usuarios y claves secretas de Django) **no deben almacenarse directamente en archivos `.env` o dentro del repositorio**.
>
> La práctica recomendada es utilizar servicios de **Secret Management** como:
>
> * AWS Secrets Manager
> * Azure Key Vault
> * HashiCorp Vault
> * Docker secrets (para Swarm)
>
> Para efectos de este trabajo académico, se han definido directamente en el archivo `.env` para facilitar la revisión y ejecución sin requerir infraestructura adicional.

---

## Instrucciones para Ejecutar el Proyecto

1. Clonar el repositorio:

```bash
git clone https://github.com/GaboUCR/ie0417.git
cd laboratorios\laboratorio5\IoT
```

2. Crear imagen y contenedores:

```bash
docker-compose build --no-cache
docker-compose up
```

4. Abrir en el navegador:

```
http://localhost:8000
```

---

