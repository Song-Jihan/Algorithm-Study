#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Listnode{
    char data;
    struct Listnode *left;
    struct Listnode *right;
}Listnode;

Listnode *head,*tail,*p;

void init(void){
    head=(Listnode*)malloc(sizeof(Listnode));
    tail=(Listnode*)malloc(sizeof(Listnode));
    head->left=head; head->right=tail;
    tail->left=head; tail->right=tail;
    p=tail;
}


void insert(char x){
    Listnode *n=(Listnode*)malloc(sizeof(Listnode));
    n->data=x;
    n->right=p;
    n->left=p->left;
    p->left->right=n;
    p->left=n;
}

void Bdelete(void){
    Listnode* removed=(Listnode*)malloc(sizeof(Listnode));
    if(p!=head->right){
        removed=p->left;
        removed->left->right=p;
        p->left=removed->left;
        free(removed);
    }
}

void Lgoleft(){
    if(p!=head->right) p=p->left;
}

void Dgoright(){
    if(p!=tail) p=p->right;
}

void print_list(){
    p = head->right;
    while(p!=tail){
        printf("%c",p->data);
        p=p->right;
    }
    printf("\n");
}

void del_all(){
    Listnode* d = head->right;
    while(d!=tail){
        Listnode* t=d;
        d=d->right;
        free(t);
    }
}

int main(){
    char input[1000000]; char c;
    int n,len;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        init();
        scanf("%s",input);
        getchar();
        len=strlen(input);
        for(int j=0;j<len;j++){
            c=input[j];
            switch(c){
                case'<':
                    Lgoleft();
                    break;
                case'>':
                    Dgoright();
                    break;
                case'-':
                    Bdelete();
                    break;
                default:
                    insert(c);
                    break;
            }
        }
        print_list();
        del_all();
    }
    free(head); free(tail);
}