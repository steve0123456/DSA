#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* delbeg(struct node *head)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;
    return head;
}

struct node* delend(struct node *head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        head=ptr->next; 
        free(head);
        ptr->next=head;
        
    return head;
    
}

int display(struct node *head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr =head;
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr->next!=head);
    
}
struct node * insertend(struct node *head,int data)
{
     struct node *ptr = (struct node*)malloc(sizeof(struct node));
         struct node *temp;
         ptr->data = data;
             if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;
            head->next=head;
        }  
        return head;
}

struct node * insertbeg(struct node *head,int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    ptr ->data =data;
    
    if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
    else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        return head;
}


int main() {
    int data;
  struct node *head;
  head=(struct node*)malloc(sizeof(struct node));
    head->next=head;
  int ch;
  do{
      printf("enter choice");
      printf("\n1.innsert beg\n 2.insert end\n 3.delete front\n 4.delete end\n display");
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
          head=delbeg(head);
          break;
          case 4:
          head=delend(head);
          break;
          case 5:
          display(head);
          break;
      }
  }while(ch!=6);

    return 0;
}