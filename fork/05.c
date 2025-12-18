#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if(pid == 0) {
        printf("Child process exiting\n");
        exit(0);
    } else {
        sleep(10);  // Parent sleeps, does not wait
        printf("Parent process awake\n");
    }

    return 0;
}
