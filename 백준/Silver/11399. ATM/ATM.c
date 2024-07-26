#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


typedef struct{
    int heap[MAX];
    int heap_size;
}HeapType;

HeapType heap;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size=0;
}

void insert_max_heap(HeapType *h,int item){
    int i;
    i=++(h->heap_size);
    while((i!=1)&&(item>h->heap[i/2])){
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i]=item;
}

int delete_max_heap(HeapType* h){
    int parent,child;
    int item, temp;

    item=h->heap[1];
    temp=h->heap[(h->heap_size)--];
    parent=1; child=2;
    while(child<=h->heap_size){
        if(h->heap[child]<h->heap[child+1] && child<h->heap_size)
            child++;
        if(temp>=h->heap[child]) break;
        h->heap[parent]=h->heap[child];
        parent=child;
        child*=2;
    }
    h->heap[parent]=temp;
    return item;
}

void heap_sort(int a[],int n){
    int i;
    HeapType* h;
    h=create();
    init(h);
    for(i=0;i<n;i++){
        insert_max_heap(h,a[i]);
    }
    for(i=(n-1);i>-1;i--){
        a[i]=delete_max_heap(h);
    }
    free(h);
}

int main(void) {
    int n;
    long long int sum=0; 
    int list[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",list+i);
    }
    heap_sort(list, n);
    for (int i=0; i<n; i++)
        for(int j=0;j<=i;j++)
            sum+=list[j];
    printf("%lld",sum);
    return 0;
}