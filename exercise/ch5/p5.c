#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    int rc = fork();

    if (rc == 0) {
        printf("child pid : %d\n",(int)getpid());
        printf("child wait() return : %d\n", wait(NULL));
        // process b
    }
    else {
        // process a
        printf("parent pid : %d\n",(int)getpid());
        int wc = wait(NULL);
        printf("parent process\n");
        printf("wait() return : %d\n", wc);
    }

    return 0;
}