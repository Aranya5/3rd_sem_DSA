#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;
node *top = NULL;

node *push(node *top, int val)
{
    node *new = (node*)malloc(sizeof(node));
    if(new != NULL)
    {
        new->data = val;
        new->link = top;
        top = new;
    }
    else
    {
        printf("MEMORY ALLOCATION FAILED");
        exit(0);
    }
    return top;
}

int pop(node **topptr)
{
    int val;
    node *top = *topptr;
    if(top == NULL)
    {
        printf("Under Flow!\n");
        return -1;
    }
    else
    {
        node *temp= top;
        top = top->link;
        val = temp->data;
        free(temp);
        *topptr = top;
        return val;
    }
}

void peek(node *top)
{
    if(top == NULL)
    {
        printf("Under Flow No Elements to Show!!\n");
    }
    else
    {
        printf("Peek Item is %d\n",top->data);
    }
}

void display(node *top)
{
    if(top == NULL)
    {
        printf("Under Flow No Elements to Show!!\n");
    }
    else
    {
        node *temp = top;
        while(temp != NULL)
        {
            printf("%d",temp->data);
            printf("\n----\n");
            temp = temp->link;
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
            top=push(top,v);
            break;
        case 2:
            v=pop(&top);
            if(v != -1)
            printf("Poped Item: %d\n",v);
            break;
        case 3:
             peek(top);
            break;
        case 4:
            display(top);
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