#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2], fdt[2];

    pipe(fd1); pipe(fd2); pipe(fdt);

    struct timeval tv_bg, tv_ed;

    cpu_set_t set;

    CPU_SET(0, &set);

    int n;
    printf("Please input number of tests :");
    scanf("%d", &n);

    int rc = fork();
    if (rc == 0) {
        pid_t pid = getpid();
        sched_setaffinity(pid, sizeof(cpu_set_t), &set);

        for (int i = 0; i < n; i ++) {
            write(fd1[1], NULL, 0);
            read(fd2[0], NULL, 0);
        }

        gettimeofday(&tv_ed, NULL);

        read(fdt[0], &tv_bg, sizeof(tv_bg));

        float totalTime = tv_ed.tv_sec * 1000000 + tv_ed.tv_usec - tv_bg.tv_sec * 1000000 - tv_bg.tv_usec;

        printf("Total time of %d switch : %f us\n", n*2, totalTime);
        printf("Average time : %f us\n", totalTime / 2 / n); 
    }
    else {
        pid_t pid = getpid();
        sched_setaffinity(pid, sizeof(cpu_set_t), &set);

        gettimeofday(&tv_bg, NULL);

        for (int i = 0; i < n; i ++) {
            read(fd1[0], NULL, 0);
            write(fd2[1], NULL, 0);
        }

        write(fdt[1], &tv_bg, sizeof(tv_bg));
    }
}