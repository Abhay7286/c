#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct Stack *sp){
    return sp->top == -1;
}

int isFull(struct Stack *sp){
    return sp->top == sp->size-1;
}

void push(struct Stack *sp,char val){
    if (isFull(sp))
    {
        printf("stack overflow");
    }else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}

char pop(struct Stack *sp){
    if (isEmpty(sp))
    {
        printf("stack underflow");
    }else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int match(char a,char b){
    if (a=='(' && b==')')
    {
        return 1;
    }
    if (a=='{' && b=='}')
    {
        return 1;
    }
    if (a=='[' && b==']')
    {
        return 1;
    }
    return 0;
    
}

int parenthesisMatch(char* exp){
    char popped_item;
    struct Stack *sp ;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++){
       if (exp[i]=='('|| exp[i]=='{'|| exp[i]=='[')
       {
        push(sp,exp[i]);
       }
       else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']'){
        if (isEmpty(sp)){
            return 0;
        }
        popped_item = pop(sp);
        if (!match(popped_item,exp[i]))
        {
            return 0;
        }
        
       }

    }
       if (isEmpty(sp)){
        return 1;
       }else{
        return 0;
       }
       
    
}


int main(){
    char * exp = "([(8)%(9)]])";

    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}