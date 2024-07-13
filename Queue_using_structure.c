#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 5
struct bill{
    int id,qty;
    int price;
    char name[20];
}b[size];
int front=-1,rear=-1;

int isFull(){
    if (rear == size-1)
    return 1;
    else
    return 0;
}

int isEmpty(){
    if(front==-1 || front>rear)
    return 1;
    else
    return 0;
}

void enqueue(struct bill item)
{
    if (isFull())
    printf(“\nQueue Full”);
    else{
        if(front == -1)
        front = 0;
        b[++rear]= item;
    }
}

void dequeue(){
    if (isEmpty())
    printf("\nQueue Empty");
    else{
        printf("Deleting %s,%d, %d, %d",
        b[front].name,b[front].id,b[front].qty,b[front].price);
        front++;
    }
}

int display(){
    int i;
    printf("name  id  qty  price \n");
    for(i=front;i<=rear;i++){
        printf(" %s  %d  %d  %d\n.",b[i].name,b[i].id,b[i].qty,b[i].price );
    }
}

int total(){
    int total=0;
    printf("Final Bill:");
    printf("\nId\tName\tQty\tPrice\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t%s\t%d\t%d\n",b[i].id,b[i].name,b[i].qty,b[i].price);
    }
    for(int i=front;i<=rear;i++){
        total=total+b[i].qty*b[i].price;
    }
    printf("\nTotal bill =%d",total);
    exit(0);
}

int main(){
    int choice;
    struct bill item;
    while(1){
        printf("\n\nMenu:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Total\n");
        printf("Enter your choice::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter bill details(Name,ID,Qty,Price):\n");
            scanf("%s %d %d %d",item.name,&item.id,&item.qty,&item.price);
            enqueue(item);
            break;
        case 2:
        dequeue(item);
        break;
        case 3:
        display();
        break;
        case 4:
        total();
        break;
        default: printf("INVALID OPTION!!Enter choice from the menu.");
        }
    }
}