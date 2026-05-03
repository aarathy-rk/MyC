#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void append(struct Node **q,int num)
{
	struct Node *temp,*r;
	if(*q==NULL)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = num;
		temp->prev = NULL;
		temp->next = NULL;		
		*q = temp;
	}
	else
	{
		temp = *q;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		r = (struct Node*)malloc(sizeof(struct Node));
		r->data = num;
		r->prev = temp;
		r->next = NULL;
		temp->next = r;
	}
}

void appendatbeg(struct Node **q, int num)
{
	struct Node *temp,*r;
	if(*q==NULL)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = num;
		temp->prev = NULL;
		temp->next = NULL;		
		*q = temp;
	}
	else
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		r->data = num;
		r->prev = NULL;
		r->next = *q;
		(*q)->prev = r;
		*q = r;
	}

}

void appendbtw(struct Node *q, int loc, int num)
{
	struct Node *temp,*r;
	temp = q;
	for(int i=0;i<loc;i++)
	{
		temp = temp->next;
	}
	r = (struct Node*)malloc(sizeof(struct Node));
	r->data = num;
	r->prev = temp;
	r->next = temp->next;
	temp =  temp->next;
	temp->prev->next = r;
	if(temp!=NULL)
		temp->prev = r;	
}

void display(struct Node *q)
{
	printf("Linkedlist is: ");
	while(q!=NULL)
	{
		printf("%d\t",q->data);
		q = q->next;
	}
	printf("\n");
}

void removedup(struct Node *q)
{
	struct Node *temp, *dup, *last;
	temp = q;
	while(temp!=NULL)
	{
		last = temp;
		dup = temp->next;
		while(dup!=NULL)
		{
			if(dup->data == temp->data)
			{
				last->next = dup->next;
				dup->next->prev = last;
				free(dup);
				dup = last->next;
			}
			else
			{
				last = dup;
				dup = dup->next;
			}
		}
		temp = temp->next;
	}
}

void reverse(struct Node **q)
{
	struct Node *temp = NULL;
	struct Node *current = *q;

	while(current!=NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	
	if(temp!=NULL)
		*q = temp->prev;
}

int main()
{
	struct Node *p = NULL;
	append(&p,10);
	append(&p,20);
	append(&p,30);
	appendatbeg(&p,5);
	appendbtw(p,1,15);
	appendbtw(p,3,20);
	display(p);
	removedup(p);
	display(p);
	reverse(&p);
	display(p);
	return 0;
}
		