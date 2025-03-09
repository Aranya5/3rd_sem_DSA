#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push values onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Function to pop values from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate the postfix expression
int evaluatePostfix(char *exp) {
    char *token = strtok(exp, " ");
    while (token != NULL) {
        // If the token is a number, push it onto the stack
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            // Operator found, pop two values from stack
            int val2 = pop();
            int val1 = pop();

            switch (token[0]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();  // Final result is on top of the stack
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression (use spaces to separate numbers and operators): ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}