#include <stdio.h>

int main() {
    int front=0,ans=0,what=0;
    int want[50],arr[50];
    int n,m,rcnt=0,lcnt=0,tmp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) arr[i]=i+1;
    for(int i=0;i<m;i++) scanf("%d",want+i);
    
    for(int i=0;i<m;i++){
            tmp=front;
            while(arr[front]!=want[i]){
                front=(front-1+n)%n;
                while(arr[front]==0){
                    front=(front+n-1)%n;
                }
                lcnt++;
            }
            //printf("%d ",lcnt);
            
            front=tmp;
            while(arr[front]!=want[i]){
                front=(front+1)%n;
                while(arr[front]==0){
                    front=(front+1)%n;
                }
                rcnt++;
            }
            //printf("%d\n",rcnt);
        
            if(rcnt<=lcnt) ans+=rcnt;
            else ans+=lcnt;
        
            arr[front]=0;
            front=(front+1)%n;
            for(int i=0;i<n;i++) {
                if(arr[i]!=0){
                    break;
                }
                else{
                    if(i==(n-1)){
                        printf("%d",ans);
                        return 0;
                    }
                }
            }
            while(arr[front]==0) {
                front=(front+1)%n;
            }
            rcnt=0; lcnt=0;
            //printf("ans: %d\n",ans);
    }
    
    printf("%d",ans);
}