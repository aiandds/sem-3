#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
}
node;
node *head;

node* create(int d);
void insert_begin(node *p);
void insert_end(node *p);
void insert_after(node *n,int a);
void del_first();
void del_last();
void del_ele(int d);
void display();
void create_in();

int main()
{
    int d,ch,tmp;
    head->next=NULL;
    node *n,*after;
    create_in();
    do
    {
    printf("Enter your choice");
    scanf("%d",&ch);
    printf("\n1.insert in the beginning \n2.insert at last \n3. insert after \n4. delete first \n5. delete last \n6. delete the given element \n7. Display");
    switch(ch)
    {
        case 1:
          printf("Enter the element to insert ");
          scanf("%d",&d);
          n=create(d);
          insert_begin(n);
          break;
        case 2:
          printf("Enter the element to insert ");
          scanf("%d",&d);
          n=create(d);
          insert_end(n);
          break;
        case 3:
          printf("Enter the element to be inserted after the element ");
          scanf("%d",&d);
          printf("Enter the element ");
          scanf("%d",&tmp);
          after -> num =d; 
          insert_after(after,tmp);
          break;
        case 4:
          del_first();
          break;
        case 5:
          del_last();
          break;
        case 6:
          printf("Enter the element to delete ");
          scanf("%d",&d);
          del_ele(d);
          break;
        case 7:
          display();
          break;
        

         
    }
    }
    while(ch<=7);
    
    return 0;
}

void create_in()
{
    node *sec,*first;
    int d;
    printf("Enter the first element");
    scanf("%d",&d);
    first=create(d);
    head->next=first;
    printf("Enter the elements to create a list");
    scanf("%d",&d);
    sec=create(d);
    first->next=sec;
}

node* create(int d)
{
    node *ptr;
    ptr = malloc(sizeof(node));
    ptr->num=d;
    ptr->next=NULL;
    return ptr;
}
void insert_begin(node *p)
{
    if(head->next==NULL)
    {
        head->next=p;
    }
    else
    {
        p->next=head->next;
        head->next=p;
    }
}
void insert_end(node *p)
{
    node *temp;
    temp=head->next;
    if(temp==NULL)
    { 
        head->next=p;
    }
    else
    {
      while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    }
}
void insert_after(node *n,int a)
{
  node *temp;
  temp=head->next;
  while(temp->num!=a)
  {
      temp=temp->next;
  }
  n->next=temp->next;
  temp->next=n;
}
void del_first()
{
    node *first=head->next;
    printf("The first element which is deleted is %d",first->num);
    head->next=head->next->next;
    free(first);
}
void del_last()
{
    node *temp;
    temp=head->next;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void del_ele(int d)
{
   node *temp,*f;
   temp=head->next;
   while(temp->next->num!=d)
   {
       temp=temp->next;
   }
   f=temp->next;
   temp->next=temp->next->next;
   free(f);
}
void display()
{
    node *temp;
    temp=head->next;
    if(temp==NULL)
    printf("The list is empty");
    else
    {
    while(temp!=NULL)
    {
        printf("%d\t",temp->num);
        temp=temp->next;
    }
    }
}
