import java.util.*;
import java.io.*;

public class Main {
    static int[][] arr;
    public static void main(String[] args) throws Exception{
        int n,m,bigsquare=-1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int min=(n<m)?n:m;
        arr=new int[n][m];
        
        for(int y=0;y<n;y++){
            String str = br.readLine();
            for(int x=0;x<m;x++){
                arr[y][x]=str.charAt(x) - '0';
            }
        }
        
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                for(int i=0;i<min;i++){
                    if(y+i >= n || x+i>=m) continue;
                    if(arr[y+i][x]==arr[y][x] &&
                       arr[y][x+i]==arr[y][x] &&
                       arr[y+i][x+i]==arr[y][x]){
                        if(bigsquare<(i+1)*(i+1)){
                            bigsquare=(i+1)*(i+1);
                        }
                       }
                }
            }
        }
        System.out.print(bigsquare);
  }
}