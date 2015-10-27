#include "header.h"

void enterdata() {
	static int i = 0, k = 1;
	int j = 1;
	product a[SIZE];
	int fd = open("ALL products", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed:\n");
		return;
	}
	while(j) {
		a[i].sn = k;
		k++;
		printf("quantity :\n");
		scanf("%d", &a[i].quantity);
		printf("Enter name of product:\n");
		scanf(" %[^\n]", a[i].name);
		printf("Enter price :\n");
		scanf("%lf", &a[i].price);
		printf("Enter discount\n");
		scanf("%d", &a[i].discount);
		write(fd, &a[i], sizeof(a[0]));
		i++;
		printf("To enter Data press 1\nTo stop Press 0\n");
		scanf("%d", &j);
	}
close(fd);
}

void printdata() {
	int fd;
	int x, i, n, count;
	double k;
	product a[SIZE];
	fd = open("ALL products", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	printf("Serial Number\tName Of Product\tQuantity\tPrice\t\tDiscount in perc\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t%d\t\t%lf\t\t%d\n", a[i].sn, a[i].name, a[i].quantity, a[i].price, a[i].discount);
	}
	close(fd);
	return;
}

void appenddata() {
	static int i = 0, k = 1;
	int j = 1, n, x;
	product a[SIZE];
	int fp = open("ALL products", O_RDONLY);
	if(fp == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fp, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fp);
	int fd = open("ALL products", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed:\n");
		return;
	}
	i = n - 1;
	k = n + 1;
	while(j) {
		a[i].sn = k;
		k++;
		printf("quantity :\n");
		scanf("%d", &a[i].quantity);
		printf("Enter name of product:\n");
		scanf("%s", a[i].name);
		printf("Enter price :\n");
		scanf("%lf", &a[i].price);
		printf("Enter discount\n");
		scanf("%d", &a[i].discount);
		write(fd, &a[i], sizeof(a[0]));
		i++;
		printf("To continue adding new product press 1\nTo stop Press 0\n");
		scanf("%d", &j);
	}
	close(fd);
	return;
}

void editdata () {
	int fd, fp, n, x, i, ch, q;
	char z[32];
	double k;
	product a[SIZE];
	fp = open("ALL products", O_RDONLY);
	
	if(fp == -1) {
		printf("Not able to edit\n");
		return;
	}
	x = read(fp, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fp);
	printf("Press 1 to change price of atom\nPress 2 to change no atoms present in shop\nPress 3 to change discount on item\n");
	scanf("%d", &ch);
	printf("Enter the name of product\n");
	scanf(" %[^\n]", z);
	fd = open("ALL products", O_WRONLY , S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("Not able to edit\n");
		return;
	}
	for(i = 0; i < n; i++) {
		if(!(strcmp(a[i].name,z)) && ch == 1) {
			printf("Enter new price\n");
			scanf("%lf", &k);
			a[i].price = k;
			write(fd, &a[i], sizeof(a[0]));
		}
		else if(!(strcmp(a[i].name,z)) && ch == 2) {
			printf("Enter quantity\n");
			scanf("%d", &q);
			a[i].quantity = q;
			write(fd, &a[i], sizeof(a[0]));
		}
		else if(!(strcmp(a[i].name,z)) && ch == 3) {
			printf("Enter Discount\n");
			scanf("%d", &q);
			a[i].discount = q;
			write(fd, &a[i], sizeof(a[0]));
		}
		else
			write(fd, &a[i], sizeof(a[0]));
	}
	close(fd);
	return;
}

void tobeordered() {
	product a[SIZE];
	int fp, fd, x, i, n, count;
	fp = open("ALL products", O_RDONLY);
	if(fp == -1) {
		printf("Not able to edit\n");
		return;
	}
	x = read(fp, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fp);
	fd = open("To be ordered",  O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	for(i = 0; i < n; i++) {
		if(a[i].quantity == 0) {
			write(fd, &a[i], sizeof(a[0]));
		}
	}
	close(fd);
	fd = open("To be ordered", O_RDONLY);
	if(fd == -1) {
		printf("All products are available\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	printf("Serial Number\tName Of Atom\tPrice\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t%lf\n", i + 1, a[i].name, a[i].price);
	}
	close(fd);
	return;
}