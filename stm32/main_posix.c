#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>  // Bibliothèque pour gérer les GPIO sur Raspberry Pi, par exemple

void *blinkLED1(void *arg) {
    while (1) {
        // Simuler l'allumage de la LED 1
        digitalWrite(0, HIGH);  // GPIO 0 (LED1)
        sleep(1);               // Délai de 1 seconde
        digitalWrite(0, LOW);   // GPIO 0 OFF
        sleep(1);
    }
}

void *blinkLED2(void *arg) {
    while (1) {
        // Simuler l'allumage de la LED 2
        digitalWrite(1, HIGH);  // GPIO 1 (LED2)
        sleep(2);               // Délai de 2 secondes
        digitalWrite(1, LOW);   // GPIO 1 OFF
        sleep(2);
    }
}

int main() {
    // Initialisation GPIO
    wiringPiSetup();
    pinMode(0, OUTPUT);  // Configurer GPIO 0 comme sortie (LED1)
    pinMode(1, OUTPUT);  // Configurer GPIO 1 comme sortie (LED2)

    // Créer les threads (équivalent des tâches FreeRTOS)
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, blinkLED1, NULL);
    pthread_create(&thread2, NULL, blinkLED2, NULL);

    // Attendre que les threads terminent
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}