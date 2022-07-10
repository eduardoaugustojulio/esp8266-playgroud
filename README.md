# ESP8266-RTOS Playground

### Get toolchain for Linux 64 bits

```
wget https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz
sudo tar -xvf xtensa-lx106-elf-linux64-1.22.0-100-ge567ec7-5.2.0.tar.gz /opt
```

## To Build 

```
git submodule update --init
source setup.sh
make all && make flash
```
