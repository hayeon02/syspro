#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void almhandler();

int main() {
	signal(SIGALRM, almhandler);
	alarm(5);
	short i = 0;
	while (1) {
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
	printf("end\n");
}

void almhandler(int signo) {
	printf("Wake up\n");
	exit(0);
}
