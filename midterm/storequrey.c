#include <stdio.h>
#include "storecreate.h"

int main(int argc, char *argv[]) {
	struct storecreate rec;
	FILE *fp;
	int c;
	fp = fopen("db.dat", "rb");

	printf("--Goods query--\n");
	printf("0: list of all goods, 1: list of available goods  ");
	scanf("%d", &c);

	printf("%s", "id");
	printf("%13s", "name");
	printf("%13s", "category");
	printf("%13s", "expired_date");
	printf("%13s\n", "stock");

	if(c == 0) {
		while (fread(&rec, sizeof(rec), 5, fp) > 0) { 
			if (rec.ID != 0) {
				printf("%d", rec.ID);
				printf("%13s", rec.name);
				printf("%13s", rec.category);
				printf("%13d", rec.expired_date);
				printf("%13d\n", rec.stock);
			}
		}
	}
	else{
		while (fread(&rec, sizeof(rec), 5, fp) > 0) {
			if (rec.ID != 0 && rec.expired_date >= 2023 && rec.stock != 0) {
				printf("%d", rec.ID);
				printf("%13s", rec.name);
				printf("%13s", rec.category);
				printf("%13d", rec.expired_date);
				printf("%13d\n", rec.stock);
			}
		}
	}
	fclose(fp);
	return 0;
}

