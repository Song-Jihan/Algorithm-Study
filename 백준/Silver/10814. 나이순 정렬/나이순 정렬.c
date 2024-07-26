#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int age;
    int index;
    char name[101];
}account;

int compare(const void* first,const void* second){
    account*a=(account*)first;
    account*b=(account*)second;
    if(a->age < b->age){
        return -1;
    }
    else if(a->age > b->age){
            return 1;
    }
    else{
        if(a->index<b->index)
            return -1;
        else
            return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    account* list = (account*)malloc(n*sizeof(account));
    for(int i=0;i<n;i++){
        scanf("%d %s",&list[i].age,list[i].name);
        list[i].index=i;
    }
    
    qsort(list,n,sizeof(list[0]),compare);
    
    for(int i=0;i<n;i++){
        printf("%d %s\n",list[i].age,list[i].name);
    }
    return 0;
}