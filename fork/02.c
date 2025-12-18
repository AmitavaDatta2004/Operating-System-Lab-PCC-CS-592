#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid==0){
        printf("I am the child\n");
        printf("My pid is %d\n",pid);
    } else {
        
        printf("I am the parent.\n");
        wait(NULL);
        printf("child finished\n");
    }
}