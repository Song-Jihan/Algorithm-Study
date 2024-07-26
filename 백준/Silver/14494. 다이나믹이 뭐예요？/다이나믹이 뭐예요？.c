#include <stdio.h>

int main() {
    int n,m;
    long long int dp[1001][1001];
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=m;i++){
        dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++){
       for(int j=2;j<=m;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%1000000007;
       }
    }
    
    printf("%lld",dp[n][m]);
}