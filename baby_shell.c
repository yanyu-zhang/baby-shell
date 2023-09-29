#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *baby_shell_read_line(void) {
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

int baby_shell_execute(char *line) {
    if (strcmp(line, "exit\n") == 0) {
        return 0;
    }
    printf("hello");
    return 1;
}

void baby_shell_loop() {
    char *line;
    int status;

    do {
        printf("BS> ");
        line = baby_shell_read_line();
        status = baby_shell_execute(line);

        free(line);
    } while (status);
}

int main(int argc, char *argv[]) {
    baby_shell_loop();

    return EXIT_SUCCESS;
}
