#include "header.h"

int main() {
	int ch, j, k, c, w = 1;
	double amt;
	list l;
	while (w) {
		printf("\n1 : Products\n2 : Bill\n3 : Employee\n");
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
		case 3:
			printf("\nTo Enter employee record press 1\nTo add new employee press 2\nTo print list press 3\nTo mark attendance press 4\n");
			scanf(" %d", &k);
			switch(k) {
				case 1:
					enter_employee();
					break;
				case 2:
					append_employee();
					break;
				case 3:
					printedata();
					break;
				case 4:
					printf("Enter id of employee\n");
					scanf("%d", &c);
					mark_attendance(c);
					break;
			}
		}
		printf("\nTo stop Apllication press 0\nTo continue press 1\n");
		scanf("%d", &w);
	}
	return 0;
}
