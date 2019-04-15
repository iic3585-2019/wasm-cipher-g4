#include <iostream>
#include <ctype.h>
#include <emscripten/emscripten.h>
#include "./morse-code/src/encode.c"
#include "vigenere.c"

#ifdef __cplusplus
extern "C" {
#endif

	char* EMSCRIPTEN_KEEPALIVE caesar(char* text, int n, int s) {
		for (int i = 0; i < n; i++) {
			if (isupper(text[i])) text[i] = char(int(text[i] + s - 65) % 26 + 65);
			else if (isspace(text[i])) continue;
			else text[i] = char(int(text[i] + s - 97) % 26 + 97);
		}
		return text;
	}

		char* EMSCRIPTEN_KEEPALIVE morse_encode(char* text) {
		return encoder(text);
	}

	char* EMSCRIPTEN_KEEPALIVE vigenere_encoder(char* text, char* key) {
	return vigenere_encode(text, key);
}


	char* EMSCRIPTEN_KEEPALIVE vigenere_decoder(char* text, char* key) {
	return vigenere_decode(text, key);
}


#ifdef __cplusplus
}
#endif
