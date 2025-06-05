#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <condition_variable>
#include <semaphore>
#include <chrono>

using namespace std;

constexpr int BUFFER_SIZE = 10;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;

// Semáforos que controlan la cantidad de espacios.
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
std::counting_semaphore<BUFFER_SIZE> full_slots(0);

// Funcion de los hilos productores
void producer(int id, int num_tasks) {
    for (int i = 0; i < num_tasks; ++i) {
        int item = id * 100 + i;
        empty_slots.acquire();  // Espera a que haya espacio disponible en el búfer.
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);
            std::cout << "Producer" << id << " produced item" << item << std::endl;
        }

        full_slots.release();  // Indicar si existen ítems disponibles.
        cv_consumer.notify_one();
    }
}


// Funcion de los hilos consumidores
void consumer(int id) {
    while (true) {
        full_slots.acquire();
        std::unique_locks<std::mutex> lock(mtx);

        cv_consumer.wait(lock, [] { return !buffer.empty(); });  // Espera mientras el búfer esté vacío.

        int item = buffer.front();
        buffer.pop();
        std::cout<< "Consumer" << id << " consumed item " << item << std::endl;

        lock.unlock();  // Liberar el mutex.
        empty_slots.release();  // Indica el espacio libre en el búfer.
        cv_producer.notify_one();  

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulacion del tiempo de consumo.

    }
}


int main() {
    const int num_producers = 2;
    const int num_consumers = 3; 
    const int num_tasks_per_producer = 10;

    std::vector<std::thread> producers, consumers;   // Crea vectores de hilos.


    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer, i, num_tasks_per_producer);
    }

    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "All producers have finished." << std::endl;
    return 0;
}