import java.util.*;
import java.io.*;

public class Main {
  static final int MAX = 500;
  static int x1,y1,x2,y2;
  static int m,n,k;
  static boolean visit[][]=new boolean[MAX][MAX];
  static int arr[][]=new int[MAX][MAX];
  static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},ans[]=new int[MAX];
  
  static void dfs(int y,int x,int idx){
    ans[idx]++;
    visit[y][x]=true;
    int nx,ny;
    for(int i=0;i<4;i++){
      nx=x+dx[i]; 
      ny=y+dy[i];
      if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
      if(visit[ny][nx]==true || arr[ny][nx]==1) continue;
      dfs(ny,nx,idx);
    }
  }
  
  public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      m=Integer.parseInt(st.nextToken());
      n=Integer.parseInt(st.nextToken());
      k=Integer.parseInt(st.nextToken());
      
      
      for(int i=0;i<k;i++){
        st=new StringTokenizer(br.readLine());
        x1=Integer.parseInt(st.nextToken());
        y1=Integer.parseInt(st.nextToken());
        x2=Integer.parseInt(st.nextToken());
        y2=Integer.parseInt(st.nextToken());
        for(int y=y1;y<y2;y++){
          for(int x=x1;x<x2;x++){
            arr[y][x]=1;
          }
        }
      }
      
      int cnt=0,idx=0;
      
      for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
          if(visit[y][x]==false && arr[y][x]==0){
            cnt++;
            dfs(y,x,idx);
            idx++;
          }
        }
      }
      Arrays.sort(ans,0,cnt);
      System.out.println(cnt);
      for(int i=0;i<cnt;i++){
        System.out.print(ans[i]+" ");
      }
      
  }
} 