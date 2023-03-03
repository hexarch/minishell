#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// Creating and Killing Child Processes in C

// ---*** fork() ***---

/*
Fork() fonksiyonu, iki kez geri döndürür: bir kez ebeveyn işlem için ve bir kez de çocuk
işlem için. Ebeveyn işlem için, fork() fonksiyonu, çocuk işlemin işlem kimliğini (process 
ID) döndürürken, çocuk işlem için ise 0 değerini döndürür.
*/

// Creating

/*
int main()
{
    pid_t pid;
    pid = fork();

    if (pid > 0) // parent
    {
        printf("parent: %d my pid: %d\n", pid, getpid());
    }
    if (pid == 0) // child
    {   
        printf("child: %d my pid: %d\n", pid, getpid());
    }
    if (pid < 0)
    {
        printf("error");
    } 
}
*/

// Example about Fork()
/*
Çocuk işlem, fork() fonksiyonu çağrısından önce ana işlem tarafından atanan 
değişkenlerin ve bellek alanının bir kopyasına sahiptir. Bu nedenle, çocuk işlem, fork()
onksiyonu çağrısından sonra ana işlemde yapılan değişikliklerin kopyasını almaz, ancak bu 
değişkenlere erişebilir ve değerlerini okuyabilir.

Çocuk işlem, x ve y değişkenlerine erişebilir ve değerlerini 
okuyabilir. Ancak, çocuk işlem, result değişkenini sadece kendisi için oluşturmuştur ve 
bu nedenle, ebeveyn işlemde yapılan değişikliklerin bir kopyasını almaz.

Dolayısıyla, çocuk işlem result değişkenini sadece kendi hesaplamaları için kullanabilir 
ve bu hesaplamaların sonucunu yazdırabilir.
*/

/*
int main()
{
    int x,y,result;
    x = 42;
    y = 30;

    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        result = x + y;
        printf("Parent process %d\n", result);
    }
    else if (pid == 0)
    {
        result = x - y;
        printf("Child process %d\n", result);
    }
    return (0);
}
*/

// Example about Race Conditions

/*
int main()
{
    int x,y,result;
    x = 42;
    y = 30;

    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        wait(NULL); // Child process bitene kadar bekle 
        result = x + y;
        printf("Parent process %d\n", result);
    }
    else if (pid == 0)
    {
        result = x - y;
        printf("Child process %d\n", result);
    }
    return (0);
}
*/

/*
Child ve Parent prosesin değerleri fork() yaratıldığı anda kopyalanıyor.
Daha sonra iki proses birbirinin değerini etkilemiyor. 
Burada Parent ve child prosesin birbirinden bağımsız olarak kendi adres alanları var.
Yani ram üzerinde ikiside tamamen farklı bir alanda varlıklarını sürdürüyorlar.
Dolayısıyla kendi değişkenleri de birbirinden bağımsız oluyor.
Bir diğer değişle child parenttan bir değişkeni miras aldı ama
aldıktan sonra o değişken artık child üzerinde çalışan bambaşka bir değişken oldu.
*/

/*
int main()
{
    int x,y,result;
    x = 42;
    y = 30;
    // result = 1;
    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        wait(NULL);
        result = result * 2;
        printf("Parent process %d\n", result);
    }
    else if (pid == 0)
    {
        result = x - y;
        printf("Child process %d\n", result);
    }
    return (0);
}
*/

/*
int main()
{
    pid_t pid;

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
        }
    }
    else if (pid == 0)
    {
        printf("Ben sağ çocuk. %d - %d\n", pid, getpid());
    }
}
*/

// ---*** wait() | exit() ***---

/*
exit(0) fonksiyonu, C programının normal bir şekilde sonlandığını belirtmek için kullanılır.
exit(0) kullanımının amacı, programın belirtilen çıkış kodu (exit code) ile sonlandırılmasını sağlamaktır.
Çıkış kodu, programın diğer programlarla etkileşim halindeyken bir hata durumunda ne yapması gerektiğini belirtir. 
Genellikle, 0 normal bir çıkış kodu olarak kabul edilirken, farklı çıkış kodları, farklı hata durumlarına karşılık gelir.
exit() fonksiyonu, programın herhangi bir yerinde çağrılabilir ve programın o noktada sonlandırılmasını sağlar. 
Bu nedenle, exit() fonksiyonu, programların güvenli bir şekilde sonlandırılmasını sağlamak için önemlidir.
Bir diğer kullanım alanı ise, bir işlemci (process) içinde birden fazla işlem yürütülürken,
bir işlem normal bir şekilde tamamlandığında, exit() fonksiyonu kullanılarak işlem
sonlandırılır ve işlemci kaynakları serbest bırakılır.
Bu, programın daha düzenli bir şekilde çalışmasına yardımcı olur ve kaynak atıklarını önler.
*/

/*
wait(NULL) fonksiyonu, bir çocuk işleminin tamamlanmasını beklemek için kullanılır.
wait(NULL) fonksiyonunun bir başka kullanım alanı ise, 
birden fazla çocuk işleminin tamamlanmasını beklemek için kullanılmasıdır.
*/

/*
int main()
{
    int id = fork();
    int n;
    if (id == 0)
        n = 1;
    else 
        n = 6;
    if (id != 0)
        wait(NULL);
    int i;
    if (id == 0)
    {
        for (i = n; i < n + 5; i++)
        {
            printf("%d ", i);
            fflush(stdout);
        }
        printf("Child process ");
        exit(0);
    }
    else if (id > 0)
    {
        for (i = n; i < n + 5; i++)
        {
            printf("%d ", i);
            fflush(stdout);
        }
        printf("Parent process\n");
    }
}
*/

// ---*** waitpid() ***---

/*
waitpid() fonksiyonu, wait() fonksiyonuna benzer bir şekilde, bir çocuk işleminin tamamlanmasını beklemek için kullanılır.
waitpid() fonksiyonu, wait() fonksiyonuyla benzer şekilde çalışır ancak belirtilen pid 
numarasına sahip çocuk işlemi tamamlanmadan önce ana işlemi bekletir. 
Bu fonksiyon, bir çocuk işlemin tamamlanmasını beklerken diğer işlemlerin çalışmasını sürdürür
ve bir çocuk işlem tamamlandığında, çocuğun pid numarasını döndürür.
waitpid() fonksiyonunun en büyük avantajı, belirli bir çocuk işlemi için beklemeye izin vermesidir.
Bu, özellikle birçok çocuk işlemi oluşturulduğunda ve her biri farklı bir işlem yaparken,
bir çocuk işleminin tamamlanmasını beklemeniz gerektiğinde faydalıdır.

-- pid_t waitpid(pid_t pid, int *status, int options); --

pid: Hangi çocuk işleminin tamamlanmasını bekleyeceğimizi belirten bir pid (process ID) numarası.
Eğer pid negatif bir değer ise, işlev, hangi çocuk işleminin tamamlandığına bakılmaksızın herhangi bir çocuk işlemi için bekler.

status: Çocuk işlemin sonlandırma durumunu tutmak için kullanılır. wait() 
fonksiyonunda olduğu gibi, bu işlev NULL olarak da atanabilir.

options: İşlevin davranışını belirleyen işaretçilerin bir listesidir. 
Bu, özel bir işlev çağrısı sırasında veya yalnızca bir işlemin bitmesine yanıt olarak bazı sinyallerin bloke edilmesi gerektiğinde kullanılır.
*/

/*
int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("I am the child process.\n");
        exit(0);
    }
    else {
        printf("I am the parent process.\n");
        waitpid(pid, &status, 0);
        printf("Child process exited with status %d.\n", status);
    }
    return 0;
}
*/

// Killing

/*
int main()
{
    pid_t pid;

    pid = fork();

    if (pid > 0)
    {
        printf("I am the parent process.\n");
        sleep(5);
        printf("Parent process is done sleeping.\n");
        kill(pid, SIGTERM);
        printf("Parent process has sent SIGTERM to the child process.\n");

    }
    else if (pid == 0)
    {
        printf("I am the child process.\n");
        sleep(10);
        printf("Child process is done sleeping.\n");
        exit(0);
    }
    else 
    {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    }
    return (0);
}
*/
