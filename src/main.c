#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/decrypt.h"
#include "include/encrypt.h"

void print_usage() {
    printf("Usage: ee [additional arguments] <string>\n\n");
    printf("Additional arguments:\n");
    printf("-d <key>: Decrypts a string with the provided key\n");
    printf("-v:       Prints verbose output\n");
    exit(2);
}

int main(int argc, char **argv) {
    char *string = NULL;
    char *key = NULL;
    int verbose = 0;

    if (argc < 2 || argc > 5) {
        print_usage();
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                key = argv[i + 1];
                i++;
            } else {
                print_usage();
            }
        } else {
            string = argv[i];
        }
    }

    if (string == NULL) {
        print_usage();
    }

    if (key != NULL) {
        char *decrypted = decrypt_string(string, key, verbose);
        if (decrypted != NULL) {
            printf("Decrypted string: %s\n", decrypted);
            free(decrypted);
        } else {
            printf("Decryption failed.\n");
        }
    } else {
        char *encrypted = encrypt_string(string, verbose);
        if (encrypted != NULL) {
            printf("Encrypted string: %s\n", encrypted);
            free(encrypted);
        } else {
            printf("Encryption failed.\n");
        }
    }

    return 0;
}

