#include <stdio.h>
int arr[100][100],visit[100][100];
int n;
void dfs(int y,int x,int now){
    for(int i=0;i<n;i++){
        if(arr[x][i]==1 && !visit[now][i]){
            visit[now][i]=1;
            dfs(x,i,now);
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && !visit[i][j]){
                dfs(i,j,i);
                visit[i][j]=1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
}