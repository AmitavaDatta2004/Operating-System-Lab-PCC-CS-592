#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("1\n");
    fork();
    printf("2\n");
    fork();
    printf("3\n");
}