#include <stdio.h>

int main() {
    int num,arr[5001];
    scanf("%d",&num);
    for(int i=0;i<=num;i++){
        arr[i]=-1;
    }
    arr[3]=1; arr[5]=1;
    for(int i=6;i<=num;i++){
        if(arr[i-3]!=-1){
            if(arr[i-5]!=-1){
                arr[i]=(arr[i-3]<arr[i-5])?arr[i-3]+1:arr[i-5]+1;
            }
            else 
                arr[i]=arr[i-3]+1;
        }
        else if(arr[i-5]!=-1){
            arr[i]=arr[i-5]+1;
        }
    }
    printf("%d",arr[num]);
}