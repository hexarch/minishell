#include <stdio.h>
#include <dirent.h>

/*

int main(int ac, char **) {
    DIR *dir;
    struct dirent *ent;

    // Dizin açma
    dir = opendir("denemedosya");
    if (dir == NULL) {
        printf("Could not open directory\n");
        return 1;
    }

    // Dizindeki tüm dosya adlarını okuma
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    // Dizin işaretçisini serbest bırakma
    closedir(dir);

    return 0;
}
*/