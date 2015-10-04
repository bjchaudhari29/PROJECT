#define SIZE 1024
#include <stdio.h>
#include <fcntl.h>
int main() {
	static int i = 0, k = 1;
	int j;
	struct product {
		int sn;
		int quantity;
		char name[32];
		double price;
	}a[SIZE];
	int fd = open("ALL products", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed:\n");
		return 1;
	}
	printf("To enter Data press 1\nTo stop Press 0\n");
	scanf("%d", &j);
	while(j) {
		a[i].sn = k;
		k++;
		printf("quantity :\n");
		scanf("%d", &a[i].quantity);
		printf("Enter name of product:\n");
		scanf("%s", a[i].name);
		printf("Enter price :\n");
		scanf("%lf", &a[i].price);
		write(fd, &a[i], sizeof(a[0]));
		i++;
		printf("To enter Data press 1\nTo stop Press 0\n");
       	     	scanf("%d", &j);
	}
	close(fd);
	return 0;
}
		
