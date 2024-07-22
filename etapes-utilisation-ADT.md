1. # Modifier local.conf pour ajouter les fonctionnalités du SDK.
- On ajoute les outils de debug et tools dans les extras packages.
```
EXTRA_IMAGE_FEATURES ?= "debug-tweaks tools-sdk tools-debug"
```
2. # Construire l'image yocto.
```
bibtbake core-image-minimal
```

3. # Créer et installer ADT
```
bitbake core-image-minimal -c populate_sdk
```

4. # Installer les sdk
```
./tmp/deploy/sdk/poky-glibc-x86_64-meta-toolchain-core2-64-qemux86-64-toolchain-5.0+snapshot.sh 
```

5. # source les sdks
- Dans le dossier de sortie de sdk, on source un fichier d'environement avec les tools 

6. # Commande pour démarrer qemu.

- Avant on peut créer une clé usb pour partager les données entre notre qemu et le host
- Si qemu-img est non disponible, on peut l'installer par exemple sur ubuntu avec la commande `apt install qemu-utils -y`
```
qemu-img create -f raw usb.img 1G
mkfs.ext4 usb.img
```

- Commande pour démarrer un qemux86-64
```
runqemu qemux86-64 nographic slirp qemuparams="-netdev user,id=usernet,hostfwd=tcp::224-:22 -device e1000,netdev=usernet -drive file=usb.img,format=raw,if=none,id=usbdisk -device usb-storage,drive=usbdisk"
```

7. # Arreter les machines
shutdown now
poweroff