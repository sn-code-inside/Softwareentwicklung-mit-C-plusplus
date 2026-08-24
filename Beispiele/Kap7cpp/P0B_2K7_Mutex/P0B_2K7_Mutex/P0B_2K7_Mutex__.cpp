// P0B_2K7_Mutex.cpp

#include <iostream>
//#include <sys/mman.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

// Struktur, die im Shared Memory liegen soll
struct SharedData {
    pthread_mutex_t mutex;
    int counter;
};

int main() {
    // 1. Shared Memory Objekt erstellen
    int shm_fd = shm_open("/my_shared_mutex", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedData));

    // 2. Shared Memory in den Adressraum mappen
    SharedData* shared = (SharedData*)mmap(NULL, sizeof(SharedData),
        PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // 3. Mutex-Attribute für prozessübergreifende Nutzung konfigurieren
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    // 4. Mutex initialisieren
    pthread_mutex_init(&shared->mutex, &attr);
    pthread_mutexattr_destroy(&attr);
    shared->counter = 0;

    pid_t pid = fork();

    if (pid == 0) {
        // --- Kindprozess ---
        for (int i = 0; i < 5; ++i) {
            pthread_mutex_lock(&shared->mutex);
            shared->counter++;
            std::cout << "Kind  erhöht auf: " << shared->counter << std::endl;
            pthread_mutex_unlock(&shared->mutex);
            usleep(100000); // Kurz warten
        }
    }
    else {
        // --- Elternprozess ---
        for (int i = 0; i < 5; ++i) {
            pthread_mutex_lock(&shared->mutex);
            shared->counter++;
            std::cout << "Eltern erhöht auf: " << shared->counter << std::endl;
            pthread_mutex_unlock(&shared->mutex);
            usleep(100000);
        }
        wait(NULL); // Auf Kindprozess warten

        // 5. Cleanup
        pthread_mutex_destroy(&shared->mutex);
        shm_unlink("/my_shared_mutex");
        std::cout << "Endstand: " << shared->counter << std::endl;
    }

    return 0;
}