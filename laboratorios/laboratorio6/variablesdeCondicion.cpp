#include <mutex>
#include <condition_variable>


std::mutex mtx;   // Protege el acceso a la variable 'ready'.
std::condition_variable cv;  // Permite que un hilo espere hasta que otro lo aparezca.
bool ready = false;

// Función encargada de ejecutar un hilo que espera a una señal.
void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });  // Cuando 'ready' es true, el hilo continúa su ejecución.
}


 // Función encargada de notificar a otros hilos que pueden continuar
void notifyingThread() {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one();  // Notifica a los hilos sobre la condicion.
}