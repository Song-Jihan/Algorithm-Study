import java.util.*;
import java.io.*;

public class Main {
  static int dx[]={0,1,0,-1},
              dy[]={1,0,-1,0};
  static int[][] arr;
  static boolean[][] visit;
  static int max=-1,n,m;
  
  
  static void dfs(int y,int x,int cnt,int sum){
    //4칸 확인 끝
    if(cnt==3){
      if(max<sum) max=sum;
      return;
    }
    
    int nx,ny;
    
    for(int i=0;i<4;i++){
      nx=x+dx[i]; 
      ny=y+dy[i];
      if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
      if(visit[ny][nx]) continue;
      
      if(cnt==1){
        visit[ny][nx]=true;
        dfs(y,x,cnt+1,sum+arr[ny][nx]);
        visit[ny][nx]=false;
      }
      
      visit[ny][nx]=true;
      dfs(ny,nx,cnt+1,sum+arr[ny][nx]);
      visit[ny][nx]=false;
    }
  }
  
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    
    arr=new int[n][m];
    visit=new boolean[n][m];
    
    for(int i=0;i<n;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<m;j++){
        arr[i][j]=Integer.parseInt(st.nextToken());
      }
    }
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          visit[i][j]=true;
          dfs(i,j,0,arr[i][j]);
          visit[i][j]=false;
      }
    }
    
    System.out.print(max);
  }
}