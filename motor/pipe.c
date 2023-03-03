#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

/*
int main()
{
    int fd[2];
    pid_t pid;
    char buffer[20];

    if (pipe(fd) < 0)
    {
        printf("Pipe oluşturulamadı.\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork hatası.\n");
        return 1;
    }
    if (pid > 0) {
        close(fd[0]); // Okuma ucu kapatılır
        char *message = "Merhaba Dünya!";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]); // Yazma ucu kapatılır
        wait(NULL); // Child process'in bitmesi beklenir
    } else {
        close(fd[1]); // Yazma ucu kapatılır
        read(fd[0], buffer, sizeof(buffer));
        printf("Child process aldı: %s\n", buffer);
        close(fd[0]); // Okuma ucu kapatılır
        exit(0);
    }

    return 0;
}
*/

/*
int main()
{
    pid_t pid;
    int fd[2];
    char str[10];

    pipe(fd);

    pid = fork();
    
    if (pid > 0)
    {
        wait(NULL);
        printf("Ben parent process. sağ çocuk process id = %d - %d\n", pid, getpid());
        pid_t pid1;
        pid1 = fork();
        if (pid1 > 0)
        {
            wait(NULL);
            printf("Ben parent process. sol çocuk process id = %d - %d\n", pid1, getpid());
        }
        else if (pid1 == 0)
        {
            printf("Ben sol çocuk. %d - %d\n", pid1, getpid());
            close(fd[1]);
            read(fd[0], str, 5);
            printf("%s\n", str);
            close(fd[0]);
        }
    }
    else if (pid == 0)
    {
        printf("Ben sağ çocuk. %d - %d\n", pid, getpid());
        close(fd[0]);
        write(fd[1], "hello", 5);
        close(fd[1]);
    }
    close(fd[0]);
    close(fd[1]);
    //waitpid(-1, NULL, WUNTRACED);

    return (0);
}
*/