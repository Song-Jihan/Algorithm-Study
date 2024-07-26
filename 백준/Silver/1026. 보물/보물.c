#include <stdio.h>
#include <stdlib.h>
int compare(const int* a,const int *b){
    return (*a-*b);
}
int revcompare(const int* a,const int *b){
    return (*b-*a);
}
int main() {
    int n,a[50],b[50],sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    
    qsort(&a[0],n,sizeof(int),compare);
    qsort(&b[0],n,sizeof(int),revcompare);
    
    for(int i=0;i<n;i++){
        sum+=(a[i]*b[i]);
    }
    printf("%d",sum);
}