#include "header.h"

void customerentry() {
	static int i = 0, k = 1;
	int j = 1, x, n;
	customer a[SIZE];
	int fp = open("All customers", O_RDONLY);
	if(fp == -1) {
		int fd = open("All customers", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);		
		a[i].sn = k;
		k++;
		printf("Enter name of customer\n");
		scanf(" %s", a[i].nm);
		a[i].balance = 0.00;
		write(fd, &a[i], sizeof(customer));
		close(fd);
		return;
	}
	else {
		int fp = open("All customers", O_RDONLY);
		if(fp == -1) {
			printf("open failed\n");
			return;
		}
		x = read(fp, &a, sizeof(a));
		n = x / sizeof(a[0]);
		close(fp);
		int fd = open("All customers", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
		if(fd == -1) {
			printf("open failed:\n");
			return;
		}
		i = n;
		k = n + 1;
		a[i].sn = k;
		printf("Enter name of customer\n");
		scanf(" %s", a[i].nm);
		a[i].balance = 0.00;
		write(fd, &a[i], sizeof(a[0]));
		close(fd);
		return;
	}
}

void print_customer() {
	int fd;
	int x, i, n, count;
	double k;
	customer a[SIZE];
	fd = open("All customers", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	printf("Serial Number\tName Of Customer\t\t\t\tBalance\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t\t\t\t%lf\n", a[i].sn, a[i].nm, a[i].balance);
	}
	close(fd);
	return;
}
