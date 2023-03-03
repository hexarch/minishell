#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*

int main(void)
{
    pid_t pid;

    char *argv[] = {"/bin/ls", "-1", NULL};

    pid = fork();

    if (pid == -1)
        return -1;

    if (pid == 0)
    {
        int val = execve(argv[0], argv, NULL);

        if (val == -1)
            perror("Error");
    }
    else
    {
        wait(NULL);
        printf("Done with execve\n");
    }
    return (0);
}
*/

/*
char *argv[] adında bir dizi oluşturur. 
Bu dizi, ls komutunun argümanlarını içerir. 
Bu argümanlar, "/bin/ls" (yürütülecek dosyanın tam yolu) ve -1 (listeleme modu) şeklindedir.

-a: Gizli dosyaları da gösterir.
-l: Dosyaların uzun formda listelenmesini sağlar. Dosyaların izinleri, 
sahibi, grup bilgisi, boyutu, oluşturma zamanı gibi detaylı bilgiler de dahil
olmak üzere daha fazla bilgi görüntüler.
-h: -l moduyla birlikte kullanılırsa, dosya boyutunu insan tarafından daha okunaklı bir biçimde gösterir.
-r: Dosyaları ters sırayla listeler.
-t: Dosyaları oluşturma tarihine göre listeler.
-R: Alt dizinleri de dahil olmak üzere tüm dizinleri rekürsif olarak listeler.
-G: Dosyaları renkli olarak gösterir.
*/