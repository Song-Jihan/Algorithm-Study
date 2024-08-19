import java.util.*;
import java.io.*;

public class Main {
  static int[][] arr,dp;
  static boolean[][] visit;
  static int[] dx={0,1,0,-1},dy={-1,0,1,0};
  static int m,n,ans;
  public static int dfs(int x,int y){
    if(x==n-1 && y==m-1){
      return 1;
    }
    if(dp[y][x]!=-1) {
      return dp[y][x];
    }
    dp[y][x]=0;
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(ny<0||nx<0||ny>=m||nx>=n) continue;
      if(arr[ny][nx]<arr[y][x]){
        dp[y][x]+=dfs(nx,ny);
      }
    }
    return dp[y][x];
  }
  
  public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      m=Integer.parseInt(st.nextToken());
      n=Integer.parseInt(st.nextToken());
      arr=new int[m][n];
      visit=new boolean[m][n];
      dp=new int[m][n];
      for(int i=0;i<m;i++){
        st = new StringTokenizer(br.readLine());
        for(int j=0;j<n;j++){
          arr[i][j]=Integer.parseInt(st.nextToken());
          dp[i][j]=-1;
        }
      }
      dfs(0,0);
      System.out.print(dp[0][0]);
  }
}