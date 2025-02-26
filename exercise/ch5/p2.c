#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    close(STDOUT_FILENO);
    int fd = open("p2.output", O_CREAT | O_RDWR, 0777);
    printf("This is begin of the process XXX\n"); 
    
    int rc = fork();

    if (rc == 0) {
        // process b
        printf("This is process b\n");
    }
    else {
        int wc = wait(NULL);
        // process a
        printf("This is process a\n");
    }

    printf("\n\n\n\n\n");
    return 0;
}