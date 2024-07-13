#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * insertbeg(struct node *head,int data)
{
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=data;
   ptr->next=head;
   head=ptr;
    return head;
}

struct node * insertend(struct node *head,int data)
{
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    struct node * p=head;
    ptr->data =data;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

struct node * insertafter(struct node *head,int data,int element)
{
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *temp=head;
    for(int i=0;i<element;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}

struct node * deletebeg(struct node * head)
{
    struct node *ptr =head;
    head=head->next;
    free(ptr);
    return head;
}

struct node * deleteend(struct node * head){
    struct node *ptr,*ptr1;
    ptr=head;
    
    while(ptr->next!=NULL){
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=NULL;
    free(ptr);
    return head;
}

void display(struct node *head){
    struct node * ptr=(struct node* )malloc(sizeof(struct node));
    ptr=head;
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}


int main() {
   struct node *head;
   head=(struct node*)malloc(sizeof(struct node));
   head->next=NULL;
   int ch,data,element;
   do{
       printf("enter choice");
       printf("\n 1.insert at beg\n 2. insert end\n 3.insert after node\n 4.display \n5.delete beg");
       scanf("%d",&ch);
       switch(ch){
           case 1:
           printf("enter value");
           scanf("%d",&data);
           head=insertbeg(head,data);
           break;
           case 2:
           printf("enter value");
           scanf("%d",&data);
           head=insertend(head,data);
           break;
           case 3:
           printf("enter value");
           scanf("%d",&data);
           printf("enter node ");
           scanf("%d",&element);
           head=insertafter(head,data,element);
           break;
           case 4:
           display(head);
           break;
           case 5:
           head=deletebeg(head);
           break;
           case 6:
           head=deleteend(head);
           break;
       }
   }while  (ch!=8 );

    return 0;
}