#include<stdio.h>
#include<string.h>

int main(){
    int n,k,asw=0,index;
    int alp[26]={0,};
    char word[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",word);
        
        if(strlen(word)==1){
            asw++;
            continue;
        }
        for(int j=0;j<26;j++){
            alp[j]=0;
        }
        
        for(k=1;k<strlen(word);k++){
            index = word[k-1]-'a';
            if(word[k]!=word[k-1]){
                if(alp[index]==0){
                    alp[index]=1;
                }
                else
                    break;
            }
            if(k==strlen(word)-1){
                index=word[k]-'a';
                if(alp[index]==0)
                    alp[index]=1;
                else
                    break;
            }
        }
        if(k==strlen(word)){
            asw++;
        }
    }
    printf("%d",asw);
}