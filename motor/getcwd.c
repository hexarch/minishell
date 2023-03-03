#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int main()
{
    char *cwd = (char*)malloc(sizeof(char) * 256);

    if(cwd == NULL) {
        perror("malloc");
        exit(1);
    }
    if(getcwd(cwd, 256) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd");
        exit(1);
    }
    free(cwd);
    return 0;
}
*/