#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int n;
    printf("input number of system call :");
    scanf("%d", &n);
    
    struct timeval begin_time, end_time;

    gettimeofday(&begin_time, NULL);

    for (int i = 0; i < n; i ++) {
        read(0, NULL, 0);
    }

    gettimeofday(&end_time, NULL);
    float total_time = -(float)(begin_time.tv_usec + begin_time.tv_sec * 1000000 - end_time.tv_usec - end_time.tv_sec * 1000000); 
    printf("Total time of %d system calls : %f us\n", n, total_time);
    printf("Average time : %f us\n",total_time / n);
    return 0;
}