#include <stdio.h>
#define MAXLINE 80

int main(int argc, char *argv[]) {
	FILE *fp;
	int c;

	if(strcmp(argv[1], "-n") == 0) {
		fp = fopen(argv[2], "r");
		c = getc(fp);
		printf("1 ");
		while( c != EOF) {
			putc(c, stdout);
			c = getc(fp);
		}
	}
	else {
		for(int i = 1; i < argc; i++) {
			fp = fopen(argv[i], "r");
			c = fgetc(fp);
			while(c != EOF) {
				putc(c, stdout);
				c = fgetc(fp);
			}
			fclose(fp);
		}
	}
	return 0;
}
