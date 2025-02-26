#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd[2];

    pipe(fd);

    char input_str[100];


    scanf("%s", input_str);

    int p = fork();

    if (p == 0) {
        close(fd[0]); // close reading end
        write(fd[1], input_str, strlen(input_str) + 1);
        printf("Input string: %s \n", input_str);
        close(fd[1]);
    }
    else {
       waitpid(p, NULL, 0);
        close(fd[1]); // close writing end
        
        char get_str[100];

        read(fd[0], get_str, 100);

        printf("Final string: %s is my son. \n", get_str);
        close(fd[0]);

    }

    return 0;
}