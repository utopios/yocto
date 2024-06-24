
sudo add-apt-repository universe
sudo add-apt-repository multiverse

### build de l'image
sudo docker build -f dockerfile.build -t yocto-builder .
git clone git://git.yoctoproject.org/poky

sudo docker run --name yocto -d -v $(pwd)/poky:/poky yocto-builder 

sudo docker exec -it yocto bash


