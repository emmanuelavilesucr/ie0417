#include <mutex>

std::mutex mtx;  // Se declara un mutex global.


// Función encargada de incrementar la variable.
void safeIncrement(int &counter){
    std::lock_guard<std::mutex> lock(mtx);  // Bloquea el acceso a otros hilos hasta que se libere el mutex.
    ++counter;  // Se incrementa la variable.
}








    

    