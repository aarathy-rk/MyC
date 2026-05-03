#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void append(struct Node **q,int num)
{
	struct Node *temp,*r;
	if(*q==NULL)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = num;
		temp->link = NULL;		
		*q = temp;
	}
	else
	{
		temp = *q;
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		r = (struct Node*)malloc(sizeof(struct Node));
		r->data = num;
		r->link = NULL;
		temp->link = r;
	}
}

void display(struct Node *q)
{
	printf("Linkedlist is: ");
	while(q!=NULL)
	{
		printf("%d\t",q->data);
		q = q->link;
	}
	printf("\n");
}

void reverse(struct Node **q)
{
	struct Node *current = *q;
	struct Node *prev = NULL;
	struct Node *next;
	
	while(current!=NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	*q = prev;
}

int main()
{
	struct Node *p = NULL;
	append(&p,10);
	append(&p,20);
	append(&p,30);
	append(&p,40);
	display(p);
	reverse(&p);
	display(p);

	return 0;
}
		