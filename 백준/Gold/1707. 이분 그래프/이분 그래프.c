#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//https://www.acmicpc.net/board/view/77198

int v,e,n1,n2,k;
int visit[20001],color[20001];

typedef struct GraphNode{
    int vertix;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    struct GraphNode* adj[20001]; 
}GraphType;

void insert_node(GraphType* g,int u,int v){
    GraphNode* node=(GraphNode*)malloc(sizeof(GraphNode));
    node->vertix=v;
    node->link=g->adj[u];
    g->adj[u]=node;
}

void colordfs(GraphType* g,int v,int c){
    color[v]=c;
    for(GraphNode* w=g->adj[v];w;w=w->link){
        if(color[w->vertix]==0){
            colordfs(g,w->vertix,3-c);
        }
    }
}

int dfs(GraphType* g, int vl) {
    for(int j=1;j<=vl;j++){
        for (GraphNode* w = g->adj[j]; w; w = w->link){
            if(color[j]==color[w->vertix]){
                return 0;
            }
        }
    }
    return 1;
}


int main() {
    int n1,n2,ans=1;
    scanf("%d",&k);
    GraphType* g=(GraphType*)malloc(sizeof(GraphType));
    for(int i=0;i<k;i++){
        scanf("%d %d",&v,&e);
        
        for(int j=1;j<=v;j++) {
            g->adj[j]=NULL;
            visit[j]=0;
            color[j]=0;
        }
        
        for(int j=0;j<e;j++){
            scanf("%d %d",&n1,&n2);
            insert_node(g,n1,n2);
            insert_node(g,n2,n1);
        }
        
        for(int j=1;j<=v;j++){
            if(color[j]==0) colordfs(g,j,1);
        }
        
        if(dfs(g,v)) printf("YES\n");
        else printf("NO\n");
    }
}