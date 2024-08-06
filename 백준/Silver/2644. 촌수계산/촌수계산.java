import java.util.*;
import java.io.*;

public class Main {
  static final int MAX=101;
  static boolean[][] graph=new boolean[MAX][MAX];
  static int[] visit=new int[MAX];
  static int fp,sp,vertex_amount;
  
  static void dfs(int f,int cnt){
    visit[f]=++cnt;
    for(int i=1;i<vertex_amount+1;i++){
      if(graph[f][i]&&visit[i]==0){
        dfs(i,cnt);
      }
    }
  }
  
  public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    vertex_amount=Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    fp=Integer.parseInt(st.nextToken());
    sp=Integer.parseInt(st.nextToken());
    int k=Integer.parseInt(br.readLine());
    for(int i=0;i<k;i++){
      st = new StringTokenizer(br.readLine());
      int n1=Integer.parseInt(st.nextToken());
      int n2=Integer.parseInt(st.nextToken());
      graph[n1][n2]=true;
      graph[n2][n1]=true;
    }
    
    dfs(fp,0);
    System.out.print(visit[sp]-1);
  }
}