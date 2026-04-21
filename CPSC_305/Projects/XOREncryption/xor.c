#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * Changes the contents of a string via the XOR operation
  * @param key The string key used for the encryption
  * @param message The string to be encrypted
  * @param size The size of the string
  * @return The new string
  */
char* xor (char key[], char message[], int size[1]) {
    int keyInx = 0;
    char output[1000];
    for (int i = 0; i < *size; i++) {
        if ((int) (key[keyInx] ^ message[i]) == 0) {
            // I was getting weird errors that would stop decrypting correctly if a ^ b = 0, so this was my work-around for it
            output[i] = message[i];
        } else {
            output[i] = key[keyInx] ^ message[i];
        }
        keyInx++;
        if (strlen(key) <= keyInx) {
                keyInx = 0;
        }
    }
    output[size[0]] = '\0';
    strcpy(message, output);

    return message;
}

/**
  * Encrypts a message onto a file
  * @param key The string key used for the encryption
  * @param filename The name of the file to be created
  */
void encrypt(char* key[], char* filename[]) {
    // Create a file
    FILE* file = fopen(*filename, "w");

    // Get a message
    char message[1000];
    printf("Enter a message:\n");
    for (int i = 0; i < 1000; i++) {
        scanf("%c", &message[i]);
        if (message[i] == 10) {
            message[i] = '\0';
            break;
        }
    }

    char out[1000];
    int messageSize[1];
    messageSize[0] = (int) strlen(message);
    strcpy(out, xor(*key, message, messageSize));
    
    fwrite(messageSize, 4, 1, file);
    fwrite(out, *messageSize, 1, file);

    fclose(file);
}

/**
  * Decrypts a message from a file
  * @param key The string key used for the decryption
  * @param filename The name of the file that is being decrypted
  */
void decrypt(char* key[], char* filename[]) {
    FILE* file = fopen(*filename, "r");
    if (file == NULL) {
        printf("File could not be read\n");
        return;
    }
    int fileSize[1];
    char line[1000];
    // Read the int
    fread(fileSize, 4, 1, file);
    
    // Read the line
    fread(line, *fileSize, 1, file);
    char out[1000];
    line[*fileSize] = '\0';
    strcpy(out, xor(*key, line, fileSize));
    printf("%s\n", out);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Not enough arguments\n");
        return 1;
    } else {
        if (strcmp(argv[1], "dec")== 0) {
            decrypt(&argv[2], &argv[3]);
        } else if (strcmp(argv[1], "enc") == 0) {
            encrypt(&argv[2], &argv[3]);
        } else {
            printf("Invalid argument\n");
            return 1;
        }
    }
    return 0;
}
