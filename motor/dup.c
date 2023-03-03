#include <stdio.h>
#include <unistd.h>

/*
int main() {
    int stdout_copy = dup(STDOUT_FILENO);
    dup2(stdout_copy, 3);
    printf("This text will be printed to both stdout and the duplicate file descriptor\n");
    fflush(stdout);
    return 0;
}
*/
