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

/*This function initialise th list which is used
*while creating a bill*/

void init(list *l) {
	l->head = l->tail = NULL;
}

/* This function prints the bill i.e. linklist on screen*/
 
void print_bill(list *l) {
	printf("Sr\tName\tQuantity\tprice\tDiscount\n");
	double k, z;
	bnode *p;
	p = l->head;
	while(p != l->tail) {
		printf("%d\t", p->sr);
		printf("%s\t", p->item);
		printf("%d\t", p->qt);
		printf("%lf\t", p->pr);
		printf("%lf\n", p->disc);
		p = p->next;
	}
	if(p) {
		printf("%d\t", p->sr);
		printf("%s\t", p->item);
		printf("%d\t", p->qt);
		printf("%lf\t", p->pr);
		printf("%lf\n", p->disc);
	}
	k = total_amt(l);                     //Also compute total bill
	printf("Total Bill = %lf\n", k);
	z = total_disc(l);                     //compute total discount
	printf("You saved rs. %lf\n", z);
	return;
}

/*This function creates hashtable and stores all information in it
*Also it creates bill by taking inputs of buyed atoms
*it stores bill in form of linked list*/
 
void create_bill(list *l) {
	bnode *tmp;
	static int i = 1;
	int x, n, fd, j, m = 1, fp, z, rs;
	double pr;
	
	product a[SIZE];
	fd = open("ALL products", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fd);
	
	inithashtable();
	for(j = 0; j < n; j++) 
		storedata(a[j]);
		
		int count = 1;
		while(m) {
			if(l->head == NULL) {
				tmp = (bnode *)malloc(sizeof(bnode));
				tmp->sr = i;
				printf("Enter name of item purchased\n");
				scanf(" %[^\n]", tmp->item);
				printf("Enter quantity\n");
				scanf("%d", &(tmp->qt));
				z = search(tmp->item);
				if(z != -1) {
						int loc = hash(tmp->item);
						node *p = hashtable[loc];
						while(p) {
							if(strcmp(p->pr.name, tmp->item) == 0)
								break;
							p = p->next;
						}
						pr = 0.01 * p->pr.discount * p->pr.price;
						rs = p->pr.price - pr;
						p->pr.quantity = p->pr.quantity - tmp->qt;
						tmp->disc = tmp->qt * pr;
						tmp->pr = tmp->qt * rs;
						l->head = l->tail = tmp;
						tmp->next = tmp->prev = NULL;
						i++;
					
						
				}
				if(z == -1)
					printf("Item is not available in shop\n");
			}
			else {
				tmp = (bnode *)malloc(sizeof(bnode));
				tmp->sr = i;
				printf("Enter name of item purchased\n");
				scanf(" %[^\n]", tmp->item);
				printf("Enter quantity\n");
				scanf("%d", &(tmp->qt));
				z = search(tmp->item);
				if(z != -1) {
						int loc = hash(tmp->item);
						node *p = hashtable[loc];
						while(p) {
							if(strcmp(p->pr.name, tmp->item) == 0)
								break;
							p = p->next;
						}	
						pr = 0.01 * p->pr.discount * p->pr.price;
						rs = p->pr.price - pr;
						p->pr.quantity = p->pr.quantity - tmp->qt;
						tmp->pr = tmp->qt * p->pr.price;
						tmp->disc = tmp->qt * pr;
						tmp->prev = l->tail;
						tmp->next = NULL;
						l->tail->next = tmp;
						l->tail = tmp;
						i++;
				}
				if(z == -1)
					printf("Item is not available in shop\n");
			}	
		printf("press 0 to stop\nPree 1 to continue\n");
		scanf("%d", &m);
	}
	
	fp = open("ALL products", O_WRONLY , S_IRUSR | S_IWUSR);
	if(fp == -1) {
		printf("Not able to edit\n");
		return;
	}
/*this snipet of code modify quantities of atoms in file and restore them in file*/
	
	for(j = 0; j < SIZE1; j++) {
		if(hashtable[j]) {
			node *g = hashtable[j];
			while(g) {
				product u;
				u = g->pr;
				u.sn = count;
				count++;
				write(fp, &u, sizeof(product));
				g = g->next;
			}
		}
	}
	close(fp);
	
	
	return;
}

/*This function calculates total amount of bill by list l as argument*/

double total_amt(list *l) {
	double total;
	bnode *p;
	p = l->head;
	while(p != l->tail) {
		total = total + p->pr;
		p = p->next;
	}
	if(p) {
		total = total + p->pr;
	}
	return total;
}

/*This function calculates total amount of bill by list l as argument*/

double total_disc(list *l) {
	double total;
	bnode *p;
	p = l->head;
	while(p != l->tail) {
		total = total + p->disc;
		p = p->next;
	}
	if(p) {
		total = total + p->disc;
	}
	return total;
}

/*This is hash function which hashes the data*/

int hash (char *data) {
	return (*data - 'a') % SIZE;
} 

/*Initialises the hash table**/

void inithashtable() {
	int i;
	for(i = 0; i < SIZE1; i++)
		hashtable[i] = NULL; 
}

/*Stores data  in hash table*/

void insert(int index, product p) {
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->pr = p;
	tmp->next = hashtable[index];
	hashtable[index] = tmp;
}

/*This function used while searching a particular atom in hash table*/

int getbucket(char *data) {
	int loc = hash(data);
	return loc;
}

void storedata(product p) { 
	int loc = getbucket(p.name);
	insert(loc, p);
}

/*This function search data in hash table*/

int search(char *data) {
	int loc = hash(data);
	node *p = hashtable[loc];
	while(p) {
		if(strcmp(p->pr.name, data) == 0)
			return loc;
		p = p->next;
	}
	return -1;
}
