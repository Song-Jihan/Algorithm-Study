#include<stdio.h>

int main(){
    int x,y,n,arr[1000][1000]={0,},cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        for(int k=0;k<10;k++){
            for(int j=0;j<10;j++)
                arr[x+k][y+j]=1;
        }
    }
    for(int k=0;k<1000;k++){
            for(int j=0;j<1000;j++)
                if(arr[k][j]==1) cnt++;
    }
    printf("%d",cnt);
}