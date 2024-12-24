#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <readline/readline.h>


//
#define MAX_GROUPS 100
#define MAX_WORD_LEN 100


char list1[100][200]

char groups[MAX_GROUPS][MAX_WORD_LEN];
int groupCount = 0;

void addToGroup(char *word) {
    int i;
    for (i = 0; i < groupCount; i++) {
        if (strcmp(groups[i], word) == 0) {
            return;
        }
    }
    if (groupCount < MAX_GROUPS) {
        strcpy(groups[groupCount], word);
        groupCount++;
    }
}

void sortGroups() {
    for (int i = 0; i < groupCount - 1; i++) {
        for (int j = i + 1; j < groupCount; j++) {
            if (strcmp(groups[i], groups[j]) > 0) {
                char temp[MAX_WORD_LEN];
                strcpy(temp, groups[i]);
                strcpy(groups[i], groups[j]);
                strcpy(groups[j], temp);
            }
        }
    }
}

void printGroups() {
    for (int i = 0; i < groupCount; i++) {
        printf("%s ", groups[i]);
    }
    printf("\n");
}


//




// char *process(const char *);

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

        char currentWord[MAX_WORD_LEN];

        printf("Word: \"%s\"\n", word);

        // Convert to lowercase for comparison
        for (int i = 0; i < strlen(word); i++) {
            currentWord[i] = tolower((unsigned char)word[i]);
        }
        currentWord[strlen(word)] = '\0';
        
        // Add to group or create new group
        addToGroup(currentWord);
        
        // Reset currentWord for next iteration
        memset(currentWord, 0, sizeof(currentWord));
        strcpy(currentWord, word);


        word = strtok(NULL, " "); //delim

        ////
        // printf("Word: \"%s\"n\"", word);
        // int w_len = strlen(word) - 1;
        // if (w_len > 0) {
        //     memcpy(res + len, word + 1, w_len + sizeof(char));
        //     len += w_len;
        //     res[len] = ' ';
        //     ++len;
        // }
        // printf("Result: \"%s\"\n", res);
        // word = strtok(NULL, " "); //delim
        ////

    }


    // Sort groups
    sortGroups();

    // Print sorted groups
    printGroups();

    // return 0;


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
        // printf("\"%s\n", input);
        char *output = process(input);
        // printf("\"%s\n", output);

        free(input);
        free(output);
    }
    return 0;
}


