#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    int rc = fork();

    if (rc == 0) {
        // process b
        printf("child process\n");
    }
    else {
        // process a
        sleep(1);
        printf("parent process\n");
    }

    return 0;
}