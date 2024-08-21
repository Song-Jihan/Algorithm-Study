import java.io.*;
import java.util.*;
import java.awt.Point;

public class Main {
    static int n,m;
    static int[] dx={0,1,0,-1}, dy={-1,0,1,0};
    static int[][] arr;
    static boolean[][] visit;
    static Queue<Point> q=new LinkedList<Point>(); 
    
    static void bfs(int x,int y){
        arr[y][x]=0;
        visit[y][x]=true;;
        q.offer(new Point(x,y));
        while(!q.isEmpty()){
            Point tmp=q.poll();
            for(int i=0;i<4;i++){
                int nx=tmp.x+dx[i];
                int ny=tmp.y+dy[i];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                if(arr[ny][nx]!=1 || visit[ny][nx]) continue;
                arr[ny][nx]=arr[tmp.y][tmp.x]+1;
                visit[ny][nx]=true;
                q.offer(new Point(nx,ny));
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        arr=new int[n][m];
        visit=new boolean[n][m];
        int startx=0, starty=0;
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j]==2){
                    startx=j; 
                    starty=i;
                }
            }
        }
        bfs(startx,starty);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=1) System.out.print(arr[i][j]+" ");
                else {
                    if(!visit[i][j]) 
                        System.out.print("-1 ");
                    else System.out.print(arr[i][j]+" ");
                }
            }
            System.out.println();
        }

    }
}
