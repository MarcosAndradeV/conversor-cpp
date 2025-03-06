# Conversor-cpp

## Build/Compilar

### Meson

```bash
meson setup build
meson compile -C build
```

### g++

```bash
mkdir build
g++ src/conv.cpp -o build/conv
```

## Run/Rodar

```bash
./build/conv tests/msg.txt
```
