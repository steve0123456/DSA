#include <stdio.h>
#include <ctype.h>
#include<math.h>
#include<string.h>
int stack[40],top=-1;
void sum();
void diff();
void power();
void multi();
void div();

int main() {
    char ch[30];
    int i;
    printf("enter the expression");
    scanf("%[^\n]s",ch);
    for(i=0;ch[i]!='\0';i++){
        if(ch[i]!=""){
            switch(ch[i]){
                case '+':
                sum();
                break;
                case '-':
                diff();
                break;
                case '*':
                multi();
                break;
                case '/':
                div();
                break;
                case '^':
                power();
                break;
                default:
                top++;
                stack[top]=ch[i]-48;
            }
        }
    }
    printf("result %d",stack[top]);
    return 0;
}

void sum(){
    int num1,num2,res;
    num1=stack[top];
    top--;
    num2=stack[top];
    top--;
    res=num2+num1;
    top++;
    stack[top]=res;
}

void diff(){
    int num1,num2,res;
    num1=stack[top];
    top--;
    num2=stack[top];
    top--;
    res=num2-num1;
    top++;
    stack[top]=res;
}

void multi(){
    int num1,num2,res;
    num1=stack[top];
    top--;
    num2=stack[top];
    top--;
    res=num2*num1;
    top++;
    stack[top]=res;
}
void div(){
    int num1,num2,res;
    num1=stack[top];
    top--;
    num2=stack[top];
    top--;
    res=num2/num1;
    top++;
    stack[top]=res;
}
void power(){
    int num1,num2,res;
    num1=stack[top];
    top--;
    num2=stack[top];
    top--;
    res=pow(num2,num1);
    top++;
    stack[top]=res;
}









