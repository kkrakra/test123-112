#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main() {

    char *input;

    while (1) {
        input = readline("Enter input (type 'exit' to quit): ");
        if (input == NULL) {
            // EOF reached, exit the loop
            break;
        }

        // Process the input here
        printf("You entered: %s\n", input);


    }

}