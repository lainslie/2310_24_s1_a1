#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "a1library.h"
#include "command_line.h"
#include "utils.h"


int main(int argc, char *argv[]) {
 
    CommandLineParams command_params = {
        4, 
        "/local/courses/csse2310/etc/words",
        NULL
    };

    commandLineParsing(argc, argv, &command_params);

    if (!command_params.letters) {
        command_params.letters = get_random_letters(8);
    }

    read_dict_file(command_params);

    while (fgets(input, MAX_WORD_LENGTH, stdin)) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        int len = strlen(input);
        if (!areAllLetters(input)) {
            printf("Word must contain only letters\n");
            continue;
        }

        if (len < MIN_WORD_LENGTH) {
            printf("Word too short - it must have at least %d characters\n", MIN_WORD_LENGTH);
            continue;
        }

        if (len > MAX_WORD_LENGTH) {
            printf("Word must have a length of no more than %d characters\n", MAX_WORD_LENGTH);
            continue;
        }

        if (!canBeFormed(input)) {
            printf("Word cannot be made with available letters\n");
            continue;
        }

        // Check if word is in the dictionary (implementation not provided)

        // Check if the word has been guessed earlier (implementation not provided)

        // If all checks are passed, increment score and print message
        score += len; // Increment score by word length
        // Additional 10 points if word is of the maximum length
        if (len == MAX_WORD_LENGTH) score += 10;

        printf("Good! Score so far is %d\n", score);
    }

    return 0;


    return 0;
}
