#include<stdio.h>
#include<math.h>
#define min(x,y) x<=y?x:y

#define INF 100000000
int n,m,k,broken[10]={0,};
int ans;

int solve(int x){
    int tmp=x;
    int len=0; //the number which how many times press the button
    int bool=1;
    
    if(x==0){
        if(broken[0]==1) return INF;
        else len=1;
    }
    
    while(tmp>0){
        if(broken[tmp%10]==1){
            bool=0;
            break;
        }
        else{
            tmp/=10;
            len++;
        }
    }
    
    if(bool==1){
        return abs(x-n)+len;
    }
    else return INF;
}

int main(){
    
    scanf("%d %d",&n,&m);
    ans=abs(n-100);
    
    for(int i=0;i<m;i++){
        scanf("%d",&k);
        broken[k]=1;
    }
    for(int i=0;i<1000000;i++){
        ans=min(ans,solve(i));
    }
    printf("%d",ans);
}