#include <stdio.h>


int main(int a, char **v, char **e)
{
    while(*e)
    {
        printf("%s\n", *e);
        *e++;
    }
}
