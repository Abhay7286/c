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

int parenthesisMatch(char* exp){
    struct Stack *sp ;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++){
       if (exp[i]=='(')
       {
        push(sp,'(');
       }
       else if(exp[i]==')'){
        if (isEmpty(sp)){
            return 0;
        }
        pop(sp);
       }

    }
       if (isEmpty(sp)){
        return 1;
       }else{
        return 0;
       }
       
    
}


int main(){
    char * exp = "((8)%(9))";

    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}