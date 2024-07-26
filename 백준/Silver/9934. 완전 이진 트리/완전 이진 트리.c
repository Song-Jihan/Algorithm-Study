#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int k,cntrem, cnt=1,num[1024],level,temp[1024],ans[1024][1024],ansi=0;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        cnt*=2;
    }
    cnt-=1;
    for(int i=0;i<cnt;i++){
        scanf("%d",num+i);
    }
    cntrem=cnt;
    level=k;
    while(level>0){
        for(int i=0;i<cnt;i++){
            if(i%2==0){
                ans[level][ansi++]=num[i];
            }
            else{
                temp[i/2]=num[i];
            }
        }
        for(int i=0;i<cnt/2;i++){
            num[i]=temp[i];
        }
        cnt/=2;
        level--;
        ansi=0;
    }
    for(int j=1;j<=k;j++){
        cnt=1;
        for(int i=0;i<j;i++){
            cnt*=2;
        }
        for(int i=0;i<cnt/2;i++){
            printf("%d ",ans[j][i]);
        }
        printf("\n");
    }
}