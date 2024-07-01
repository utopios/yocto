1. ## Préparation des fichiers sources
- net-app.c
- Makefile
2. ## Créer un ZIP avec l'application
```bash
tar czvf net-app.tar.gz net-app.c Makefile
```

3. ## Création de la structure de custom layer
```
bitbake-layers create-layer meta-networking
```

4. ## L'ajout de la recette de l'application

- Créer la structure de la recette
- Créer le fichier .bb

5. ## L'ajout du custom Layer au build

6. ## Construire l'image