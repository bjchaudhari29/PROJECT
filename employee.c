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
 
/*This program stores Employees data and attendance in file
*Don't give spaces while writing names. Use "_" sign to distinguish first and midde name.
*/
#include "header.h"

/*This function create file and store data of employee*/

void enter_employee() {
	employee a[SIZE];
	int fd, j = 1;
	static int i = 0, k = 1;  
	fd = open("Employees", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed:\n");
		return;
	}
	while(j) {
		a[i].id = k;
		k++;
		printf("Enter name of employee :\n");
		scanf("%s", a[i].nav);
		printf("Enter salary :\n");
		scanf("%lf", &a[i].salary);
		a[i].attendance = 0;
		write(fd, &a[i], sizeof(a[0]));
		i++;
		printf("To enter Data press 1\nTo stop Press 0\n");
		scanf("%d", &j);
	}
	close(fd);
}

/*This function add employee in file which is new in shop*/

void append_employee() {
	static int i = 0, k = 1;
	int j = 1, n, x;
	employee a[SIZE];
	int fp = open("Employees", O_RDONLY);
	if(fp == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fp, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fp);
	int fd = open("Employees", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("open failed:\n");
		return;
	}
	i = n - 1;
	k = n + 1;
	while(j) {
		a[i].id = k;
		k++;
		printf("Enter name of employee :\n");
		scanf("%s", a[i].nav);
		printf("Enter salary :\n");
		scanf("%lf", &a[i].salary);
		a[i].attendance = 0;
		write(fd, &a[i], sizeof(a[0]));
		i++;
		printf("To enter Data press 1\nTo stop Press 0\n");
		scanf("%d", &j);
	}
	close(fd);
	return;
}

/*This function prints list of employees with salary attendance and id on screen*/
 
void printedata() {
	int fd;
	int x, i, n;
	employee a[SIZE];
	fd = open("Employees", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	printf("ID\tName Of Employee\t\tAttendance\tSalary\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t%d\t\t%lf\n", a[i].id, a[i].nav, a[i].attendance, a[i].salary);
	}
	close(fd);
	return;
}

/*This function marks attendance of employee after entering valid id*/
 
void mark_attendance(int num) {
	int fd, fp, n, x, i;
	employee a[SIZE];
	fp = open("Employees", O_RDONLY);
	
	if(fp == -1) {
		printf("Not able to edit\n");
		return;
	}
	x = read(fp, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fp);
	fd = open("Employees", O_WRONLY , S_IRUSR | S_IWUSR);
	if(fd == -1) {
		printf("Not able to edit\n");
		return;
	}
	for(i = 0; i < n; i++) {
		if(a[i].id == num) {
			a[i].attendance = a[i].attendance + 1;
			if(a[i].attendance == 30) {
				printf("Give salary to this employee\n");
				a[i].attendance == 0;
			}
			write(fd, &a[i], sizeof(a[0]));
		}
		else {
			write(fd, &a[i], sizeof(a[0]));
		}
	}
	close(fd);
	return;
}
