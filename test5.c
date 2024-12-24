#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_GROUPS 100
#define MAX_WORD_LEN 100

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

int main() {
    char input[] = "Listen cat listen sIlent tac dog";
    char *token;
    char currentWord[MAX_WORD_LEN];
    memset(currentWord, 0, sizeof(currentWord));

    // Tokenize the input string
    token = strtok(input, " ");
    while (token != NULL) {
        // Convert to lowercase for comparison
        for (int i = 0; i < strlen(token); i++) {
            currentWord[i] = tolower((unsigned char)token[i]);
        }
        currentWord[strlen(token)] = '\0';
        
        // Add to group or create new group
        addToGroup(currentWord);
        
        // Reset currentWord for next iteration
        memset(currentWord, 0, sizeof(currentWord));
        strcpy(currentWord, token);
        
        token = strtok(NULL, " ");
    }

    // Sort groups
    sortGroups();

    // Print sorted groups
    printGroups();

    return 0;
}
