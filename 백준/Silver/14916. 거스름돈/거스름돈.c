#include <stdio.h>

int main() {
    int n,ans=0;
    scanf("%d",&n);
    while(n>0){
        if((n-5)%2==0 || (n-5)%5==0){
            n-=5;
            ans++;
        }
        else if((n-2)%2==0 || (n-2)%5==0){
            n-=2;
            ans++;
        }
        else {
            printf("-1");
            return 0;
        }
    }
    if(n==0) printf("%d",ans);
    else printf("-1");
}