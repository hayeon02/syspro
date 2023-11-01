#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]) 
{
   char buffer[BUFSIZE];
   int fd;
   ssize_t nread;
   long total = 0;
   char savedText[10][100];
   int line, j, y, t = 0;
   int bb = 0;

   fd = open(argv[1], O_RDONLY);

   while( (nread = read(fd, &buffer, 1)) > 0) {
	   for(int i = 0; i < nread; i++) {
		   j = buffer[i];
		   savedText[y][t] = j;
		   t++;
		   if(j == '\n') {
			   savedText[y][t]= '\0';
			   line++;
			   y++;
			   t = 0;
		   }
	   }
   }
   close(fd);
   printf("%s", savedText[3]);
   printf("%s", savedText[2]);
   printf("%s", savedText[1]);
   printf("%s", savedText[0]);
   exit(0);
}

