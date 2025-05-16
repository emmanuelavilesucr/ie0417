# “Patrones de diseño en entrevistas técnicas”

## 1. Investigación
### Buscar al menos 3 preguntas reales de entrevistas (Glassdoor, LeetCode, Discussions, GitHub, libros como Cracking the Coding Interview o Design Patterns Interview Questions). Deben enfocarse en preguntas de diseño de software.

- 1. Describa un escenario donde el patron Strategy seria apropiado y que compensaciones consideraría
- 2. Describa un escenario donde utilizaria el patron Singleton
- 3. ¿Como se puede aplicar el patron Command en un marco de interfaz de usuario (UI)?

## 2. Análisis y aplicación de patrones
### Problema:
- **1. Strategy:** Una tienda en línea desea implementar un sistema de descuentos, como parte de un plan de marketing. Este sistema debe de permitir aplicar distintos tipos de descuentos según el tipo de cliente.

- **2. Singleton:** Se esta desarrollando una aplicación de un banco que  necesita acceder a la base de datos para realizar una serie de operaciones financieras. La aplicación posee multiples módulos que registran los eventos importantes como los errores y advertencias, en un archivo log para la auditoria.

- **3. Command:** Se esta desarrollando un editor de texto, el cual posee tres botones que corresponden a las acciones de cortar, copiar y pegar.


### Patrón de diseño más adecuado:
- **1. Strategy**
- **2. Singleton**
- **3. Command**

### Justificación:
- **1. Strategy:** Se aplica Strategy para separar la logica del carrito principal, sin la necesidad de modificar el carrito para nuevas estrategias, solo se agregaron nuevas clases que implementan la interfaz de usuario mediante el principio de abierto/cerrado.

- **2. Singleton:** La implementación de este patron es conveniente en este caso debido a que Singleton brinda un punto de acceso global desde la instancia de la clase. Lo que facilita la coordinación las diferentes módulos que registran los movimientos en la aplicación del banco. 
 
- **3. Command:** Este patrón es ideal para resolver este problema, dado que Command encapsula solicitudes como objetos y los define como un método sin retorno. Esto funciona para las operaciones como "cortar", "copiar", o "pegar".


### Implementación sencilla del patrón:

- **1. Strategy:**

```python

from abc import ABC, abstractmethod

class DiscountStrategy(ABC):
    @abstractmethod
    def apply_discount(self, total: float) -> float:
        pass

# Sin descuento
class NoDiscount(DiscountStrategy):
    def apply_discount(self, total: float) -> float:
        return total

# Descuento para clientes frecuentes
class LoyaltyDiscount(DiscountStrategy):
    def apply_discount(self, total: float) -> float:
        return total * 0.9

```

- **2. Singleton:**


```python

import threading

class Logger:
    _instance = None
    _lock = threading.Lock()

    def __new__(cls, log_file="app.log"):
        with cls._lock:
            if cls._instance is None:
                cls._instance = super(Logger, cls).__new__(cls)
                cls._instance._initialize(log_file)
        return cls._instance

    def _initialize(self, log_file):
        self.log_file = log_file
        with open(self.log_file, "a") as f:
            f.write("=== Inicio de logging ===\n")

    def log(self, message):
        with open(self.log_file, "a") as f:
            f.write(message + "\n")
```

## 3. Reflexión:

- El tema de  patrones de diseño suele ser un tópico usualmente tocado en las entrevistas de trabajo, dado a que estas no solo suelen ser una prueba de conocimiento técnico sino que también suelen brindar una noción al entrevistador de las habilidades de resolución de problemas de cada entrevistado, en el ámbito del desarrollo de software.
