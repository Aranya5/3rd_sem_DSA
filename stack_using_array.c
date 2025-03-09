#include <stdio.h>
#include <stdlib.h>
#define N 10
int top = -1;
int stack[N];

void push(int data)
{
    if(top == N-1)
    {
        printf("Stack Overflow!");
        
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    int val;
    if(top == -1)
    {
        printf("Under Flow!\n");
        return -1;
        
    }
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}

void peek()
{
    if(top == -1)
    {
        printf("Under flow!\n");
    }
    else
    {
        printf("Peek is %d\n",stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Under Flow Nothing to Display");
    }
    else
    {
        int i;
        for(i=top; i>=0; i--)
        {
            printf("%d",stack[i]);
            printf("\n----\n");
        }
    }
}
int main()
{
    int ch,v;
    while(1)
    {
         printf("Enter Choice: 1.PUSH 2.POP 3.PEEK 4.DISPLAY 5.EXIT\n");
         scanf("%d", &ch);
        switch(ch)
        {
         case 1:
            printf("Enter value to push:");
            scanf("%d",&v);
            push(v);
            break;
        case 2:
            v=pop();
            if(v != -1)
            printf("Poped Item: %d\n",v);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice!!");
            break;
        }
    }
    return 0;
}