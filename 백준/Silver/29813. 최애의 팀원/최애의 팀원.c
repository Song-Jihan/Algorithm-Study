#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front,rear,n;
int num[1000];
char name[1000][4];


int main() {
    int move,tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",name[i]);
        getchar();
        scanf("%d",&num[i]);
    }
    front=0; rear=n-1;
    /*
    for(int i=0;i<n;i++){
        tmp=strlen(name[i]);
        for(int j=0;j<tmp;j++) printf("%c",name[i][j]);
        printf(" ");
        printf("%d\n",num[i]);
    }
    */
    int amt=n;
    while(amt!=1){
        move=num[front];
        num[front]=0; amt--;
        for(int i=0;i<move;i++){
            front=(front+1)%n;
            if(num[front]==0) i--;
        }
        num[front]=0; amt--;
        front=(front+1)%n;
        while(num[front]==0) front=(front+1)%n;
    }
    tmp=strlen(name[front]);
    for(int j=0;j<tmp;j++) printf("%c",name[front][j]);
}