#include <stdio.h>
#include <unistd.h>

int main()
{
    for (int i = 1;; i *= 2)
    {
        printf("%d \n", i);
        sleep(1);
    }
}
