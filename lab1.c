#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName) {
    char* mempoint = (char*)malloc(100 * sizeof(char));
    if (mempoint == NULL) {
        perror("malloc failed in readString");
        mempoint = malloc(1);
        mempoint[0] = '\0';
        return mempoint;
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL || fgets(mempoint, 100, file) == NULL) {
        if (file == NULL) {
            perror("Error opening file");
        }
        mempoint[0] = '\0';
    } else {
        // If the read was successful, just remove the newline like before.
        mempoint[strcspn(mempoint, "\n")] = '\0';
    }

    if (file != NULL) {
        fclose(file);
    }

    return mempoint;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str) {
   
    if (str == NULL) {
        char* empty = malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }
    int length = strlen(str);
    int newLength = (length * (length + 1)) / 2;
    char* expo = (char *)malloc(newLength + 1);

    // If malloc fails, return an empty string instead of NULL.
    if (expo == NULL) {
        perror("malloc failed in mysteryExplode");
        char* empty = (char*)malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    char* current_pos = expo;
    for (int i = 1; i <= length; i++) {
        memcpy(current_pos, str, i);
        current_pos += i;
    }
    *current_pos = '\0';
    return expo;
}