#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    char msg[100];

    pipe(fd);
    if (fork()==0){
        close(fd[1]);
        
        read(fd[0],msg,sizeof(msg));
        printf("the message is %s\n",msg);
        close(fd[0]);
    } else {
        close(fd[0]);
        printf("Enter the message:");
        scanf("%s",msg);
        write(fd[1],msg,sizeof(msg));
        close(fd[1]);
    }

}