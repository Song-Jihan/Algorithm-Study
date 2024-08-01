#include <stdio.h>
#define MAX 10001
int n,m,max=-1,zerocnt,viruscnt,safezone;
int arr[8][8],test[8][8];
int front, rear;

typedef struct{
    int x,y;
}QueueType;

QueueType q[MAX];

void enqueue(int x,int y){
    rear=(rear+1)%MAX;
    q[rear].x=x;
    q[rear].y=y;
}

QueueType dequeue(){
    front=(front+1)%MAX;
    return q[front];
}

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

void bfs(){
    int nx,ny;
    QueueType tmp;
    while(front<rear){
        tmp=dequeue();
        for(int i=0;i<4;i++){
            nx=tmp.x+dx[i];
            ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=m||ny>=n) continue;
            if(test[ny][nx]!=0) continue;
            test[ny][nx]=test[tmp.y][tmp.x]+1;
            enqueue(nx,ny);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(test[i][j]>2){
                test[i][j]=0;
            }
            else if(test[i][j]==0){
                safezone++;
            }
        }
    }
    if(safezone>max){
        max=safezone;
    }
    front=0; rear=viruscnt; safezone=0;
}

void make_wall(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(test[i][j]==0){
                test[i][j]=1;
                make_wall(cnt+1);
                test[i][j]=0;
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            test[i][j]=arr[i][j];
            if(arr[i][j]==2) {
                viruscnt++;
                enqueue(j,i);
            }
        }
    }
    make_wall(0);
    printf("%d",max);
}