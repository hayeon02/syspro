#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
	char i;
	char **ptr;
	extern char **environ;

	if(strcmp(argv[1], "-e") == 0) {
		if(argv[2] == NULL) {
			for(ptr = environ; *ptr != 0; ptr++)
				printf("%s \n", *ptr);
		}
		else {
			printf("%s = %s \n", argv[2], getenv(argv[2]));
		}
	}
	else if(strcmp(argv[1], "-g") == 0) {
		printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
		printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
	}
	else if(strcmp(argv[1], "-u") == 0) {
		printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
		printf("My Valid User ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	}
	else if(strcmp(argv[1], "-i") == 0){
		printf("my process number : [%d]\n", getpid());
	}
	else if(strcmp(argv[1], "-p") == 0){
		printf("my parent's process number : [%d]\n", getppid());
	}
	else
		printf("\n");
	exit(0);
}
