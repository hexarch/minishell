#include "minishell.h"


int main(int argc, char *argv[], char *env[])
{
    (void)argv;
    (void)argc;
    
    fill_envs(env);
    

    while (g_core.env_table->next != 0)
    {
        printf("%s %s\n", g_core.env_table->env_name, g_core.env_table->content);
        g_core.env_table = g_core.env_table->next;
    }
}