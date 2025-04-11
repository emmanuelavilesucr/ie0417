/**
 * @file calculadora.cpp
 * @brief Implementación de una calculadora básica.
 *
 * Este programa implementa las funciones básicas de una calculadora:
 * suma, resta, multiplicación y división.
 */

#include <iostream>
#include <stdexcept>

/**
 * @brief Suma dos números.
 * 
 * Esta función toma dos números de tipo float y retorna su suma.
 * 
 * @param a Primer número.
 * @param b Segundo número.
 * @return La suma de los dos números.
 */
float suma(float a, float b) {
    return a + b;
}

/**
 * @brief Resta dos números.
 * 
 * Esta función toma dos números de tipo float y retorna su resta.
 * 
 * @param a Primer número.
 * @param b Segundo número.
 * @return La resta de los dos números.
 */
float resta(float a, float b) {
    return a - b;
}

/**
 * @brief Multiplica dos números.
 * 
 * Esta función toma dos números de tipo float y retorna su producto.
 * 
 * @param a Primer número.
 * @param b Segundo número.
 * @return El producto de los dos números.
 */
float multiplicacion(float a, float b) {
    return a * b;
}

/**
 * @brief Divide dos números.
 * 
 * Esta función toma dos números de tipo float y retorna su división.
 * 
 * @param a Numerador.
 * @param b Denominador.
 * @return El cociente de la división.
 * @throws std::invalid_argument Si el denominador es cero.
 */
float division(float a, float b) {
    if (b == 0) {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
    return a / b;
}

/**
 * @brief Función principal que ejecuta la calculadora.
 * 
 * La función principal permite al usuario realizar operaciones
 * aritméticas básicas, como suma, resta, multiplicación y división.
 * 
 * @return Código de salida del programa.
 */
int main() {
    float a = 10.0f;
    float b = 5.0f;

    std::cout << "Suma: " << suma(a, b) << std::endl;
    std::cout << "Resta: " << resta(a, b) << std::endl;
    std::cout << "Multiplicación: " << multiplicacion(a, b) << std::endl;
    try {
        std::cout << "División: " << division(a, b) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

