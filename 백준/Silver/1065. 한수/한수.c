#include<stdio.h>

int main(){
    int n;
    int cnt=0;
    int hdr,ten,one;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i<100){
            cnt++;
        }
        else{
            hdr=i/100;
            ten=(i%100)/10;
            one=i%10;
            if((hdr-ten)==(ten-one)){
                cnt++;
            }
            else{
                continue;
            }
        }
    }
    printf("%d",cnt);
}