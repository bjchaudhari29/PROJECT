#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	int fd;
	int x, i, n, count;
	double k;
	struct product {
		int sn;
		int quantity;
		char name[32];
		double price;
	}a[1024];									
	fd = open("ALL products", O_RDONLY); 
	if(fd == -1) {
		printf("open failed\n");
		return 1;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	printf("Serial Number\tName Of Atom\tQuantity\tPrice\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t%d\t\t%lf\n", a[i].sn, a[i].name, a[i].quantity, a[i].price);
	}
	close(fd);
	return 0;
}  
