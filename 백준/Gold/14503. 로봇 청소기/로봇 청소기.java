import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  static int dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
  static int[][] visit,board;
  static int cnt=1,n,m,ny,nx;
  
  static void dfs(int x,int y,int dir){
    if(visit[y][x]==0){
      visit[y][x]=1;
    }
    
    for(int i=0;i<4;i++){
      dir--;
      if(dir==-1) dir=3;
      
      ny=y+dy[dir];
      nx=x+dx[dir];
      if(ny<0||nx<0||nx>m||ny>n) continue;
      if(board[ny][nx]==1 || visit[ny][nx]==1) continue;
      //이동가능한 칸이고 청소 안된 곳이 존재시
      cnt++;
      dfs(nx,ny,dir);
      return;
    }
    
    int d=(dir+2)%4;
    ny=y+dy[d];
    nx=x+dx[d];
    if(!(ny<0||nx<0||nx>m||ny>n) && (board[ny][nx]==0)){
      dfs(nx,ny,dir);
    }
  }
  
  public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st=new StringTokenizer(br.readLine());
    n=Integer.parseInt(st.nextToken());
    m=Integer.parseInt(st.nextToken());
    board=new int[n][m];
    visit=new int[n][m];
    st=new StringTokenizer(br.readLine());
    int starty=Integer.parseInt(st.nextToken());
    int startx=Integer.parseInt(st.nextToken());
    int d=Integer.parseInt(st.nextToken());
    for(int i=0;i<n;i++){
      st=new StringTokenizer(br.readLine());
      for(int j=0;j<m;j++){
        board[i][j]=Integer.parseInt(st.nextToken());
      }
    }
    
    dfs(startx,starty,d);
    
    System.out.print(cnt);
  }
}