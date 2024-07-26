#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int graph[MAX][MAX],visit[MAX];
int n1,n2,N,M,p;
int sum,ans;

typedef struct Graphnode{
    int vertex;
    struct Graphnode* link;
}Graphnode;

Graphnode* mat[MAX];

void insert_node(int u,int v){
    Graphnode* node = (Graphnode*)malloc(sizeof(Graphnode));
    node->vertex=v;
    node->link=mat[u];
    mat[u]=node;
}

void dfs(int start,int end){
    if(start==end && !visit[start]){
        printf("%d\n",sum);
    }
    
    visit[start]=1;
    //start와 end 노드가 서로 인접돼있는지 확인
    for(Graphnode* w=mat[start];w;w=w->link){
        if(w->vertex==end){
            sum+=graph[start][w->vertex];
            dfs(w->vertex,end);
            sum-=graph[start][w->vertex];
        }
    }
    
    //아니라면 그냥 찾기
    for(Graphnode* w=mat[start];w;w=w->link){
        if(!visit[w->vertex]){
            sum+=graph[start][w->vertex];
            dfs(w->vertex,end);
            sum-=graph[start][w->vertex];
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d",&n1,&n2,&p);
        graph[n1][n2]=p; graph[n2][n1]=p;
        insert_node(n1,n2); insert_node(n2,n1);
    }
    
    for(int i=0;i<M;i++){
        scanf("%d %d",&n1,&n2);
        dfs(n1,n2);
        
        for(int k=0;k<N+1;k++){
            visit[k]=0;
        }
        sum=0;
    }
}