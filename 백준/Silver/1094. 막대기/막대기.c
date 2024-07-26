#include <stdio.h>
#include<math.h>
int main() {
    int n,x,cnt=0,num=6,arr[7]={0,},tmp;
    scanf("%d",&n);
    x=n;
    while(x!=0){
        if(x%2==1){
            x-=1;
            arr[0]=1;
        }
        else{
            for(int i=1;i<7;i++){
                tmp=(int)pow(2,i);
                if(x<tmp) break;
                else num=i;
            }
            arr[num]=1;
            if(tmp==x) x-=tmp;
            else x-=tmp/2;
        }
    }
    for(int i=0;i<7;i++){
        if(arr[i]==1) cnt++;
    }
    printf("%d",cnt);
}