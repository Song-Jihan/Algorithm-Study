#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
int n;

typedef struct {
    int front, rear;
    int data[MAX];
} DequeType;

void init_deque(DequeType* q) {
    q->front = q->rear = 0;
}

int is_full(DequeType* q) {
    return ((q->rear + 1) % MAX == q->front);
}

int is_empty(DequeType* q) {
    return (q->front == q->rear);
}

void add_front(DequeType* q, int v) {
    if (!is_full(q)) {
        q->data[q->front] = v;
        q->front = (q->front - 1 + MAX) % MAX;
    }
}

void add_rear(DequeType* q, int v) {
    if (!is_full(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = v;
    }
}

int delete_front(DequeType* q) {
    if (!is_empty(q)) {
        q->front = (q->front + 1) % MAX;
        return q->data[q->front];
    }
}

int delete_rear(DequeType* q){
    if(!is_empty(q)){
        int n=q->data[q->rear];
        q->rear=(q->rear-1+MAX)%MAX;
        return n;
    }
    return -1;
}

void print_deque(DequeType* q){
    while(!is_empty(q)){
        printf("%c",delete_front(q));
    }
}

int main() {
    int arr[MAX];
    int n,num,k=0;
    char ch;
    DequeType q;
    init_deque(&q);
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(num!=3)arr[k++]=num;
        switch(num){
            case 1:
                scanf(" %c",&ch);
                add_rear(&q,ch);
                break;
            case 2:
                scanf(" %c",&ch);
                add_front(&q,ch);
                break;
            case 3:
                if(!is_empty(&q)){
                    num=arr[--k];
                    if(num==1) delete_rear(&q);
                    else delete_front(&q);
                }
                break;
        }
    }
    if(!is_empty(&q)) print_deque(&q);
    else printf("0");
}
