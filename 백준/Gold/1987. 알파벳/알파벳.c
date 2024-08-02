#include <stdio.h>
char arr[20][20];
int visit[20][20],alp[26];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,sum,max;

void dfs(int y,int x){
    int nx,ny;
    sum++;
    if(sum>max) 
        max=sum;
    visit[y][x]=1;
    alp[arr[y][x]-'A']=1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
        if(visit[ny][nx]==1 || alp[arr[ny][nx]-'A']==1) continue;
        dfs(ny,nx);
        if(sum>max){
            max=sum;
        }
        sum--;
        alp[arr[ny][nx]-'A']=0;
        visit[ny][nx]=0;
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
        getchar();
    }

    dfs(0,0);
    
    printf("%d",max);
}