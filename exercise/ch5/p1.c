#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    int x = 100;

        printf("x in process a(begin): %d\n", x);
    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    else if (rc == 0) {
        x = 200;
        printf("x in process b : %d (should be 200)\n", x);
    }
    else {
        int wc = wait(NULL);
    //    x = 300;
        printf("x in process a : %d (should be 300)\n", x);
    }
    
    return 0;
}