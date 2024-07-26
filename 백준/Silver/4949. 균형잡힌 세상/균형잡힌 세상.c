#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100001

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top=-1;
}

int is_empty(StackType *s){
    return (s->top==-1);
}

int is_full(StackType *s){
    return (s->top==(MAX_STACK_SIZE-1));
}

void push(StackType *s,element v){
    s->data[++(s->top)]=v;
}

element pop(StackType *s){
    return s->data[s->top--];
}

element peek(StackType *s){
    return s->data[s->top];
}


int solve(char exp[]){
    if(exp[0]=='.') return 1;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);
    for(int i=0;i<len;i++){
        ch=exp[i];
        switch(ch){
            case '(': case '[':
                push(&s,ch);
                break;
            case ')':
                if(peek(&s)!='(' || is_empty(&s)) return 0;
                else pop(&s);
                break;
            case']':
                if(peek(&s)!='[' || is_empty(&s)) return 0;
                else pop(&s);
                break;
            case'.':
                return is_empty(&s);
        }
    }
    return 0;
}

int main(){    
    int asw[100001]={0,},i=0,len;
    char sentence[1000001];
    while(1){
        gets(sentence);
        if(sentence[0]=='.') break;
        if(solve(sentence)) asw[i++]=1;
        else {
            asw[i++]=0;
        }
          
    }
    
    for(int k=0;k<i;k++){
        asw[k]==1?printf("yes\n"):printf("no\n");
    }
}