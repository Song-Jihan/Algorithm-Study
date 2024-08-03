#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1,TmpSum=1,sum;
int stack[50];
char arr[50],tmp;

void push(int v){
    stack[++top]=v;
}

int pop(){
    return stack[top--];
}

int main() {
    scanf("%s",arr);
    getchar();
    int len=strlen(arr);
    for(int i=0;i<len;i++){
        if(arr[i]=='('||arr[i]=='['){
            if(arr[i]=='(') {
                push(arr[i]);
                TmpSum*=2;
            }
            else if(arr[i]=='[') {
                push(arr[i]);
                TmpSum*=3;
            }
        }
        else{
            tmp=pop();
            if(arr[i]==')'&&tmp=='('){
                if(arr[i-1]==')' || arr[i-1]==']') TmpSum/=2;
                else{
                    sum+=TmpSum;
                    TmpSum/=2;
                }
            }
            else if(arr[i]==']'&&tmp=='['){
                if(arr[i-1]==')' || arr[i-1]==']') TmpSum/=3;
                else{
                    sum+=TmpSum;
                    TmpSum/=3;
                }
            }
            else{
                printf("0");
                return 0;
            }
        }
    }
    if(top==-1) printf("%d",sum);
    else printf("0");
}