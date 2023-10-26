#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int c;
	fp = fopen("data.txt", "r");

	c = getc(fp);
	for(int i = 1; i < 52; i++) {
		putc(c, stdout);
		c = getc(fp);
	}
	fclose(fp);
	return 0;
}
