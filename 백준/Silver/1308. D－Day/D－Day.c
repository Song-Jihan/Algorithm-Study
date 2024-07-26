#include<stdio.h>
int y[2],m[2],d[2];

int yoon(int y){
    if(y%4==0 && y%100!=0 || y%400==0)
        return 1;
    else return 0;
}

int main(){
    int cnt=0;
    for(int i=0;i<2;i++)
        scanf("%d %d %d",&y[i],&m[i],&d[i]);
    
    if(y[1]-y[0]==1000 && m[0]<=m[1] && d[0]<=d[1]
    || y[1]-y[0]>1000){
        printf("gg");
        return 0;    
    }
    while(1){
        d[0]++;
        if(m[0]<=7){
            if(m[0]%2==1 && d[0]==32
            || m[0]%2==0 && d[0]==31
            || m[0]==2 && yoon(y[0])==1 && d[0]==30
            || m[0]==2 && yoon(y[0])==0 && d[0]==29){
                m[0]++;
                d[0]=1;
            }
        }
        else{
            if(m[0]%2==0 && d[0]==32
            || m[0]%2==1 && d[0]==31){
                m[0]++;
                d[0]=1;
            }
        }
        if(m[0]==13){
            y[0]++;
            m[0]=1;
        }
        if(y[0]==y[1] && m[0]==m[1] && d[0]==d[1]){
            break;
        }
        cnt++;
    }
    printf("D-%d",cnt+1);
}