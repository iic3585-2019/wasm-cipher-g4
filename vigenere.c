#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


char *generate_key (char *key, int msgLen){
  char *newKey = (char *)malloc(sizeof('a')*msgLen);
  int i, j;
  for(i = 0, j = 0; i < msgLen; ++i, ++j){
      if(j == strlen(key))
          j = 0;
      newKey[i] = key[j];
  }
  newKey[i] = '\0';
  return newKey;
}

char *vigenere_encode (char *msg, char *key){
  int msgLen = strlen(msg);
  printf("%s", msg);
  char *newKey = (char *)malloc (sizeof('a')*msgLen);
  char *encryptedMsg = (char *)malloc (sizeof('a')*msgLen);
  newKey = generate_key(key, msgLen);
  int i;
  for(i = 0; i < msgLen; ++i){
    if (isspace(msg[i])) encryptedMsg[i] = ' ';
    else encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
  }
  encryptedMsg[i] = '\0';
  return encryptedMsg;
}


char *vigenere_decode (char *msg, char *key){
  int msgLen = strlen(msg);
  char *newKey = (char *)malloc (sizeof('a')*msgLen);
  char *decryptedMsg = (char *)malloc (sizeof('a')*msgLen);
  newKey = generate_key(key, msgLen);
  int i;
  for(i = 0; i < msgLen; ++i){
    if (isspace(msg[i])) decryptedMsg[i] = ' ';
    else decryptedMsg[i] = (((msg[i] - newKey[i]) + 26) % 26) + 'A';
  }
  decryptedMsg[i] = '\0';
  return decryptedMsg;
}
