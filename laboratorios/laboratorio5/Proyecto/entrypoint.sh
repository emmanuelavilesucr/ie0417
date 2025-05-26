#!/bin/sh

# Esperar a PostgreSQL con script Python
echo "🔄 Esperando base de datos..."
python wait_for_db.py

# Migraciones
echo "📦 Ejecutando migraciones..."
python manage.py migrate --noinput

# Archivos estáticos
echo "🎨 Recolectando archivos estáticos..."
python manage.py collectstatic --noinput

python manage.py loaddata initial_sensors

python manage.py loaddata initial_actuators

# Ejecutar el servidor
echo "🚀 Iniciando servidor..."
exec gunicorn iot_ucr.wsgi:application --bind 0.0.0.0:8000
