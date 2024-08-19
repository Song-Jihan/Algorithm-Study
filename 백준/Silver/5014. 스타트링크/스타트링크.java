import java.util.*;
import java.io.*;

public class Main {
  static int F, S, G, U, D;
  static int visit[];
  static Queue<Integer> q=new LinkedList<>();
  static void bfs(int n){
    visit[n]=1;
    q.offer(n);
    while(!q.isEmpty()){
      int tmp=q.poll();
      //System.out.println(tmp);
      if(!(tmp+U>F || visit[tmp+U]!=0)){
        visit[tmp+U]=visit[tmp]+1;
        q.offer(tmp+U);
        
      }
      if(!(tmp-D<=0 || visit[tmp-D]!=0)){
        visit[tmp-D]=visit[tmp]+1;
        q.offer(tmp-D);
      }
    }
  }
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      F=Integer.parseInt(st.nextToken());
      visit=new int[F+1];
      S=Integer.parseInt(st.nextToken());
      G=Integer.parseInt(st.nextToken());
      U=Integer.parseInt(st.nextToken());
      D=Integer.parseInt(st.nextToken());
      bfs(S);
      if(visit[G]==0) System.out.print("use the stairs");
      else System.out.print(visit[G]-1);
  }
}