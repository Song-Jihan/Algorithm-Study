#include <stdio.h>
#define MAX 50
int n,max=-1,cnt;
char a[MAX][MAX];
int visit[MAX][MAX];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
        getchar();
    }
    for(int man=0;man<n;man++){
        for(int mf=0;mf<n;mf++){
            if(a[man][mf]=='Y' && man!=mf && !visit[man][mf]){
                visit[man][mf]=1;
                cnt++;
                for(int k=0;k<n;k++){
                    if(a[mf][k]=='Y' && k!=man && k!=mf && !visit[man][k]){
                        if(a[man][k]!='Y') {
                            visit[man][k]=1;
                            cnt++;
                        }
                    }
                }
            }
        }
        if(max<cnt) max=cnt;
        cnt=0;
    }
    printf("%d",max);
}