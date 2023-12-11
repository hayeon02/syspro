#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int pid1, pid2, child, status;
	printf("[%d] 부모 프로세스 시작 \n", getpid( ));
	pid1 = fork();
	if (pid1 == 0) {
		printf("[%d] 자식 프로세스[1] 시작 \n", getpid( ));
		sleep(1);
		printf("[%d] 자식 프로세스[1] 종료 \n", getpid( ));
		exit(1);
	}
}
