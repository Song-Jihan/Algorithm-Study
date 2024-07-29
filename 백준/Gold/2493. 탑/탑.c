#include <stdio.h>
#define MAX 500001
int n,arr[MAX],result[MAX];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }
    arr[0]=100000001;
    for(int i=1;i<=n;i++){
        for(int k=i-1;k>=0;){
            if(arr[i]<arr[k]){
                printf("%d ",k);
                result[i]=k;
                break;
            }
            else{
                k=result[k];
            }
        }
    }
}