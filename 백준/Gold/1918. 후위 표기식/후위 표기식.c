#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101
typedef struct{
    char data[MAX];
    int top;
}StackType;

void init_stack(StackType *s){
    s->top=-1;
}

int is_empty(StackType *s){
    return ((s->top)==-1);
}

int is_full(StackType *s){
    return ((s->top)==(MAX-1));
}

void push(StackType *s,char v){
    if(!is_full(s)){
        s->data[++(s->top)]=v;
    }
}

char pop(StackType *s){
    if(!is_empty(s)){
        return s->data[(s->top)--];
    }
}

char peek(StackType *s){
    if(!is_empty(s))
        return (s->data[s->top]);
}

int prec(char ch){
    switch(ch){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case'/': return 2;
    }
    return -1;
}

void infix(char exp[]){
    int len=strlen(exp);
    char top_op;
    char ch;
    StackType s; init_stack(&s);
    
    for(int i=0;i<len;i++){
        ch=exp[i];
        switch(ch){
            case'+':case'-':case'*':case'/':
                while(!is_empty(&s) && prec(peek(&s))>=prec(ch)){
                    printf("%c",pop(&s));
                }
                push(&s,ch);
                break;
            case'(':
                push(&s,ch);
                break;
            case')':
                top_op=pop(&s);
                while(top_op!='('){
                    printf("%c",top_op);
                    top_op=pop(&s);
                }
                break;
            default:
                printf("%c",ch);
                break;
        }
    }
    while(!is_empty(&s)){
        printf("%c",pop(&s));
    }
}

int main(){
    int n,op1,op2;
    char num[101];
    StackType s;
    init_stack(&s);
    scanf("%s",num);
    infix(num);
}