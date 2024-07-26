#include <stdio.h>

int main() {
    int cnt=0,tx,ty,x,y,sup=0;
    char arr[11][11];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%c",&arr[i][j]);
        }
        getchar();
    }
    for(y=0;y<10;y++){
        for(x=0;x<10;x++){
            if(x<=5){
                cnt=0;
                for(int i=0;i<5;i++){
                    if(arr[y][x+i]=='O') break;
                    else if(arr[y][x+i]=='X') cnt++;
                    if(i==4&&cnt>=4){
                        printf("1");
                        return 0;
                    }
                }
            }
            if(y<=5){
                cnt=0;
                for(int i=0;i<5;i++){
                    if(arr[y+i][x]=='O') break;
                    else if(arr[y+i][x]=='X') cnt++;
                    if(i==4&&cnt>=4){
                        printf("1");
                        return 0;
                    }
                }
            }
            cnt=0;
            for(int i=0;i<5;i++){
                if(y+i>=10 || x+i>=10) break;
                if(arr[y+i][x+i]=='O') break;
                else if(arr[y+i][x+i]=='X') cnt++;
                if(i==4&&cnt>=4){
                    printf("1");
                    return 0;
                }
            }
            cnt=0;
            for(int i=0;i<5;i++){
                if(y-i<0 || x+i>=10) break;
                if(arr[y-i][x+i]=='O') break;
                else if(arr[y-i][x+i]=='X') cnt++;
                if(i==4&&cnt>=4){
                    printf("1");
                    return 0;
                }
            }
        }
    }
    printf("0");
}