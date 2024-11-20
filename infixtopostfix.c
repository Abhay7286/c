#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp)
{
    return sp->top == -1;
}

int isFull(struct stack *sp)
{
    return sp->top == sp->size - 1;
}

void push(struct stack *sp, char val)
{
    if (isFull(sp)){
        printf("stack overflow!\n");
        return;
    }
    sp->arr[++(sp->top)] = val;
}

char pop(struct stack *sp)
{
    if (isEmpty(sp)){
        printf("stack underflow!\n");
        return '\0';
    }
    return sp->arr[(sp->top)--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}

int main()
{
    char* infix = "p-q-r/q";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}