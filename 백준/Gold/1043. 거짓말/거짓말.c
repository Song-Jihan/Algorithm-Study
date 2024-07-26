#include <stdio.h>
#include <stdlib.h>
int know[51],input[51][51],attend[51];
int cnt=0;
int vertex_amt, edge_amt, num, who, HowManyKnow;

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

GraphNode* adj[51];

void insert_edge(int u, int v) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=adj[u];
    adj[u]=node;
}

void find_know(int n){
    for(GraphNode* w=adj[n];w;w=w->link){
        if(know[w->vertex]==2){
            know[n]=2;
            for(GraphNode* p=adj[n];p;p=p->link){
                know[p->vertex]=2;
            }
            break;
        }
    }
    if(know[n]!=2){
        know[n]=1;
        for(GraphNode* w=adj[n];w;w=w->link) 
            know[w->vertex]=1;
    }
}

int main() {
    
    scanf("%d %d",&vertex_amt,&edge_amt);
    scanf("%d",&HowManyKnow);
    for(int o=0;o<HowManyKnow;o++){
        scanf("%d",&num);
        know[num]=2;
    }
    
    for(int i=0;i<edge_amt;i++){
        scanf("%d",&attend[i]);
        for(int j=0;j<attend[i];j++){
            scanf("%d",&input[i][j]);
        }
        for(int j=0;j<attend[i]-1;j++){
            insert_edge(input[i][j],input[i][j+1]);
            insert_edge(input[i][j+1],input[i][j]);
        }
    }

    for(int j=1;j<=vertex_amt;j++){
        for(int i=1;i<=vertex_amt;i++){
            find_know(i);
            //printf("%d know:%d\n",i,know[i]);
        }
    }
    
    for(int i=0;i<edge_amt;i++){
        for(int j=0;j<attend[i];j++){
            //printf("%d %d\n",input[i][j],know[input[i][j]]);
            if(know[input[i][j]]==2) break;
            if(j==attend[i]-1) {
                //printf("attend: %d\n",i);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    
    return 0;
}