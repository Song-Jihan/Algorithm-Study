import java.util.*;
import java.io.*;

public class Main {
  static int N,K;
  static int visit[];
  static Queue<Integer> q=new LinkedList<>();
  
  static void bfs(int n){
    visit[n]=0;
    q.offer(n);
    while(!q.isEmpty()){
      int tmp=q.poll();
      int move=tmp-1;
      if(move>=0){
        if(visit[move]==-1 || visit[move]>visit[tmp]+1){
          visit[move]=visit[tmp]+1;
          q.offer(move);
        }
      }
      move=tmp+1;
      if(move<200000){
        if(visit[move]==-1 || visit[move]>visit[tmp]+1){
          visit[move]=visit[tmp]+1;
          q.offer(move);
        }
      }
      move=tmp*2;
      if(move<200000){
        if(visit[move]==-1 || visit[move]>visit[tmp]){
          visit[move]=visit[tmp];
          q.offer(move);
        }
      }
    }
  }
    public static void main(String[] args) throws IOException{
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st=new StringTokenizer(br.readLine());
      N=Integer.parseInt(st.nextToken());
      K=Integer.parseInt(st.nextToken());
      visit=new int[200001];
      for(int i=0;i<200001;i++){
        visit[i]=-1;
      }
      bfs(N);
      System.out.print(visit[K]);
  }
}