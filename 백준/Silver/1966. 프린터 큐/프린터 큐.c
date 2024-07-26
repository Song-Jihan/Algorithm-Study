#include <stdio.h>
#include <stdlib.h>

int main(){
    int max=0,p,n,m,num[100],cnt=1;
    int front=0;
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        cnt=1; front=0; max=0;
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++){
            scanf("%d",&num[j]);
        }

        while(1){
            for(int j=0;j<n;j++)
                if(num[j]>max) max=num[j];
            while(num[front]!=max){
                front=(front+1)%n;
            }
            if(front==m) break;

            cnt++;
            num[front]=0;
            front=(front+1)%n;
            max=0;
        }
        printf("%d\n",cnt);
    }
}