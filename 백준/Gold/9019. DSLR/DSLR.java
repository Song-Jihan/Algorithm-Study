import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  static final int MAX=10000;
  //static Queue<Integer> q=new LinkedList<>();
  
  public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int T=Integer.parseInt(br.readLine());
    for(int t=0;t<T;t++){
      StringTokenizer st=new StringTokenizer(br.readLine());
      int A=Integer.parseInt(st.nextToken());
      int B=Integer.parseInt(st.nextToken());
      boolean[] visit=new boolean[MAX];
      String[] ans=new String[MAX];
      Queue<Integer> q=new LinkedList<>();
      
      q.add(A);
      visit[A]=true;
      Arrays.fill(ans,"");
        
      while(!q.isEmpty()&&!visit[B]){
        int n=q.poll();
        
        int D=(n*2)%MAX;
        int S=(n==0)?9999:n-1;
        int L=(n%1000)*10+n/1000;
        int R=(n%10)*1000+n/10;
        
        if(!visit[D]){
          q.add(D);
          visit[D]=true;
          ans[D]=ans[n]+"D";
        }
        
        if(!visit[S]){
          q.add(S);
          visit[S]=true;
          ans[S]=ans[n]+"S";
        }
        
        if(!visit[L]){
          q.add(L);
          visit[L]=true;
          ans[L]=ans[n]+"L";
        }
        
        if(!visit[R]){
          q.add(R);
          visit[R]=true;
          ans[R]=ans[n]+"R";
        }
      }
      System.out.println(ans[B]);
    }
  }
}