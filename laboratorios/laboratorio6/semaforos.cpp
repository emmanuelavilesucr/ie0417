#include <semaphore> 

std::counting_semaphore<1> sem(1);  // Se declara un semáforo binario con 1 permiso disponible.

// Función encargada del acceso al recurso.(adquiere el semáforo, bloqueando si no hay permisos disponibles).
void accessResource() {    
    sem.acquire();  // Asegura que el hilo pueda acceder a una sección.
    sem.release();  // Libera el semáforo.
}
