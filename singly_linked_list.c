#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node * link;
} node;

node *insert_at_beginning(node *head, int val)
{
    node *new = (node*)malloc(sizeof(node));
    if(new != NULL)
    {
        new->data = val;
        new->link = NULL;
        if(head == NULL)
        {
            head = new;
        }
        else
        {
            new->link = head;
            head = new;
        }
    }
    else
    {
        printf("MEMORY ALLOCATION FAILED");
    }
    return head;
}

node *inser_at_end(node *head, int val)
{
    node *new = (node*)malloc(sizeof(node));
    if(new != NULL)
    {
        new->data = val;
        new->link = NULL;
        if(head == NULL)
        {
            head=new;
        }
        else
        {
            node *cur = head;
            while(cur->link != NULL)
            {
                cur = cur->link;
            }
            cur->link = new;
        }
    }
    else
    {
        printf("MEMORY ALLOCATION FAILED");
        exit(0);
    }
    return head;
}

node *insert_at_position(node *head, int val, int pos)
{
    node *cur = head;
    int count = 0;
    if(pos == 1)
    {
        head = insert_at_beginning(head,val);
    }
    while(cur != NULL)
    {
        count++;
        if(pos == count+1)
        {
            node *new = (node*)malloc(sizeof(node));
            if(new != NULL)
            {
                new->data = val;
                new->link = cur->link;
                cur->link = new;
            }
            else
            {
                 printf("MEMORY ALLOCATION FAILED");
                 exit(0);                     
            }
        }
        cur = cur->link;
    }
    if(pos <= 0 || pos > count+1)
    {
        printf("Invalid Position");
    }
    return head;
}

int delete_at_beginning(node **hptr)
{
    int val;
    node *head = *hptr;
    if(head == NULL)
    {
        printf("Empty list nothing to delete");
        return INT_MIN;
    }
    else
    {
        node *temp = head;
        head = head->link;
        val = temp->data;
        free(temp);
        *hptr = head;
        return val;
    }
}

int delete_at_end(node **hptr)
{
    int val;
    node *cur = *hptr, *prev = NULL;
    if(cur == NULL)
    {
        printf("Empty list nothing to delete");
        return INT_MIN;
    }
    else
    {
        while(cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
        }

        if(prev != NULL)
        {
            prev->link = NULL;
        }
        else
        {
            *hptr = NULL;
        }

        val = cur->data;
        free(cur);
        return val;
    }
}

int delete_at_position(node **hptr, int pos)
{
    int count=0,val;
    node *head = *hptr, *cur = head, *prev = NULL;
    if(cur == NULL)
    {
        printf("Empty list nothing to delete");
        return INT_MIN;
    }
    if(pos == 1)
    {
        val = delete_at_beginning(&head);
        *hptr = head;
        return val; 
    }
    while(cur != NULL)
    {
        count++;
        if(pos == count)
        {
            if(prev != NULL)
            {
                prev->link = cur->link;
            }
            val = cur->data;
            free(cur);
            return val;           
        }
        prev = cur;
        cur = cur->link;
    }
    if(pos >= count || pos <= 0)
    {
        printf("Invalid Position");
        return INT_MIN;
    }
return val;
}

int delete_by_value(node **hptr,int key)
{
    node *head = *hptr, *cur = head, *prev = NULL;
    int flag = 0,val;
    if(cur == NULL)
    {
         printf("Empty list");
         return INT_MIN;
    }
    while(cur!=NULL)
    {
        if(cur->data == key)
        {
            flag = 1;
            break;
        }
        prev = cur;
        cur = cur->link;
    }
    if(flag == 0)
    {
        printf("Element not found");
        return INT_MIN;
    }
    if(prev == NULL)
    {
        val = delete_at_beginning(&hptr);
    }
    else
    {
        prev->link = cur->link;
        val = cur->data;
        free(cur);
    }
    return val;
}

node *reverse_linked_list(node *head)
{
    node *cur = head,*prev = NULL,*next;
    if(head == NULL)
    {
        printf("Empty List");
        return head;
    }
    next = cur->link;
    while(next != NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = next;
        next = next->link;
    }
    head = cur;
    cur->link = prev;
    return head;
}

void display(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
}
int main()
{
    int v,r;
    node *head = NULL;
   head = inser_at_end(head, 20);
   head =  inser_at_end(head, 30);
    head =   inser_at_end(head, 40);
    head =  insert_at_beginning(head,90);
   head = insert_at_position(head, 70 , 2);
    display(head);
    printf("\n");
    v=delete_by_value(&head,40);
   display(head);
    printf("\n");
    r=delete_at_position(&head,1);
    display(head);
    printf("\n");

    head = reverse_linked_list(head);
    printf("\n");
     display(head);
    return 0;
}