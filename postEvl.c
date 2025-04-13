#include <stdio.h>
#include <math.h>

int stack[50], top = -1;

void push(int data)
{
    top++;
    stack[top] = data;
}

int pop()
{
    int val;

    val = stack[top];
    top--;
    return val;
}

int main()
{
    char st[30];
    int i, res, op1, op2;
    ;
    printf("Enter the postfix expression");
    scanf("%[^\n]s", st);
    for (i = 0; st[i] != '\0'; i++)
    {
        if (st[i] != ' ')
        {
            switch (st[i])
            {
            case '+':
                op1 = pop();
                op2 = pop();
                res = op2 + op1;
                push(res);
                break;
            case '-':
                op1 = pop();
                op2 = pop();
                res = op2 - op1;
                push(res);
                break;
            case '*':
                op1 = pop();
                op2 = pop();
                res = op2 * op1;
                push(res);
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                res = op2 / op1;
                push(res);
                break;
            case '^':
                op1 = pop();
                op2 = pop();
                res = pow(op2, op1);
                push(res);
                break;
            default:
                top++;
                stack[top] = st[i] - 48;
            }
        }
    }
    printf("\nThe result is = %d", stack[top]);
}
