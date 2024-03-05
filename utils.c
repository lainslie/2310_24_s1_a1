#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_alpha_string(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isalpha(string[i])) {
            return false;
        }
    }

    return true;
}

bool is_digit_string(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return false;
        }
    }

    return true;
}