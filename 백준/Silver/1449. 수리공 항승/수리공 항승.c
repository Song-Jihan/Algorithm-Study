#include <stdio.h>
#include <stdlib.h>
int arr[2001],bit[2001];
int n,l,num,cnt=0,cm=0;

int compare(const int* a,const int* b){
    if(*a>*b) return 1;
    else if(*a==*b) return 0;
    else return -1;
}

int main(){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(arr[0]),compare);
    for(int i=0;i<n;i++){
        if(bit[arr[i]]==0){
            for(int j=0;j<l;j++)
                bit[arr[i]+j]=1;
            cnt++;
        }
    }
    printf("%d",cnt);
}