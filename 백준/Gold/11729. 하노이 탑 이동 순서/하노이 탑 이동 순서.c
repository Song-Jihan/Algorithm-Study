#include <stdio.h>
int cnt;
void hanoicnt(int n,int from,int tmp,int to){
    cnt++;
    if(n!=1){
        hanoicnt(n-1,from,to,tmp);
        hanoicnt(n-1,tmp,from,to);
    }
}

void hanoi(int n,int from,int tmp,int to){
    if(n==1) printf("%d %d\n",from,to);
    else{
        hanoi(n-1,from,to,tmp);
        printf("%d %d\n",from,to);
        hanoi(n-1,tmp,from,to);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    hanoicnt(n,1,2,3);
    printf("%d\n",cnt);
    hanoi(n,1,2,3);
}