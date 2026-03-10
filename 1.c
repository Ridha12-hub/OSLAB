#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2];
    pid_t pid;
    char write_message[]="Hello from parent";
    char read_message[100];
    if(pipe(fd)==-1){
        perror("pipe failed");
        return 1;
    }
    pid=fork();
    if(pid<0){
        perror("fork failed");
        return 1;
    }else if(pid>0){
        close(fd[0]);
        write(fd[1],write_message,sizeof(write_message));
        close(fd[1]);
    }else{
        close(fd[1]);
        read(fd[0],read_message,sizeof(read_message));
        printf("child received: %s\n", read_message);
        close(fd[0]);
    }
return 0;
}