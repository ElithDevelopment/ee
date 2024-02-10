#include "include/decrypt.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *decrypt_string(const char *encrypted, const char *key, int verbose) {
  size_t encrypted_length = strlen(encrypted);
  if (verbose) printf("Allocating memory for decrypted string...\n");
  char *decrypted = malloc(encrypted_length + 1);
  if (decrypted == NULL) {
    free(decrypted);
    fprintf(stderr, "Error allocating memory for decrypted string.\n");
    exit(1);
  }

  for (size_t i = 0; i < encrypted_length; i++) {
    if (verbose) printf("Decrypting byte '%c'...\n", decrypted[i]);
    decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
  }
  decrypted[encrypted_length] = '\0';

  return decrypted;
}

