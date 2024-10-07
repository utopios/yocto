#include "FreeRTOS.h"
#include "task.h"
#include "stm32f446_hal.h"  // Bibliothèque HAL pour STM32 (exemple de microcontrôleur)

void vTaskBlinkLED1(void *pvParameters) {
    while(1) {
        // Simuler l'allumage de la LED 1
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // GPIOA PIN5 (LED1 sur STM32)
        vTaskDelay(pdMS_TO_TICKS(500));  // Délai de 500ms
    }
}

void vTaskBlinkLED2(void *pvParameters) {
    while(1) {
        // Simuler l'allumage de la LED 2
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);  // GPIOB PIN6 (LED2 sur STM32)
        vTaskDelay(pdMS_TO_TICKS(1000));  // Délai de 1000ms
    }
}

int main(void) {
    // Initialisation du matériel (GPIO, etc.)
    HAL_Init();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Créer les tâches FreeRTOS
    xTaskCreate(vTaskBlinkLED1, "Task1", 128, NULL, 1, NULL);
    xTaskCreate(vTaskBlinkLED2, "Task2", 128, NULL, 1, NULL);

    // Démarrer l'ordonnanceur FreeRTOS
    vTaskStartScheduler();

    // Boucle infinie (ne devrait jamais être atteinte)
    while(1);
}