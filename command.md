
sudo add-apt-repository universe
sudo add-apt-repository multiverse

### build de l'image
sudo docker build -f dockerfile.build -t yocto-builder .
git clone git://git.yoctoproject.org/poky

sudo docker run --name yocto -d -v $(pwd)/poky:/poky yocto-builder 

sudo docker exec -it yocto bash

### Lignes local.conf

EXTRA_IMAGE_FEATURES ?= "debug-tweaks tools-debug tools-sdk tools-profile"

## Commandes pour installer le SDK

```bash
## generation de l'image 
bitbake core-image-minimal

bitbake meta-toolchain
## Dans le dossier build/tmp/deploy/sdk, on va avoir un fichier .sh
## On execute le point sh, le script va demander ou on va extraire le sdk, on doit le chemin souhaité.
## Dans le chemin d'extraction du sdk, on a un fichier source pour ajouter les elements du sdk.



 

```

### Après l'installation du sdk, et le sourcing du sdk

```main.c```

```bash
$CC -hhello.c -o hello
//scp hello root@device:/home/app
//ssh root@qemu './hello'
gdb ./hello
```
## Après le lancement de la commande 
(gdb) target remote <Information_remote>
(gdb) run 



