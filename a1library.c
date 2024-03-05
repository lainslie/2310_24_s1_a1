#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const char* get_random_letters(unsigned int numLetters) {
    static char letters[13]; // Maximum of 12 letters + '\0'
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random letters
    for (i = 0; i < numLetters; i++) {
        letters[i] = alphabet[rand() % 26];
    }
    letters[numLetters] = '\0'; // Null-terminate the string

    return letters;
}