#include <stdio.h>
#include <stdlib.h>
int compare(const int* a,const int* b){
    return (*a-*b);
}
int main() {
    int n,rope[100000],w,max=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&rope[i]);
    }
    qsort(rope,n,sizeof(int),compare);
    for(int i=0;i<n;i++){
        w=(n-i)*rope[i];
        if(w>=max) max=w;
    }
    printf("%d",max);
}