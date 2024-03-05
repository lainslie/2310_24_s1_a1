#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

typedef struct {
    int min_len;
    char* dict_path;
    char* letters;
} CommandLineParams;

void commandLineParsing(int argc, char** argv, CommandLineParams* params);

#endif