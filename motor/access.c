#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int main() 
{
    char *file_path = "deneme.txt";

    if(access(file_path, F_OK) == 0) {
        printf("File exists!\n");
    } else {
        printf("File does not exist.\n");
        exit(1);
    }
    if(access(file_path, R_OK) == 0) {
        printf("File is readable.\n");
    } else {
        printf("File is not readable.\n");
    }
    if(access(file_path, W_OK) == 0) {
        printf("File is writable.\n");
    } else {
        printf("File is not writable.\n");
    }
    if(access(file_path, X_OK) == 0) {
        printf("File is executable.\n");
    } else {
        printf("File is not executable.\n");
    }
    return 0;
}
*/

/*
R_OK: Dosyanın veya dizinin okunabilir olup olmadığını kontrol eder.
W_OK: Dosyanın veya dizinin yazılabilir olup olmadığını kontrol eder.
X_OK: Dosyanın veya dizinin çalıştırılabilir olup olmadığını kontrol eder.
F_OK: Dosyanın veya dizinin var olup olmadığını kontrol eder.

"access()" fonksiyonu, başarılı olursa sıfır (0) değerini döndürür. 
Aksi takdirde, -1 değerini döndürür ve "errno" değişkeni, 
hatanın türünü belirten bir hata koduyla ayarlanır.
*/