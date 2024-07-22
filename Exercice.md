### Exercice ADT

1. compiler le code pour le tester localement
2. Utiliser le compilateur ADT pour compiler pour la machine QEMU.
3. Tester l'application sur la machine QEMU.

## Fichier script.sh pour émuler le capteur de temperature
```bash
#!/bin/bash
while true; do
    # Générer un nombre aléatoire entre 15 et 35 pour la température
    echo $((RANDOM % 20 + 15)) > temperature_sensor
    sleep 60  # Mettre à jour la température chaque minute
done
```

### Fichier Application qui écoute le capteur

```c
#include <stdio.h>
#include <stdlib.h>

#define SENSOR_FILE "temperature_sensor"  

void control_cooling_system(int temperature) {
    if (temperature > 25) {
        printf("Temperature is %d°C. Turning on the cooling system.\n", temperature);
        
    } else {
        printf("Temperature is %d°C. No need for cooling.\n", temperature);
    }
}

int read_temperature() {
    FILE *file;
    int temperature;

    file = fopen(SENSOR_FILE, "r");
    if (file == NULL) {
        perror("Failed to open the temperature sensor file");
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%d", &temperature) != 1) {
        perror("Failed to read the temperature");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return temperature;
}

int main() {
    int current_temperature = read_temperature();
    control_cooling_system(current_temperature);
    return 0;
}
```