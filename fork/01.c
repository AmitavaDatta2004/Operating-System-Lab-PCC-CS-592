#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();
    
    if(pid==0){
        printf("Child created\n");
        printf("Child PID = %d\n",getpid());
        printf("My parent ID = %d\n",getppid());
    } else {
        printf("Parent running\n");
        printf("Parent PID = %d\n",getpid());
        printf("Child PID = %d\n",pid);
    }
    return 0;
}