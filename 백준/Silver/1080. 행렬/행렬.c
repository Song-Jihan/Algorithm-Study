#include <stdio.h>

int main() {
    int arr[50][50],brr[50][50];
    int n,m,cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&brr[i][j]);
        }
    }
    
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(arr[i][j]!=brr[i][j]){
                for(int k=0;k<3;k++){
                    for(int p=0;p<3;p++){
                        if(arr[i+k][j+p]==1) arr[i+k][j+p]=0;
                        else arr[i+k][j+p]=1;
                    }
                }
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=brr[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    
    printf("%d",cnt);
}