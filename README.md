# Codificador de textos

El proyecto consiste en una aplicación de codificación y decodificación de texto. Integra funciones de un archivo C++ y una librería en C, las cuales son utilizadas por medio de WebAssembly.

## Funcionalidades

1. Cifrado de Cesar: Codificación/Decodificación. Elimina puntuación en el proceso
2. Vigenere: Codificación/Decodificación. Transforma texto a mayúsculas
3. Morse: Codificación

La aplicación se puede probar [aquí](https://iic3585-2019.github.io/wasm-cipher-g4/index.html)

## Local

Para correr la aplicación en forma local el primer paso es clonar el repositorio y moverse al interior de él

```
git clone https://github.com/iic3585-2019/wasm-cipher-g4.git
cd wasm-cipher-g4
```

Luego se debe [instalar Emscripten](https://emscripten.org/docs/getting_started/downloads.html) y clonar la librería [morse-code](https://github.com/0x0584/morse-code)

```
git clone https://github.com/0x0584/morse-code.git
```

Para iniciar el servidor se debe ejecutar

```
python -m SimpleHTTPServer 8080
```
Y entrar a [localhost:8080](http://localhost:8080/index.html)
