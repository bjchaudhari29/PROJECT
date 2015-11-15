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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SIZE 1024
#define SIZE1 26

typedef struct employee {
	char nav[64];
	int id;
	double salary;
	int attendance;
}employee;

typedef struct node {
	int sn;
	int quantity;
	char name[32];
	double price;
	int discount;
}product;
	
typedef struct client {
	char nm[64];
	int sn;
	double balance;
}customer;

typedef struct a {
	int sr;
	char item[32];
	int qt;
	double pr, disc;
	struct a *next, *prev;
}bnode;

typedef struct list{
	bnode *head, *tail;
}list;

typedef struct node1 {
	product pr;
	struct node *next;
}node;

node *hashtable[SIZE1];

void enterdata();
void editdata();
void addproduct();
void printdata();
void init(list *l);
void print_bill(list *l);
void create_bill(list *l);
double total_amt(list *l);
double total_disc(list *l);
void enter_employee();
void append_employee();
void printedata();
void mark_attendance(int num);
int hash (char *data);
void inithashtable();
void insert(int index, product p);
int getbucket(char *data);
void storedata(product p);
int search(char *data);
