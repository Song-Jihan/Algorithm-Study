#include<stdio.h>
#include<stdlib.h>
int n,m,cabbage;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int visit[50][50], field[50][50];
int worm=0;

void dfs(int x,int y){
    int nx,ny;
    visit[y][x]=1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=m || ny>=n || nx<0 || ny<0) continue;
        else{
            if(field[ny][nx]==1 && visit[ny][nx]==0) 
                dfs(nx,ny);
        }
    }
}

int main(){
    int t,x,y;
    scanf("%d",&t);
    for(int o=0;o<t;o++){
        scanf("%d %d %d",&m,&n,&cabbage);
        for(int i=0;i<cabbage;i++){
            scanf("%d %d",&x,&y);
            field[y][x]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(field[i][j]==1 && visit[i][j]==0){
                    dfs(j,i);
                    worm++;
                }
            }
        }
        printf("%d\n",worm);
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                field[i][j]=0;
                visit[i][j]=0;
            }
        }
        worm=0;
    }
}