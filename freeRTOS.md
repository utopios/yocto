### Principales Fonctions dans FreeRTOS

1. **Gestion des Tâches (Tasks) :**
   - **`xTaskCreate()`** : Crée une nouvelle tâche.
   - **`vTaskDelete()`** : Supprime une tâche.
   - **`vTaskDelay()`** : Bloque la tâche en cours pendant un certain temps.
   - **`vTaskStartScheduler()`** : Démarre l'ordonnanceur FreeRTOS, permettant l'exécution multitâche.
   - **`xTaskGetTickCount()`** : Retourne le nombre de "ticks" depuis le démarrage de FreeRTOS (utile pour mesurer des délais).

   Exemple :
   ```c
   xTaskCreate(vTaskFunction, "Task 1", 1000, NULL, 1, NULL); // Crée une tâche
   vTaskDelay(pdMS_TO_TICKS(500)); // Bloque la tâche pendant 500ms
   ```

2. **Files d'attente (Queues) :**
   - **`xQueueCreate()`** : Crée une file d'attente.
   - **`xQueueSend()`** : Envoie un élément dans une file d'attente.
   - **`xQueueReceive()`** : Reçoit un élément depuis une file d'attente.
   - **`xQueueSendToBack()`** et **`xQueueSendToFront()`** : Envoie un élément respectivement à la fin ou au début de la file d'attente.

   Exemple :
   ```c
   xQueueHandle myQueue = xQueueCreate(10, sizeof(int)); // File d'attente de 10 éléments de type int
   int value = 10;
   xQueueSend(myQueue, &value, portMAX_DELAY); // Envoie un élément dans la file d'attente
   ```

3. **Sémaphores :**
   - **`xSemaphoreCreateBinary()`** : Crée un sémaphore binaire.
   - **`xSemaphoreGive()`** : Libère (donne) le sémaphore.
   - **`xSemaphoreTake()`** : Prend (réclame) le sémaphore.

   Exemple :
   ```c
   xSemaphoreHandle xBinarySemaphore = xSemaphoreCreateBinary();
   xSemaphoreGive(xBinarySemaphore);  // Libère le sémaphore
   xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);  // Réclame le sémaphore
   ```

4. **Mutex :**
   - **`xSemaphoreCreateMutex()`** : Crée un mutex.
   - **`xSemaphoreTake()`** : Réclame un mutex.
   - **`xSemaphoreGive()`** : Libère un mutex.

   Exemple :
   ```c
   xSemaphoreHandle xMutex = xSemaphoreCreateMutex();
   xSemaphoreTake(xMutex, portMAX_DELAY);  // Réclame le mutex
   xSemaphoreGive(xMutex);  // Libère le mutex
   ```

5. **Gestion des Délai (Timing) :**
   - **`vTaskDelay()`** : Retarde une tâche de manière à ce qu'elle ne soit pas exécutée pendant une certaine période.
   - **`vTaskDelayUntil()`** : Bloque une tâche jusqu'à une période spécifiée.
   - **`vTaskSuspend()`** et **`vTaskResume()`** : Suspend et reprend l'exécution d'une tâche.

   Exemple :
   ```c
   TickType_t xLastWakeTime;
   const TickType_t xFrequency = 1000; // 1 seconde

   xLastWakeTime = xTaskGetTickCount(); // Sauvegarde du temps actuel
   for( ;; ) {
       vTaskDelayUntil(&xLastWakeTime, xFrequency);  // Délai précis jusqu'à 1 seconde après le dernier appel
   }
   ```

6. **Groupes d'Événements (Event Groups) :**
   - **`xEventGroupCreate()`** : Crée un groupe d'événements.
   - **`xEventGroupSetBits()`** : Définit un ou plusieurs bits dans un groupe d'événements.
   - **`xEventGroupWaitBits()`** : Attend qu'un ou plusieurs bits soient définis dans un groupe d'événements.

   Exemple :
   ```c
   EventGroupHandle_t xEventGroup = xEventGroupCreate();
   xEventGroupSetBits(xEventGroup, BIT_0);  // Définit le bit 0
   xEventGroupWaitBits(xEventGroup, BIT_0, pdTRUE, pdFALSE, portMAX_DELAY);  // Attend que le bit 0 soit défini
   ```

7. **Timers Logiciels :**
   - **`xTimerCreate()`** : Crée un timer logiciel.
   - **`xTimerStart()`** : Démarre le timer logiciel.
   - **`xTimerStop()`** : Arrête le timer logiciel.

   Exemple :
   ```c
   TimerHandle_t xTimer = xTimerCreate("Timer", pdMS_TO_TICKS(1000), pdTRUE, 0, vTimerCallback);
   xTimerStart(xTimer, 0); // Démarre le timer
   ```
