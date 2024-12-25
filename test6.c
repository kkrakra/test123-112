#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <readline/readline.h>

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

// int compare(char *str1, char *str2) {
//     int res;
//     res = strcmp(str1, str2);
//     return res;
// }

char *process(char *str) {
    // printf("Row: %s\n", str);

    int s_len = strlen(str);
    char *res = calloc(s_len + 1, sizeof(char));

    // for (int i = 0; str[i] != '\0'; i++) {
    //     printf("%c\n", str[i]);
    // }

    // free(str);

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
    // printf("%s\n", token);

    // printf("Words in the sentence:\n");
    // for (int i = 0; i < wordCount; i++) {
    //     printf("%d: %s\n", i + 1, words[i]);
    // }

    //start


    for (int i = 0; i < wordCount; i++) {
        for (int j = i+1; j < wordCount; j++ ) {
            printf("%d: %s\n", i + 1, words[i]);
            printf("%d: %s\n", j + 1, words[j]);
            printf("===\n");

            if (strcmp(words[j], words[j + 1]) > 0) {
            // if (compare(words[j], words[j + 1]) > 0) {

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

                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;

            }


            ///start

            ///end


            // if (words[i] == words[j]) {
            //     new_words[i] = words[j];
            // } else {
            //     new_words[i] = words[i];
            // }
        }
    }
    //end

    printf("NEW Words in the sentence:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }


    // char* sentence = (char*)malloc(total_length + 1);
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


