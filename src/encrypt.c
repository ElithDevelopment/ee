#include "include/encrypt.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *encrypt_string(const char *string, int verbose) {
  if (verbose) printf("Generating random key...\n");
  char *key = generate_random_key(verbose);
  if (key == NULL) {
    fprintf(stderr, "Error generating key.\n");
    exit(1);
  }

  if (verbose) printf("Calculating length of string...\n");
  size_t string_length = strlen(string);
  if (verbose) printf("Allocating %d bytes of memory for encrypted string...\n", (string_length + 1));
  char *encrypted = malloc(string_length + 1);
  if (encrypted == NULL) {
    free(key);
    fprintf(stderr, "Error allocating memory for encrypted string.\n");
    exit(1);
  }

  if (verbose) printf("Running encryption loop...\n");
  for (size_t i = 0; i < string_length; i++) {
    if (verbose) printf("Encrypting byte '%c'...\n", string[i]);
    encrypted[i] = string[i] ^ key[i % strlen(key)];
  }
  encrypted[string_length] = '\0';

  if (verbose) printf("Freeing memory for original string...\n");
  return encrypted;
}

char *generate_random_key(int verbose) {
  const char *charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const int key_length = 16;
  if (verbose) printf("Allocating memory for random key...\n");
  char *key = malloc(key_length + 1);
  if (key == NULL) {
    free(key);
    fprintf(stderr, "Error allocating memory for random key.\n");
    exit(1);
  }

  for (int i = 0; i < key_length; i++) {
    int index = rand() % strlen(charset);
    key[i] = charset[index];
  }
  key[key_length] = '\0';

  return key;
}

