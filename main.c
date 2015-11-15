/*****************************************************************************
 * Copyright (C) Bhushan j. Chuadhari chaudharibhushan29.bc@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "header.h"

int main() {
	int ch, j, k, c, w = 1;
	list l;
	system("clear");
	printf("\t\t\t\t\t\t\t***WELCOME TO MALL***\n");
	while (w) {
		printf("\n\n\t\t\t\t1 : Products\n\t\t\t\t2 : Bill\n\t\t\t\t3 : Employee\n");
		scanf("%d", &j);
		system("clear");
		switch(j) {
		case 1:
			printf("\n\nPress 1 to start entering data\nPress 2 to add new product\nPress 3 to print list\nPress 4 to edit information\nPress 5 to see products to be ordered\nPress 6 to exit\n\n");
			scanf("%d", &ch);
			system("clear");
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
	
			init(&l);
			create_bill(&l);
			system("sleep 1");
			system("clear");
			print_bill(&l);
			printf("\n\n");
			break;
		case 3:
			printf("\nTo start Entering employee record press 1\nTo add new employee press 2\nTo print list press 3\nTo mark attendance press 4\n");
			scanf(" %d", &k);
			system("clear");
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
		//system("sleep 8");
		//system("clear");
		printf("\n\n\n\nTo stop Application press 0\nTo continue press 1\n");
		scanf("%d", &w);
		system("clear");
	}
	return 0;
}
