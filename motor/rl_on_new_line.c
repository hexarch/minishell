#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/*
int main() 
{
    char *user_input;
    while(1) {
        user_input = readline("Enter a command: ");
        if(strcmp(user_input, "exit") == 0) {
            break;
        } else {
            rl_on_new_line();
            printf("Command entered: %s\n", user_input);
        }
        add_history(user_input);
        free(user_input);
    }
    return 0;
}
*/