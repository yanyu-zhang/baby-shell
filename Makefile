CC = clang
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter

hello:
	$(CC) $(CFLAGS) -o hello hello.c

baby_shell: hello baby_shell.c
	$(CC) $(CFLAGS) -o baby_shell baby_shell.c

clean:
	rm -f baby_shell hello *.o *.out
	rm -rf *.dSYM

all: baby_shell
