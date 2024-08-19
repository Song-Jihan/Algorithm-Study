import java.util.*;
import java.io.*;

public class Main {
  static int vertex_amt,edge_amt,sum=0,min=Integer.MAX_VALUE;
  static Queue<Integer> q=new LinkedList<>();
  static int[] visit=new int[101];
  static boolean[][] graph;
  static void bfs(int n){
    q.offer(n);
    visit[n]=0;
    while(!q.isEmpty()){
      int tmp=q.poll();
      for(int i=1;i<vertex_amt+1;i++){
        if(visit[i]!=-1 || !graph[tmp][i]) continue;
        q.offer(i);
        visit[i]=visit[tmp]+1;
      }
    }
    
    for(int i=1;i<vertex_amt+1;i++){
      sum+=visit[i];
      visit[i]=-1;
    }
    //System.out.println("sum:"+sum+" n:"+n);
  }
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      vertex_amt=Integer.parseInt(st.nextToken());
      graph=new boolean[vertex_amt+1][vertex_amt+1];
      for(int i=0;i<vertex_amt+1;i++){
        visit[i]=-1;
      }
      edge_amt=Integer.parseInt(st.nextToken());
      for(int i=0;i<edge_amt;i++){
        st=new StringTokenizer(br.readLine());
        int n1=Integer.parseInt(st.nextToken());
        int n2=Integer.parseInt(st.nextToken());
        graph[n1][n2]=true; 
        graph[n2][n1]=true;
      }
      int minnum=0;
      for(int i=1;i<vertex_amt+1;i++){
        bfs(i);
        if(min>sum){
          min=sum;
          minnum=i;
        }
        sum=0;
      }
      System.out.println(minnum);
  }
}