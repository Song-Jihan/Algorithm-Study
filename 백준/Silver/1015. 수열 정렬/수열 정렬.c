#include <stdio.h>
#include <string.h>


int main() {
    int n,cnt=0,stair=1,A[1000],P[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    while(cnt!=n){
        for(int i=0;i<n;i++){
            if(A[i]==stair) P[i]=cnt++;
        }
        stair++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",P[i]);
    }
}