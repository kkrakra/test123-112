#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <readline/readline.h>

char *process(const char *);

char *process(const char *str) {
    char *s = strdup(str);
    int s_len = strlen(s);
    char *res = calloc(s_len + 1, sizeof(char));
    int len = 0;
    char *word = strtok(s, " "); //delim
    while (1) {
        if (word == NULL) {
            // EOF reached, exit the loop
            break;
        }
        printf("Word: \"%s\"n\"", word);
        int w_len = strlen(word) - 1;
        if (w_len > 0) {
            memcpy(res + len, word + 1, w_len + sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
        }
        printf("Result: \"%s\"\n", res);
        word = strtok(NULL, " "); //delim

    }
    free(s);
    if (len > 0) {
        --len;
    }
    res[len] = '\0';
    res = realloc(res, (len + 1) * sizeof(char) );
    return res;
}



int main() {
    
    while (1) {
        char *input = readline("Enter sentence\n");
        if (input == NULL) {
            // EOF reached, exit the loop
            break;
        }
        printf("\"%s\n", input);
        char *output = process(input);
        printf("\"%s\n", output);

        free(input);
        free(output);
    }
    return 0;
}


