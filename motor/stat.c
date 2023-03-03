#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

/*
int main() {
    char filename[100];
    struct stat filestat;

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (stat(filename, &filestat) == -1) {
        printf("Error: Could not get file stats!\n");
        return 1;
    }

    printf("File size: %lldd bytes\n", filestat.st_size);
    printf("Created at: %s", ctime(&filestat.st_ctime));
    printf("Last modified at: %s", ctime(&filestat.st_mtime));
    printf("Permissions: %o\n", filestat.st_mode & 0777);

    return 0;
}
*/