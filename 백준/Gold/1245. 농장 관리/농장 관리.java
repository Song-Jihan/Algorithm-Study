import java.io.*;
import java.util.*;
import java.awt.Point;

public class Main {
    static int[][] arr;
    static boolean[][] visit;
    static int[] dx={-1,0,1,-1,0,1,-1,0,1}, dy={-1,-1,-1,0,0,0,1,1,1};
    static int n,m,max=-1,cnt=0;
    static void dfs(int x,int y,int h){
        visit[y][x]=true;
        for(int i=0;i<9;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=m||ny>=n) continue;
            if(visit[ny][nx] || arr[ny][nx]==0) continue;
            if(arr[y][x]<arr[ny][nx]) continue;
            dfs(nx,ny,h);
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        arr=new int[n][m];
        visit=new boolean[n][m];

        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j]>max) max=arr[i][j];
            }
        }

        for(int h=max;h>0;h--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(arr[i][j]==h && !visit[i][j]){
                        dfs(j,i,h);
                        cnt++;
                    }
                }
            }
            
        }

        System.out.println(cnt);
    }
}
