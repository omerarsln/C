#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    assert(argc > 1);
    FILE *arduino;

    int index;
    char buf[20];
    memset(buf, 0, 20);
    strcpy(buf, argv[1]);

    for(index = 2; index < argc; index++){
        strcat(buf, " ");
        strcat(buf, argv[index]);
    }

    int fd=open("/dev/FormatDev", O_RDWR);

    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}
