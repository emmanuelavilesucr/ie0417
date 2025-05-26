import time
import psycopg
from psycopg import OperationalError

MAX_RETRIES = 10

while True:
    try:
        conn = psycopg.connect(
            host="db",
            dbname="iotdb",
            user="postgres",
            password="postgres",
            port=5432
        )
        conn.close()
        break
    except OperationalError:
        MAX_RETRIES -= 1
        if MAX_RETRIES <= 0:
            print("❌ No se pudo conectar a la base de datos.")
            exit(1)
        print("⏳ Esperando conexión a la base de datos...")
        time.sleep(1)
