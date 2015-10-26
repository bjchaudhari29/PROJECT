#include "header.h"

void init(list *l) {
	l->head = l->tail = NULL;
}

void print_bill(list *l) {
	double k;
	bnode *p;
	p = l->head;
	while(p != l->tail) {
		printf("%d\t", p->sr);
		printf("%s\t", p->item);
		printf("%d\t", p->qt);
		printf("%lf\n", p->pr);
		p = p->next;
	}
	if(p) {
		printf("%d\t", p->sr);
		printf("%s\t", p->item);
		printf("%d\t", p->qt);
		printf("%lf\n", p->pr);
	}
	k = total_amt(l);
	printf("Total Bill = %lf\n", k);
	//payment(k);
	return;
}

void create_bill(list *l) {
	bnode *tmp, *p;
	static int i = 1;
	int x, n, fd, j, m = 1, r;
	double total = 0.00;
	product a[SIZE];
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
						tmp->pr = tmp->qt * a[j].price;
						l->head = l->tail = tmp;
						tmp->next = tmp->prev = NULL;
						tmp = tmp->next;
						i++;
						count++;
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
						tmp->pr = tmp->qt * a[j].price;
						tmp->prev = l->tail;
						tmp->next = NULL;
						l->tail->next = tmp;
						l->tail = tmp;
						tmp = tmp->next;
						i++;
						count++;
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
