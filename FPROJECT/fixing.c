#include "header.h"

void init(list *l) {
	l->head = l->tail = NULL;
}

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
	k = total_amt(l);
	printf("Total Bill = %lf\n", k);
	z = total_disc(l);
	printf("You saved rs. %lf\n", z);
	return;
}

void create_bill(list *l) {
	bnode *tmp, *p;
	static int i = 1;
	int x, n, fd, j, m = 1, r, k, fp, s, t;
	double total = 0.00, pr;
	product a[SIZE], b[SIZE];
	fd = open("ALL products", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return;
	}
	x = read(fd, &a, sizeof(a));
	n = x / sizeof(a[0]);
	close(fd);
		int count = 0;
		if(l->head == NULL) {
			tmp = (bnode *)malloc(sizeof(bnode));
			tmp->sr = i;
			printf("Enter name of item purchased\n");
			scanf(" %[^\n]", tmp->item);
			printf("Enter quantity\n");
			scanf("%d", &(tmp->qt));
			for(j = 0; j < n; j++) {
				if(tmp) {
					if(!(strcmp(a[j].name,tmp->item))) {
						pr = 0.01 * a[j].discount * a[j].price;
						a[j].price = a[j].price - pr;
						tmp->disc = tmp->qt * pr;
						tmp->pr = tmp->qt * a[j].price;
						l->head = l->tail = tmp;
						tmp->next = tmp->prev = NULL;
						i++;
						count++;
						
						fp = open("ALL products", O_RDONLY);
						if(fp == -1) {
							printf("Not able to edit\n");
							return;
						}
						s = read(fp, &b, sizeof(b));
						t = x / sizeof(b[0]);
						close(fp);
						
						fd = open("ALL products", O_WRONLY , S_IRUSR | S_IWUSR);
						
						for(k = 0; k < t; k++) {
							if(!(strcmp(b[k].name,tmp->item))) {
								b[k].quantity = b[k].quantity - tmp->qt;
								write(fd, &b[k], sizeof(b[0]));
							}
							else
								write(fd, &b[k], sizeof(b[0]));
						}
						close(fd);
						tmp = tmp->next;
					}
				}
			}
			if(count == 0)
				printf("Item is not available in shop\n");
		}
		else {
			tmp = (bnode *)malloc(sizeof(bnode));
			tmp->sr = i;
			printf("Enter name of item purchased\n");
			scanf(" %[^\n]", tmp->item);
			printf("Enter quantity\n");
			scanf("%d", &(tmp->qt));
			for(j = 0; j < n; j++) {
				if(tmp) {
					if(!(strcmp(a[j].name,tmp->item))) {
						pr = 0.01 * a[j].discount * a[j].price;
						a[j].price = a[j].price - pr;
						tmp->pr = tmp->qt * a[j].price;
						tmp->disc = tmp->qt * pr;
						tmp->prev = l->tail;
						tmp->next = NULL;
						l->tail->next = tmp;
						l->tail = tmp;
						i++;
						count++;
						
						fp = open("ALL products", O_RDONLY);
						if(fp == -1) {
							printf("Not able to edit\n");
							return;
						}
						s = read(fp, &b, sizeof(b));
						t = x / sizeof(b[0]);
						close(fp);
						
						fd = open("ALL products", O_WRONLY , S_IRUSR | S_IWUSR);
						
						for(k = 0; k < t; k++) {
							if(!(strcmp(b[k].name,tmp->item))) {
								b[k].quantity = b[k].quantity - tmp->qt;
								write(fd, &b[k], sizeof(b[0]));
							}
							else
								write(fd, &b[k], sizeof(b[0]));
						}
						close(fd);
						tmp = tmp->next;
					}
				}
			}
			if(count == 0)
				printf("Item is not available in shop\n");
		}	
	printf("press 0 to stop\nPree 1 to continue\n");
	scanf("%d", &m);
	if(m == 1) {
		create_bill(l);
	}
	return;
}

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
