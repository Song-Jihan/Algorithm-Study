import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.awt.Point;
import java.lang.Math;


public class Main {
  static int[] dx={0,1,0,-1},dy={-1,0,1,0};
  static int[][] arr;
  static boolean[][] visit,change,lockTB;
  static Queue<Point> q=new LinkedList<>();
  static int n,L,R,ans;
  
  static void bfs(int x,int y){
    int sum=0,union=1;
    sum+=arr[y][x];
    q.offer(new Point(x,y));
    while(!q.isEmpty()){
      Point tmp=q.poll();
      visit[tmp.y][tmp.x]=true;
      for(int i=0;i<4;i++){
        int nx=tmp.x+dx[i];
        int ny=tmp.y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(visit[ny][nx]==true) continue;
        if(change[ny][nx]==true) continue;
        int ab=Math.abs(arr[tmp.y][tmp.x]-arr[ny][nx]);
        if(ab<L || ab>R) continue;
        visit[ny][nx]=true;
        change[y][x]=true;
        change[ny][nx]=true;
        sum+=arr[ny][nx];
        union++;
        q.offer(new Point(nx,ny));
      }
    }
    if(union!=1){
      int avg=sum/union;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(visit[i][j]==true){
            arr[i][j]=avg;
            visit[i][j]=false;
          }
          if(lockTB[i][j]==true){
            lockTB[i][j]=false;
          }
        }
      }
    }
    else visit[y][x]=false;
  }
  
  
  public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st=new StringTokenizer(br.readLine());
    n=Integer.parseInt(st.nextToken());
    arr=new int[n][n];
    visit=new boolean[n][n];
    change=new boolean[n][n];
    lockTB=new boolean[n][n];
    L=Integer.parseInt(st.nextToken());
    R=Integer.parseInt(st.nextToken());
    for(int i=0;i<n;i++){
      st=new StringTokenizer(br.readLine());
      for(int j=0;j<n;j++){
        arr[i][j]=Integer.parseInt(st.nextToken());
      }
    }
    
    boolean keepgo=true;
    while(keepgo){
      keepgo=false;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(change[i][j]==false){
            bfs(j,i);
          }
        }
      }
      
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(change[i][j]==true){
            change[i][j]=false;
            keepgo=true;
          }
        }
      }
      
      if(keepgo==true) ans++;
      
    }
    
    System.out.print(ans);
  }
}