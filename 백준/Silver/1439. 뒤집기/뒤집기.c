#include <stdio.h>
#include <string.h>

int main() {
    char num[1000001];
    int zero=0,one=0,l,start,asw;
    scanf("%s",num);
    getchar();
    if(num[0]=='0') start=0;
    else start=1;
    l=strlen(num);
    for(int i=0;i<l;i++){
        if(num[i]=='0' && start==0){
            start=1;
            zero++;
        }
        else if (num[i]=='1' && start==1){
            start=0;
            one++;
        }
    }
    asw=(zero>one)?one:zero;
    printf("%d",asw);
}