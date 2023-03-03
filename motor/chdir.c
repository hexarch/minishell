#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/*
int main() 
{
    char *cwd = (char*)malloc(sizeof(char) * 256);
    if(chdir("denemedosya") == 0) {
        printf("Changed directory to /denemedosya\n");
        getcwd(cwd, 256);
        printf("%s\n", cwd);

    } else {
        perror("chdir");
        exit(1);
    }
    return 0;
}
*/