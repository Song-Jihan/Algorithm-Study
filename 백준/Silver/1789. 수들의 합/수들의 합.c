#include <stdio.h>

int main() {
    long long int s,sum=0,cnt=0;
    scanf("%lld",&s);
    while(1){
        if(sum==s){
            printf("%lld",cnt);
            return 0;
        }
        else if(sum>s){
            cnt--;
            sum-=(sum-s);
        }
        else{
            cnt++;
            sum+=cnt;
        }
    }
}