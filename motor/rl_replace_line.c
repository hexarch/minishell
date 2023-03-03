#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/*
int main() {
    char *user_input;
    while(1) {
        user_input = readline("Enter a command: ");
        if(strcmp(user_input, "exit") == 0) {
            break;
        } else {
            rl_replace_line(user_input, 0);
            rl_redisplay();
        }
        add_history(user_input);
        free(user_input);
    }
    return 0;
}
*/