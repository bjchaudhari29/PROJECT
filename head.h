#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024

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
	double pr;
	struct a *next, *prev;
}bnode;

typedef struct list{
	bnode *head, *tail;
}list;

void enterdata();
void editdata();
void addproduct();
void printdata();
//void customerentry();
//void print_customer();
void init(list *l);
void print_bill(list *l);
void create_bill(list *l);
//void feed_customerdata(double k);
double total_amt(list *l);
//void payment(double amt);
//double check_balance(char *a);
//void edit_balance(double x, char *b);
