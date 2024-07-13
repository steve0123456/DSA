#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 2
struct box{
    int weight,length;
}b[2];

int top=-1;

void display();
void insert();
void peek();
void delete();
 int main(){
    int ch;
    do{
    printf("enter choice");
    printf("\n 1.display \n2.insert \n 3.delete \n 4.peek");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        display();
        break;
        case 2:
        insert();
        break;
        case 3:
        delete();
        break;
    }
    }while(ch!=4);
    return 0;
 }

 
 void insert(){
    
    if(top==size){
        printf("overfflow");
    }else{
        top=top+1;
        printf("enter the weight");
        scanf("%d",&b[top].weight);
        printf("enter the length");
        scanf("%d",&b[top].length);
    }
 }

 void delete(){
    if(top==-1){
        printf("underflow");
    }else{
        
        printf("deleted %d",b[top].weight);
        printf("deleted %d",b[top].length);
        top=top-1;
    }
 }

 void display(){
    for(int i=0;i<=top;i++){
        printf("%d",b[i].weight);
        printf("%d",b[i].length);
    }
 }

 void peek(){
    printf("%d",b[top].weight);
    printf("%d",b[top].length);
 }