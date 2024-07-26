#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000001

typedef struct{
    int front,rear;
    int data[MAX];
}DequeType;

void init_deque(DequeType* q){
    q->front=q->rear=0;
}

int is_full(DequeType* q){
    return ((q->rear+1)%MAX==q->front);
}

int is_empty(DequeType* q){
    return (q->front==q->rear);
}

void add_rear(DequeType* q, int v){
    if(!is_full(q)){
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=v;
    }
}

int delete_front(DequeType* q){
    if(!is_empty(q)){
        q->front=(q->front+1)%MAX;
        return q->data[q->front];
    }
}

int delete_rear(DequeType* q){
    int prev=q->rear;
    if(!is_empty(q)){
        q->rear=(q->rear-1+MAX)%MAX;
        return q->data[prev];
    }
}

void add_front(DequeType* q, int v){
    if(!is_full(q)){
        q->data[q->front]=v;
        q->front=(q->front-1+MAX)%MAX;
    }
}

int get_front(DequeType* q){
    if(!is_empty(q)){
        return q->data[(q->front+1)%MAX];
    }
}
int get_rear(DequeType* q){
    if(!is_empty(q)){
        return q->data[q->rear];
    }
}

int main(){
    int n,num;
    int input;
    DequeType q;
    init_deque(&q);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&input);
        switch(input){
            case 1:
                scanf("%d\n",&num);
                add_front(&q,num);
                break;
            case 2:
                scanf("%d\n",&num);
                add_rear(&q,num);
                break;
            case 3:
                if(!is_empty(&q)){
                    printf("%d\n",delete_front(&q));
                }
                else printf("-1\n");
                break;
            case 4:
                if(!is_empty(&q)){ 
                    printf("%d\n",delete_rear(&q));
                }
                else printf("-1\n");
                break;
            case 5:
                printf("%d\n",(q.rear-q.front+MAX)%MAX);
                break;
            case 6:
                printf("%d\n",is_empty(&q));
                break;
            case 7:
                if(!is_empty(&q)){
                    printf("%d\n",get_front(&q));
                }
                else printf("-1\n");
                break;
            case 8:
                if(!is_empty(&q)){
                    printf("%d\n",get_rear(&q));
                }
                else printf("-1\n");
                break;
        }
    }
}