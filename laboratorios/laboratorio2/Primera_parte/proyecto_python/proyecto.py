# calculadora.py

def suma(a, b):
    """
    Suma dos números.
    
    Esta función toma dos números de tipo float y retorna su suma.
    
    :param a: Primer número.
    :param b: Segundo número.
    :return: La suma de los dos números.
    """
    return a + b

def resta(a, b):
    """
    Resta dos números.
    
    Esta función toma dos números de tipo float y retorna su resta.
    
    :param a: Primer número.
    :param b: Segundo número.
    :return: La resta de los dos números.
    """
    return a - b

def multiplicacion(a, b):
    """
    Multiplica dos números.
    
    Esta función toma dos números de tipo float y retorna su producto.
    
    :param a: Primer número.
    :param b: Segundo número.
    :return: El producto de los dos números.
    """
    return a * b

def division(a, b):
    """
    Divide dos números.
    
    Esta función toma dos números de tipo float y retorna su división.
    
    :param a: Numerador.
    :param b: Denominador.
    :return: El cociente de la división.
    :raises ValueError: Si el denominador es cero.
    """
    if b == 0:
        raise ValueError("El denominador no puede ser cero.")
    return a / b

if __name__ == "__main__":
    a = 10.0
    b = 5.0

    print("Suma:", suma(a, b))
    print("Resta:", resta(a, b))
    print("Multiplicación:", multiplicacion(a, b))
    try:
        print("División:", division(a, b))
    except ValueError as e:
        print(f"Error: {e}")

