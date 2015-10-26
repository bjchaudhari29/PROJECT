#include "header.h"

void payment(double amt) {
	int a, ch, i, x, n, fd;
	customer b[SIZE];
	char c[64];
	double bal, tbill, cash, rbal;
	
	printf("\n1 : New customer\n2 : Old customer\n");
	scanf("%d", &a);
	if(a == 1) {
		customerentry();

		fd = open("All customers", O_RDONLY);
		x = read(fd, &b, sizeof(b));
		n = x / sizeof(b[0]);
		close(fd);

		tbill = amt;
		
		printf("\nTo pay bill now press 1\nTo pay it later press 0\n");
		scanf("%d", &ch);
		
		if(ch == 0) {
			printf("\nYour current balance is = %lf\n", tbill); 
			fd = open("All customers", O_WRONLY , S_IRUSR | S_IWUSR);
			for(i = 0; i < n; i++) {
				if(i = n - 1) {
					b[i].balance = amt;
					write(fd, &b[i], sizeof(b[0]));
				}
				else {
					write(fd, &b[i], sizeof(b[0]));
				}
			}
		}
		if(ch == 1) {
			printf("Enter amount which customer wants to pay\n");
			scanf("%lf", &cash);
			rbal = tbill - cash;
			printf("Your current balance is = %lf\n", rbal);
			fd = open("All customers", O_WRONLY, S_IRUSR | S_IWUSR);
		
			for(i = 0; i < n; i++) {
				if(i = n - 1) {
					b[i].balance = amt;
					write(fd, &b[i], sizeof(b[0]));
				}
				else {
					write(fd, &b[i], sizeof(b[0]));
				}
			}
		}
	}

	if(a == 2) {
		printf("Enter name of customer\n");
		scanf(" %s", c);
		fd = open("All customers", O_RDONLY);
		x = read(fd, &b, sizeof(b));
		n = x / sizeof(b[0]);
		close(fd);	
 
		for(i = 0; i < n; i++) {
			if(!(strcmp(b[i].nm,c))) {
				bal = b[i].balance;
			}
		}
		tbill = bal + amt;
		printf("\nTotal bill including previous balance = %lf", tbill);
		
		printf("\nTo pay bill now press 1\nTo pay it later press 0\n");
		scanf("%d", &ch);

		if(ch == 0) {
			printf("\nYour current balance is = %lf\n", tbill); 
			fd = open("All customers", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
			for(i = 0; i < n; i++) {
				if(!(strcmp(b[i].nm,c))) {
					b[i].balance = tbill;
					write(fd, &b[i], sizeof(b[0]));
				}
				else {
					write(fd, &b[i], sizeof(b[0]));
				}
			}
			close(fd);
		}

		if(ch == 1) {
			printf("Enter amount which customer wants to pay\n");
			scanf("%lf", &cash);
			rbal = tbill - cash;
			printf("Your current balance is = %lf\n", rbal);
			fd = open("All customers", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
		
			for(i = 0; i < n; i++) {
				if(!(strcmp(b[i].nm,c))) {
					b[i].balance = rbal;
					write(fd, &b[i], sizeof(b[0]));
				}
				else {
					write(fd, &b[i], sizeof(b[0]));
				}
			}
			close(fd);
		} 			
	}
	return;			
}
