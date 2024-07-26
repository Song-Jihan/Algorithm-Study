#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
//https://forward-gradually.tistory.com/51

int arr[1001][1001],WhereIsOne[MAX][2],queue[MAX][2]; //0==y, 1==x
int visit[1001][1001];
int front=0,rear=0,WIO=0,total,chgtom;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int ans,n,m,max=-1;

void enqueue(int i,int v){
    queue[rear][i]=v;
}

int dequeue(int i){
    return queue[front][i];
}

int bfs(int x,int y){
    int tx,ty,nx,ny;
    while(front<rear){
        ty=dequeue(0); tx=dequeue(1);
        front=(front+1)%MAX;
        for(int i=0;i<4;i++){
            nx=tx+dx[i]; ny=ty+dy[i];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(arr[ny][nx]>=1||arr[ny][nx]==-1) continue;
            chgtom++;
            arr[ny][nx]=arr[ty][tx]+1;
            if(max<arr[ny][nx]-1){
                max=arr[ny][nx]-1;
            }
            enqueue(0,ny); enqueue(1,nx);
            rear=(rear+1)%MAX;
        }
    }
    if(total==chgtom) return max;
    return -1;
}

int main() {
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0) total++;
            if(arr[i][j]==1) {
                WhereIsOne[WIO][0]=i;
                WhereIsOne[WIO][1]=j;
                enqueue(0,WhereIsOne[WIO][0]); 
                enqueue(1,WhereIsOne[WIO++][1]);
                rear=(rear+1)%MAX;
            }
        }
    }
    
    for(int i=0;i<WIO;i++){
        ans=bfs(WhereIsOne[i][1],WhereIsOne[i][0]);
    }
    
    if(total!=chgtom){
        printf("-1");
        return 0;
    }
    if(ans==-1) printf("0");
    else printf("%d",ans);
}