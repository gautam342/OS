#include<stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("File open failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        char *child_msg = "This line is written by the child process.\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
    }
    // Parent process
    else {
        wait(NULL); // Wait for child to terminate
        char *parent_msg = "This line is written by the parent process.\n";
        write(fd, parent_msg, strlen(parent_msg));
        close(fd);
    }

    return 0;
}
    

