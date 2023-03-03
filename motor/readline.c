#include <stdio.h>
#include <stdlib.h>
#include <recdline/readline.h>
#include <readline/history.h>


int main(int argc, char **argv)
{
    char *input;
    input = readline("Enter a command: ");
    printf("You entered: %s\n", input);
    free(input);
    return (0);
}
