#include <stdio.h>
#include <stdlib.h>

int visited[101],vertex_amount,edge_amount,cnt=0;

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n;
    struct GraphNode* adj_mat[101];
}GraphType;

void insert_edge(GraphType* g,int u,int v){
    GraphNode* node=(GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_mat[u];
    g->adj_mat[u]=node;
}

void dfs(GraphType* g,int v){
    visited[v]=1;
    for(GraphNode* w=g->adj_mat[v];w;w=w->link){
        if(visited[w->vertex]==0){
            cnt++;
            dfs(g,w->vertex);
        }
    }
}

int main() {
    int v1,v2;
    GraphType* g=(GraphType*)malloc(sizeof(GraphType));
    scanf("%d",&vertex_amount);
    scanf("%d",&edge_amount);
    for(int i=0;i<vertex_amount;i++){
        g->n++;
    }
    for(int i=0;i<edge_amount;i++){
        scanf("%d %d",&v1,&v2);
        insert_edge(g,v1,v2); insert_edge(g,v2,v1);
    }
    dfs(g,1);
    printf("%d",cnt);
}