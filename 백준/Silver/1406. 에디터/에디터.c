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
    //printf("%c",p->data);
    while(p!=tail){
        printf("%c",p->data);
        p=p->right;
    }
}

void del_all(){
    Listnode* d = head->right;
    while(d!=tail){
        Listnode* t=d;
        d=d->right;
        free(t);
    }
    free(head); 
    free(tail);
}

int main(){
    char input[100000]; char order,k;
    int n;
    init();
    scanf("%s",input);
    int len=strlen(input);
    for(int i=0;i<len;i++){
        insert(input[i]);
    }
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&order);
        switch(order){
            case'L':
                Lgoleft();
                getchar();
                break;
            case'D':
                Dgoright();
                getchar();
                break;
            case'B':
                Bdelete();
                getchar();            
                break;
            case'P':
                getchar();
                scanf("%c",&k);
                insert(k);
                getchar();
                break;
        }
    }
    print_list();
    del_all();
}