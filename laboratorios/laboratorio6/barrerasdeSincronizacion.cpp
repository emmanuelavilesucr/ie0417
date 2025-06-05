#include <barrier>

std::barrier sync_point(5); // Se crea una barrera que esperará a que 5 hilos lleguen a ella antes de continuar, lo resulta util en procesos de múltiples hilos en puntos específicos.

// Funcion encargada de ejecutar cada hilo.
void threadFunction() {
    sync_point.arrive_and_wait();  // Indica que ha llegado a la barrera.

}





