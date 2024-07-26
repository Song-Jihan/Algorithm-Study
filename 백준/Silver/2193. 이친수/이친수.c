#include<stdio.h>

long long fib(int n){
    if(n==1) return 1;
    if(n==0) return 0;
    
    long long pp=0;
    long long p=1;
    long long result=0;
    for(int i=2;i<=n;i++){
        result=p+pp;
        pp=p;
        p=result;
    }
    return result;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lld",fib(n));
}