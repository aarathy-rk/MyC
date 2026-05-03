#include<stdio.h>
#include<malloc.h>

struct node
{
int data;
struct node *link;//a pointer variable "link" pointing to another node in linked list
};

void append(struct node **,int);
void display(struct node *);
void addatbeg(struct node **,int);
void addafter(struct node *,int,int);
int count(struct node *);
void del(struct node **,int);

void main()
{
struct node *p;//pointer to a node in linked list
p=NULL;//node is empty
append(&p,5);//pointer to first node is passed
append(&p,10);
append(&p,15);
display(p);//first node is passed
addatbeg(&p,0);
display(p);
addafter(p,2,20);
display(p);
printf("No of elements in linked list = %d\n",count(p));
del(&p,20);
printf("No of elements in linked list = %d\n",count(p));
display(p);
}

void append(struct node **q,int num)
{
struct node *temp,*r;
if(*q==NULL)//address of node pointing to is NULL..i.e.node is empty
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
temp->link=NULL;
*q=temp;//first node always assigned to q
}
else
{
temp = *q;//first node assigned to temp
while(temp->link!=NULL)
{
temp=temp->link;//to reach last node
}
r=(struct node*)malloc(sizeof(struct node));
r->data=num;
r->link=NULL;//assign added node as last node
temp->link=r;//make 2nd last node pointing to last node
}
}

void display(struct node *q)
{
//struct node *temp;
//temp = q;
//while(temp!=NULL)//node empty or node address NULL
//{
//printf("%d\t",temp->data);
//temp=temp->link;
//}
//printf("\n");

while(q!=NULL)//node empty or node address NULL
{
printf("%d\t",q->data);
q=q->link;
}
printf("\n");
}

void addatbeg(struct node **q,int num)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
temp->link=*q;
*q=temp;
}

void addafter(struct node *q,int loc,int num)
{
struct node *temp,*r;
temp=q;
for(int i=0;i<loc;i++)//inserting after loc position starting from 0
{
temp=temp->link;
}
r=(struct node*)malloc(sizeof(struct node));
r->data=num;
r->link=temp->link;
temp->link=r;
}

int count(struct node *q)
{
int c=0;
while(q!=NULL)
{
c++;
q=q->link;
}
return c;
}

void del(struct node **q,int num)
{
struct node *old,*temp;
temp=*q;
while(temp!=NULL)
{
if(temp->data==num)
{
if(temp==*q)
{
*q=temp->link;
}
else
old->link=temp->link;
free(temp);
}
else
{
old=temp;
temp=temp->link;
}
}
}






