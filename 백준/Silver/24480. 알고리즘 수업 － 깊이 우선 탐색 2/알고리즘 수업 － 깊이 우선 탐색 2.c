#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode{
    int vertix;
    struct GraphNode* link;
}GraphNode;

typedef struct pair{
    int s; int e;
}pair;

GraphNode* adj[1000001];
int visited[1000001];

void insert_edge(int u,int v){
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertix=v;
    node->link=adj[u];
    adj[u]=node;
}

int compare(pair* a,pair* b){
    if(a->s > b->s) return 1;
    else if(a->s < b->s) return -1;
    else{
        if(a->e > b->e) return 1;
        else if(a->e < b->e) return -1;
    }
}

int vi=0;

void dfs(int v){
    visited[v]=++vi;
    for(GraphNode* w=adj[v];w;w=w->link){
        if(visited[w->vertix]==0) 
            dfs(w->vertix);
    }
}

int main() {
    int vertix_amount, edge_amount, start;
    int u,v;
    scanf("%d %d %d",&vertix_amount,&edge_amount,&start);
    pair* link=(pair*)malloc((2*edge_amount+1)*sizeof(pair));
    
    for(int i=0;i<edge_amount;i++){
        scanf("%d %d",&link[i].s,&link[i].e);
        link[i+edge_amount].s=link[i].e;
        link[i+edge_amount].e=link[i].s;
    }

    qsort(link,edge_amount*2,sizeof(link[0]),compare);

    for(int i=0;i<2*edge_amount;i++){
        insert_edge(link[i].s,link[i].e);
    }
    
    dfs(start);

    for(int i=1;i<=vertix_amount;i++){
        printf("%d\n",visited[i]);
    }
}