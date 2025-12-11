#include <string.h>
#include <stdio.h>
#include "command_parser.h"


int parse_command(char* input, char* cmd, char* arg) {
    cmd[0] = 0;
    arg[0] = 0;

    char* token = strtok(input, " ");
    if (!token) return 0;

    strcpy(cmd, token);

    token = strtok(NULL, " ");
    if (token) {
        strcpy(arg, token);
        return 1;
    }

    return 0;
}
