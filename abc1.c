#include <stdio.h>
// #include <stdlib.h>
#include <string.h>


int main() {

    // char word1, word2;

    char word1[] = "aaaa";
    char word2[] = "AAAA";
    
    int res = strcmp(word1, word2);
    printf("res: %i", res);

}


