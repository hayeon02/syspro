#include <stdio.h>
#include "storecreate.h"

int main(int argc, char* argv[]) {
	struct storecreate rec;
	FILE *fp;	
	fp = fopen("db.dat", "wb");
	
	printf("%s   ", "id");
	printf("%s   ", "name");
	printf("%s   ", "category");
	printf("%s   ", "expired_date");
	printf("%s\n", "stock");
	
	while(scanf("%d %s %s %d %d", &rec.ID, rec.name, rec.category, &rec.expired_date, &rec.stock) == 5)
		fwrite(&rec, sizeof(rec), 5, fp);
	fclose(fp);
	exit(0);
}
