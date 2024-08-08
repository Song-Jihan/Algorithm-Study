import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
    static final int MAX=101;
    static int[] visit=new int[MAX], ladder=new int[MAX], snake=new int[MAX];
    static Queue<Integer> q=new LinkedList<>();
    static int cnt=1;
    
    static void bfs(int start){
      visit[start]=0;
      q.offer(start);
      while(!q.isEmpty()){
        int now=q.poll();
        if(ladder[now]!=0){
          if(visit[ladder[now]]==0||visit[ladder[now]]>visit[now]){
            visit[ladder[now]]=visit[now];
            q.offer(ladder[now]);
          }
          continue;
        }
        
        if(snake[now]!=0){
          if(visit[snake[now]]==0||visit[snake[now]]>visit[now]){
            visit[snake[now]]=visit[now];
            q.offer(snake[now]);
          }
          continue;
        }
        
        for(int i=1;i<7;i++){
          int next=now+i;
          if(next>100) continue;
          if(visit[next]!=0) {
            if(visit[next]>=visit[now]+1);
            else continue;
          }
          visit[next]=visit[now]+1;
          q.offer(next);
        }
      }
    }
    
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      int ladderamt=Integer.parseInt(st.nextToken());
      int snakeamt=Integer.parseInt(st.nextToken());
      
      for(int i=0;i<ladderamt;i++){
        st=new StringTokenizer(br.readLine());
        int start=Integer.parseInt(st.nextToken());
        int end=Integer.parseInt(st.nextToken());
        ladder[start]=end;
      }
      
      for(int i=0;i<snakeamt;i++){
        st=new StringTokenizer(br.readLine());
        int start=Integer.parseInt(st.nextToken());
        int end=Integer.parseInt(st.nextToken());
        snake[start]=end;
      }
      
      bfs(1);
      
      System.out.println(visit[100]);
  }
}