#include "header.h"
int main() {
	int ch, j;
	double amt;
	list l;
	printf("\n1 : Products\n2 : Bill\n");
	scanf("%d", &j);
	switch(j) {
	case 1:
		printf("\n\nPress 1 to enterdata\nPress 2 to add new product\nPress 3 to print list\nPress 4 to edit information\nPress 5 to see products to be ordered\nPress 6 to exit\n\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				enterdata();
				break;
			case 2:
				appenddata();
				break;
			case 3:
				printdata();
				break;
			case 4:
				editdata();
				break;
			case 5:
				tobeordered();
				break;
			case 6:
				return 1;
			}
		break;
	case 2:
		//print_customer();
		init(&l);
		create_bill(&l);
		print_bill(&l);
		printf("\n\n");
		break;
	}
	return 0;
}
