#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500001

typedef struct{
    int front,rear;
    int data[MAX];
}QueueType;

void init_queue(QueueType* q){
    q->front=q->rear=0;
}

int is_full(QueueType* q){
    return ((q->rear+1)%MAX==q->front);
}

int is_empty(QueueType* q){
    return (q->front==q->rear);
}

void enqueue(QueueType* q, int v){
    if(!is_full(q)){
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=v;
    }
}

int dequeue(QueueType* q){
    if(!is_empty(q)){
        q->front=(q->front+1)%MAX;
        return q->data[q->front];
    }
}

int solve(QueueType *q){
    for(;!(q->front == q->rear-1);){
        dequeue(q);
        if(q->front == q->rear-1) return dequeue(q);
        enqueue(q, dequeue(q));
    }
}

int main(){
    QueueType q;
    init_queue(&q);
    int n,num;
    scanf("%d",&n);
    if(n==1){
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        enqueue(&q, i);
    }
    printf("%d",solve(&q));
}