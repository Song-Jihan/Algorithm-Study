import java.util.*;
import java.io.*;
import java.awt.Point;

public class Main {
  static final int MAX=20;
  static int[][] ocean=new int[MAX][MAX],visit=new int[MAX][MAX];
  static int n,time,sharksize=2,sharkstack,fish_amt;
  static int[] dx={0,1,0,-1},dy={1,0,-1,0};
  static Point tmp=new Point(),sharkPos,target=new Point(MAX,MAX);
  
  static void FindFish(int y,int x){
    int nx=0,ny=0;
    Queue<Point> q=new LinkedList<Point>();
    visit[y][x]=1;
    q.offer(new Point(x,y));
    while(!q.isEmpty()){
      tmp=q.poll();
      for(int i=0;i<4;i++){
        nx=tmp.x+dx[i];
        ny=tmp.y+dy[i];
        if(ny<0 || nx<0 || nx>=n || ny>=n) continue;
        if(visit[ny][nx]!=0 || sharksize<ocean[ny][nx]) continue;
        visit[ny][nx]=visit[tmp.y][tmp.x]+1;
        if(sharksize>ocean[ny][nx] && ocean[ny][nx]!=0){
          if(target.x==MAX && target.y==MAX){
            target.y=ny;
            target.x=nx;
          }
          else if(target.y>ny || (target.y==ny && target.x>nx)){
            if(visit[target.y][target.x]>=visit[ny][nx]){
              target.y=ny;
              target.x=nx;
            }
          }
        }
        q.offer(new Point(nx,ny));
      }
    }
    if(target.x==MAX && target.y==MAX) return;
    time+=(visit[target.y][target.x]-1);
  }
  
  static void moveshark(){
    ocean[sharkPos.y][sharkPos.x]=0;
    sharkPos.x=target.x;
    sharkPos.y=target.y;
    ocean[sharkPos.y][sharkPos.x]=9;
    sharkstack++;
    if(sharkstack==sharksize){
      sharkstack=0;
      sharksize++;
    }
  }
  
  public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    n=Integer.parseInt(br.readLine());
    for(int i=0;i<n;i++){
      StringTokenizer st=new StringTokenizer(br.readLine());
      for(int j=0;j<n;j++){
        ocean[i][j]=Integer.parseInt(st.nextToken());
        if(ocean[i][j]==9){
          sharkPos=new Point(j,i);
        }
        if(ocean[i][j]!=9 && ocean[i][j]!=0){
          fish_amt++;
        }
      }
    }
    
    for(int i=0;i<fish_amt;i++){
      FindFish(sharkPos.y,sharkPos.x);
      if(target.x==MAX&&target.y==MAX){
        break;
      }
      moveshark();
      
      for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
          visit[a][b]=0;
        }
      }
      target.x=MAX; 
      target.y=MAX;
      
    }
    
    if(time==0) System.out.print("0");
    else System.out.print(time);
  }
}