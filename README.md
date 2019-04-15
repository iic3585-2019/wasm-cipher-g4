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

## Compilación

Para compilar el archivo se usó el comando

```
emcc -o index.html cipher.cpp vigenere.c ./morse-code/src/init.c ./morse-code/src/libmorse.c -s WASM=1 -s NO_EXIT_RUNTIME=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']"
```

Donde:

- **emcc** es la llamada al compilador de emscripten
- **-o index.html** es el archivo que se genera después de compilar, el cual luego se sobreescribió con la vista deseada
- **cipher.cpp vigenere.c ./morse-code/src/init.c ./morse-code/src/libmorse.c** archivos requeridos para la compilación
- **-s WASM=1** para obtener un archivo .wasm como output
- **-s NO_EXIT_RUNTIME=1** evita que el programa se cierre al no encontrar una función main
- **-s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']"** exporta la función ccall, con la cual se llamará a las funciones del archivo cipher.cpp en el archivo cipher.js
