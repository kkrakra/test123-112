#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <readline/readline.h>
// #include <ctype.h>

int countWords(const char *sentence) {
    int wordCount = 0;
    int inWord = 0;

    while (*sentence != '\0') {
        if (!isspace(*sentence)) {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        sentence++;
    }

    return wordCount;
}

// // Function to convert a char to lowercase
// int tolower_char(int c) {
//     return (c >= 'A' && c <= 'Z') ? c + 32 : c;
// }

// Function to sort an array of chars
void sort_chars(char *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// int compare(char* word1, char* word2) {
    
//     // char lower_word1[MAX_WORD_LENGTH], lower_word2[MAX_WORD_LENGTH];
//     char* lower_word1;
//     char* lower_word2;

//     strcpy(lower_word1, word1);
//     strcpy(lower_word2, word2);

//     for (int i = 0; i < strlen(word1); i++) {
//         lower_word1[i] = tolower(lower_word1[i]);
//     }
//     for (int i = 0; i < strlen(word2); i++) {
//         lower_word2[i] = tolower(lower_word2[i]);
//     }

//     // Sort both strings
//     sort_chars(lower_word1, strlen(word1));
//     sort_chars(lower_word2, strlen(word2));

//     // Compare sorted strings
//     int res;
//     res = strcmp(lower_word1, lower_word2);
//     return res;

// }

int compare(char *str1, char *str2) {
    int res;



    res = strcmp(str1, str2);
    return res;
}

// int compare(char *str1, char *str2) {
//     int res;
//     char* str1_1;
//     char* str2_1;
//     for (int k = 0; k < strlen(str1); k++) {
//         char* str1_1 = tolower((unsigned char)str1);
//     }
//     for (int k = 0; k < strlen(str2); k++) {
//         char* str2_1 = tolower((unsigned char)str2);
//     }

//     res = strcmp(str1_1, str2_1);
    
//     return res;
// }

// Convert to lowercase for comparison
                // char* word1;
                // char* word2;
                
                // for (int k = 0; k < strlen(words[j]); k++) {
                //     word1 = tolower((unsigned char)words[j]);
                // }
                // for (int k = 0; k < strlen(words[j+1]); k++) {
                //     word2 = tolower((unsigned char)words[j+1]);
                // }
                //

char *process(char *str) {

    int s_len = strlen(str);
    char *res = calloc(s_len + 1, sizeof(char));

    int count_words = countWords(str);
    printf("Number of words - %i\n", count_words);
    char* words[count_words];

    char* new_words[count_words];

    // Split the sentence into words
    char* token;
    token = strtok(str, " ");

    int wordCount = 0;
    while (token != NULL && wordCount < count_words) {
        words[wordCount] = malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    //start
    // for (int i = 0; i < wordCount; i++) {
    //     for (int j = i+1; j < wordCount; j++ ) {

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 1; j < wordCount - i - 1; j++) {
            printf("%d: %s\n", i + 1, words[i]);
            printf("%d: %s\n", j + 1, words[j]);
            printf("===\n");

            if (compare(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    //end

    printf("NEW Words in the sentence:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }


    strcpy(res, "");
    for (int i = 0; i < wordCount; i++) {
        strcat(res, words[i]);
        if (i < wordCount - 1) {
            strcat(res, " ");
        }
    }

    printf("Result - %s\n", res);


    // Free allocated memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    return 0;
    
}


char *process1(const char *str) {
    char *s = strdup(str);
    int s_len = strlen(s);
    char *res = calloc(s_len + 1, sizeof(char));
    int len = 0;
    char *word = strtok(s, " "); //delim
    while (word != NULL) {

        printf("Word: \"%s\"\n", word);

        int w_len = strlen(word);
        printf("debug %i\n", w_len);
        if (w_len > 0) {
            memcpy(res + len, word + 1, w_len + sizeof(char));
            len += w_len;
            res[len] = ' ';
            ++len;
        }


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
        // printf("\"%s\n", input);
        char *output = process(input);
        // printf("\"%s\n", output);

        free(input);
        free(output);
    }
    return 0;
}


