#include <stdio.h>
#include <stdlib.h>
#define MAX 65000001

typedef struct{
    int t, h;
}time_min;

int main() {
    time_min Tmin;
    Tmin.t=MAX; Tmin.h=-1;
    int n,m,B,arr[500][500];
    int dis=0,t=0,max=-1,min=MAX;
    scanf("%d %d %d",&n,&m,&B);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf("%d",&arr[a][b]);
            if(arr[a][b]<min) min=arr[a][b];
            else if(arr[a][b]>max) max=arr[a][b];
        }
    }
    int tmp=B;
    for(int i=min;i<=max;i++){
        
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                dis=arr[a][b]-i;
                if(dis>0) {
                    t+=(dis*2);
                    B+=dis;
                }
                else if(dis<0) {
                    t-=dis;
                    B+=dis;
                }
            }
        }
        if(B>=0){
            if(Tmin.t>t){
                Tmin.t=t;
                Tmin.h=i;
            }
            else if(Tmin.t==t){
                if(Tmin.h<i)
                    Tmin.h=i;
            }
        }
        B=tmp;
        t=0;
    }
    printf("%d %d",Tmin.t,Tmin.h);
}