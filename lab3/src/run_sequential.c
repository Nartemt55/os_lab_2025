#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        char *args[] = {"./sequential_min_max", "123", "1000", NULL};
        
        execvp(args[0], args);

        perror("execvp failed");
        exit(1);
    } else {
        int status;
        wait(&status);
        printf("Sequential min/max finished with code %d\n", WEXITSTATUS(status));
    }

    return 0;
}